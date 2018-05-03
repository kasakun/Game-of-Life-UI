/*
 * Created by Zeyu Chen on 4/23/18.
 * version@1.0.0
 */

#if defined(NANOGUI_GLAD)
#if defined(NANOGUI_SHARED) && !defined(GLAD_GLAPI_EXPORT)
#define GLAD_GLAPI_EXPORT
#endif
#include <glad/glad.h>
#else
#if defined(__APPLE__)
#define GLFW_INCLUDE_GLCOREARB
#else
#define GL_GLEXT_PROTOTYPES
#endif
#endif

#include <fstream>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <sys/stat.h>
#include <GLFW/glfw3.h>
#include <nanogui/nanogui.h>
#include <future>

#include "Shader.h"
#include "Game.h"
#include "PatternLib.h"
#include "Brush.h"

#define LTBOUND ((GLfloat)-1.0)
#define DWBOUND ((GLfloat)-1.0)
using namespace nanogui;
//////////////////////////////////////////////////////////////////////////////////////
// Author: Zeyu Chen (chenzy@gatech.edu)                                                                                 //
// Game of Life, or so called cellular automata, is a simple ruled based math game. //
// The interface supports a pattern library, a brush library and random mode.       //
// Also, a strong file system is implemented which user can simply add pattern file //
// to the Lib dir or brush dir to add new element without modifying any code.       //
// The file format so far supported is LIFE 1.05. New format will be supported in   //
// future.                                                                          //
//                                                                                  //
// The default window size is 1000x1000, game borad is 200x200.                     //
//                                                                                  //
//                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//controller
bool start = false;
bool draw = false;
int rightClick;
unsigned int FPS = 24;  // MAX FPS

// stat
std::string fps;
std::string cur;
unsigned long liveCell;
unsigned long generation;

// Pattern, brush library
enum patterns {
    pattern1 = 0,
    pattern2 = 1,
    pattern3 = 2,
    pattern4 = 3
};
patterns patternEnum = pattern1;
std::vector<std::string> patternsList;
enum drawBrush {
    brush1 = 0,
    brush2 = 1,
    brush3 = 2
};
drawBrush drawEnum = brush1;
std::vector<std::string> drawList;
// w, h represent the number of cells in row and col; width, height is for window
static int w = 200, h = 200;
static int width, height;
Game g(w, h);
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
Screen *screen = nullptr;
void glfwInitWrapper() {
    glfwInit();
    glfwSetTime(0);

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    glfwWindowHint(GLFW_SAMPLES, 0);
    glfwWindowHint(GLFW_RED_BITS, 8);
    glfwWindowHint(GLFW_GREEN_BITS, 8);
    glfwWindowHint(GLFW_BLUE_BITS, 8);
    glfwWindowHint(GLFW_ALPHA_BITS, 8);
    glfwWindowHint(GLFW_STENCIL_BITS, 8);
    glfwWindowHint(GLFW_DEPTH_BITS, 24);
    glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);

}
void guiMaker(FormHelper *gui, std::string name) {
    ref<Window> nanoguiWindow = gui->addWindow(Eigen::Vector2i(10, 10), name);
    gui->setFixedSize(Eigen::Vector2i(100, 35));
    gui->setGroupFontSize(24);
    gui->setLabelFontSize(20);
    gui->setWidgetFontSize(18);
    gui->addGroup("Controller");
    gui->addButton("  Continue  ", []() {
        std::cout << "Game start." << std::endl;start = true;draw = false;
    })->setTooltip("Start the Game!");
    gui->addButton("  Pause  ", []() {
        std::cout << "Game paused." << std::endl;start = false;draw = false;
    })->setTooltip("Pause the Game!");
    gui->addGroup("Random");
    gui->addButton("  Start  ", []() { start = false;draw = false;glfwSetTime(0.0);generation = 0;
        g.randomPattern();
        start = true;
        std::cout << "Random Mode start." << std::endl;
    })->setTooltip("Start a Random Game");
    gui->addGroup("Game Library");
    gui->addVariable("Pattern", patternEnum, true)
            ->setItems(patternsList);
    gui->addButton("  Start  ", []() { start = false;draw = false;glfwSetTime(0.0);generation = 0;
        PatternLib lib(w, h);
        lib.initPatternList();
        bool** pattern = new bool*[w];
        if (lib.getPattern(patternsList[patternEnum], pattern))
            g.readLibrary(pattern);
        start = true;
        std::cout << patternEnum << std::endl;
        std::cout << "Library start." << std::endl;
    })->setTooltip("Start the Game");
    gui->addGroup("Draw");
    gui->addButton("  Clear  ", []() { g.init();draw = true;start = false;glfwSetTime(0.0);generation = 0; });
    gui->addVariable("Brush", drawEnum, true)
            ->setItems(drawList);
    gui->addGroup("Stats");
    gui->addVariable("FPS", fps)->setEditable(false);
    gui->addVariable("Time", cur)->setEditable(false);
    gui->addVariable("Live Cells", liveCell)->setEditable(false);
    gui->addVariable("Generation", generation)->setEditable(false);
    screen->setVisible(true);
    screen->performLayout();


}
void glfwCallBackSet(GLFWwindow* window) {
    glfwSetCursorPosCallback(window, [](GLFWwindow *, double x, double y) {
        screen->cursorPosCallbackEvent(x, y);
    });

    glfwSetMouseButtonCallback(window, [](GLFWwindow *, int button, int action, int modifiers) {
        screen->mouseButtonCallbackEvent(button, action, modifiers);
        if (button)
            rightClick = 1;
    });

    glfwSetKeyCallback(window, [](GLFWwindow *, int key, int scancode, int action, int mods) {
        screen->keyCallbackEvent(key, scancode, action, mods);
    });

    glfwSetCharCallback(window, [](GLFWwindow *, unsigned int codepoint) {
        screen->charCallbackEvent(codepoint);
    });

    glfwSetDropCallback(window, [](GLFWwindow *, int count, const char **filenames) {
        screen->dropCallbackEvent(count, filenames);
    });

    glfwSetScrollCallback(window, [](GLFWwindow *, double x, double y) {
        screen->scrollCallbackEvent(x, y);
    });

    glfwSetFramebufferSizeCallback(window, [](GLFWwindow *, int width, int height) {
        screen->resizeCallbackEvent(width, height);
    });
}
void glfwBufferSet(GLFWwindow* window, int& width, int& height) {
    glfwGetFramebufferSize(window, &width, &height);
    glViewport(0, 0, width, height);
    glfwSwapInterval(0);
    glfwSwapBuffers(window);
}
void paint(Brush& b) {
    if(rightClick) {
        if (draw) {
            int xStep, yStep, x, y, brushh, brushw;
            Vector2i mousePos;
            xStep = width/w;yStep = height/h;
#if defined(__APPLE__)
            mousePos = screen->mousePos();x = mousePos[0]*2/xStep; y = mousePos[1]*2/yStep;
#else
            mousePos = screen->mousePos();x = mousePos[0]/xStep; y = mousePos[1]/yStep;
#endif
            b.getBrush(drawList[drawEnum]);
            b.getBrushSize(brushh, brushw);
            if (x + brushw/2 < width && y + brushh/2 < height && x - brushw/2 > 0 && y - brushh/2 > 0)
                g.paint(x, y, brushh, brushw, b.brush);
            rightClick = 0;
        }
    }
}


int main(int /* argc */, char ** /* argv */) {
    glfwInitWrapper();
    GLFWwindow* window = glfwCreateWindow(800, 800, "Game of Life", nullptr, nullptr);
    if (window == nullptr) {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
#if defined(NANOGUI_GLAD)
    if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress))
        throw std::runtime_error("Could not initialize GLAD!");
    glGetError(); // pull and ignore unhandled errors like GL_INVALID_ENUM
#endif
    // Create a nanogui screen and pass the glfw pointer to initialize
    screen = new Screen();
    screen->initialize(window, true);
    glfwBufferSet(window, width, height);
    // Create nanogui gui
    FormHelper *gui = new FormHelper(screen);
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // Read Pattern Library and Brush List.
    Brush b = Brush();    // Brush
    PatternLib lib(w, h); // Pattern
    b.initBrushList();
    lib.initPatternList();
    patternsList = lib.getPatternList();
    drawList = b.getBrushList();
//     Welcome Interface
    bool** pattern = new bool*[w];
    lib.getPattern("WELCOME", pattern);
    g.readLibrary(pattern);
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    guiMaker(gui, "Menu");
    glfwCallBackSet(window);
    Shader ourShader("vertex.vs", "fragment.frag");
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    GLfloat vertices[12];GLuint indices[6];
    std::vector<GLuint> VAOs, VBOs, EBOs;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            GLfloat iStep = (GLfloat)2.0/w;
            GLfloat jStep = (GLfloat)2.0/h;
            //    X                                    Y                                    Z
            vertices[0] = LTBOUND + (j + 1)*iStep;vertices[1] = DWBOUND + (i + 1)*jStep;vertices[2] = 0.0f;
            vertices[3] = LTBOUND + (j + 1)*iStep;vertices[4] = DWBOUND + i*iStep;      vertices[5] = 0.0f;
            vertices[6] = LTBOUND + j*jStep;      vertices[7] = DWBOUND + i*iStep;      vertices[8] = 0.0f;
            vertices[9] = LTBOUND + j*jStep;      vertices[10]= DWBOUND + (i + 1)*jStep;vertices[11]= 0.0f;

            indices[0]=0;indices[1]=1;indices[2]=3;
            indices[3]=1;indices[4]=2;indices[5]=3;
            GLuint VAO, VBO, EBO;
            glGenVertexArrays(1, &VAO);glGenBuffers(1, &VBO);glGenBuffers(1, &EBO);
                glBindVertexArray(VAO);
                glBindBuffer(GL_ARRAY_BUFFER, VBO);
                glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

                glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
                glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

                glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
                glEnableVertexAttribArray(0);
                // Note that this is allowed, the call to glVertexAttribPointer registered VBO as the currently
                // bound vertex buffer object so afterwards we can safely unbind
                glBindBuffer(GL_ARRAY_BUFFER, 0);
            glBindVertexArray(0);
            VAOs.push_back(VAO);VBOs.push_back(VBO);EBOs.push_back(EBO);
        }
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    double t1, t2;fps = "0.0";cur = "0.0";liveCell = 0;generation = 0;
    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);
        float timeValue = glfwGetTime();
        ourShader.Use();
        t1 = glfwGetTime();
        if (start)
            g.update();
        liveCell = 0;
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                GLint vertexColorLocation = glGetUniformLocation(ourShader.Program, "ourColor");

                if (g.valueofPos(h - i - 1, j)) {
                    ++liveCell;
                    float r = sin(timeValue/5) / 5.0f + 0.6f;
                    float g = sin(timeValue/10) / 5.0f + 0.3f;
                    float b = sin(timeValue/2) / 5.0f + 0.5f;
                    glUniform4f(vertexColorLocation, r, g, b, 1.0f);
                } else
                    glUniform4f(vertexColorLocation, 1.0,  1.0, 1.0f, 1.0f);
                glBindVertexArray(VAOs[i*w + j]);
                glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
                glBindVertexArray(0);
            }
        }

        if (start) {
            while ((glfwGetTime() - t1) < 1.0/FPS);
            t2 = glfwGetTime();
            std::stringstream ssFps, ssCur;
//            std::cout << t2 - t1 << std::endl;
            ssFps << std::fixed << std::setprecision(2) << 1/(t2 - t1);
            fps = ssFps.str();
            ssCur << std::fixed << std::setprecision(2) << t2;
            cur = ssCur.str();
            ++generation;
        }
        paint(b);

        screen->drawContents();
        screen->drawWidgets();
        gui->refresh();
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwTerminate();

    return 0;
}
//
// Created by Zeyu Chen on 4/23/18.
//

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

#define LTBOUND ((GLfloat)-1.0)
#define DWBOUND ((GLfloat)-1.0)
using namespace nanogui;

// HOT Fix Shader file
static time_t lastShaderVersion;
static time_t currShaderVersion;
//


bool start = false;
unsigned int FPS = 24;
std::string fps;
std::string cur;
static unsigned long totalCell;
unsigned long liveCell;
unsigned long generation;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// w, h represent the number of cells in row and col.
int w = 200, h = 200;
Game g(w, h);
//    g.init();

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
    gui->setFixedSize(Eigen::Vector2i(60, 30));

    gui->addGroup("Controller");
    gui->addButton("  Start  ", []() {
        std::cout << "Game start." << std::endl;start = true;
    })->setTooltip("Start the Game!");
    gui->addButton("  Pause  ", []() {
        std::cout << "Game paused." << std::endl;start = false;
    })->setTooltip("Pause the Game!");
    gui->addGroup("Mode");
    gui->addButton("  Random  ", []() {
        start = false;
        g.randomPattern();
        std::cout << "Random Mode" << std::endl;
    });
    gui->addGroup("Stats");
    gui->addVariable("FPS", fps)->setEditable(false);
    gui->addVariable("Time", cur)->setEditable(false);
//    gui->addVariable("Total Cells", )->setEditable(false);
    gui->addVariable("Live Cells", liveCell)->setEditable(false);
    gui->addVariable("Generation", generation)->setEditable(false);
    screen->setVisible(true);
    screen->performLayout();
//    nanoguiWindow->center(); // set the hui at the center of the window

}
void glfwCallBackSet(GLFWwindow* window) {
    glfwSetCursorPosCallback(window, [](GLFWwindow *, double x, double y) {
        screen->cursorPosCallbackEvent(x, y);
    });

    glfwSetMouseButtonCallback(window, [](GLFWwindow *, int button, int action, int modifiers) {
        screen->mouseButtonCallbackEvent(button, action, modifiers);
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

//shader
//vertex

//
//
int main(int /* argc */, char ** /* argv */) {
    glfwInitWrapper();
    // Create a GLFW window object

    GLFWwindow* window = glfwCreateWindow(1000, 1000, "Game of Life", nullptr, nullptr);
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

    int width, height;
    glfwBufferSet(window, width, height);
    // Create nanogui gui
    FormHelper *gui = new FormHelper(screen);
    guiMaker(gui, "Menu");
    glfwCallBackSet(window);
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    Shader ourShader("vertex.vs", "fragment.frag");
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    GLfloat vertices[12];GLuint indices[6];
    std::vector<GLuint> VAOs, VBOs, EBOs;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            GLfloat iStep = (GLfloat)2.0/w;
            GLfloat jStep = (GLfloat)2.0/h;
            //    X                                    Y                                    Z
            vertices[0] = LTBOUND + (i + 1)*iStep;vertices[1] = DWBOUND + (j + 1)*jStep;vertices[2] = 0.0f;
            vertices[3] = LTBOUND + (i + 1)*iStep;vertices[4] = DWBOUND + j*jStep;      vertices[5] = 0.0f;
            vertices[6] = LTBOUND + i*iStep;      vertices[7] = DWBOUND + j*jStep;      vertices[8] = 0.0f;
            vertices[9] = LTBOUND + i*iStep;      vertices[10]= DWBOUND + (j + 1)*jStep;vertices[11]= 0.0f;

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
//     Game loop
    double t1,t2;fps = "0.0";cur = "0.0";liveCell = 0;generation = 0;
    double compute1, compute2;
    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        ourShader.Use();
        t1 = glfwGetTime();
        if (start)
            g.update();
        liveCell = 0;
        compute1 = glfwGetTime();
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                GLint vertexColorLocation = glGetUniformLocation(ourShader.Program, "ourColor");

                if (g.valueofPos(i, j)) {
                    ++liveCell;
                    float timeValue = glfwGetTime();
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

        compute2 = glfwGetTime();
        std::cout << "Elapsed Time" << compute2 - compute1 << "ms" << std::endl;
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        // Draw nanogui


        if (start) {
            while ((glfwGetTime() - t1) < 1.0/FPS);
            t2 = glfwGetTime();
            std::stringstream ssFps, ssCur;
            ssFps << std::fixed << std::setprecision(2) << 1/(t2 - t1);
            fps = ssFps.str();
            ssCur << std::fixed << std::setprecision(2) << t2;
            cur = ssCur.str();
            ++generation;
        }

        screen->drawContents();
        screen->drawWidgets();
        gui->refresh();
        glfwSwapBuffers(window);
        // Check if any events have been activated (key pressed, mouse moved etc.)
        // and call corresponding response functions
        glfwPollEvents();
    }

    // Terminate GLFW, clearing any resources allocated by GLFW.
    glfwTerminate();

    return 0;
}
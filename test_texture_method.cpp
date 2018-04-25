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
#include <sys/stat.h>

#include <GLFW/glfw3.h>
#include <nanogui/nanogui.h>

#include "Shader.h"
#include "game.h"

using namespace nanogui;

// HOT Fix Shader file
static time_t lastShaderVersion;
static time_t currShaderVersion;
//
double lastTime = 0.0, currTime = 0.0;

GLint FPS = 24;
GLint window_width = 1000;
GLint window_height = 1000;
GLfloat left = 0.0;
GLfloat right = 1.0;
GLfloat bottom = 0.0;
GLfloat top = 1.0;
GLint game_width = 100;
GLint game_height = 100;

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
    ref<Window> nanoguiWindow = gui->addWindow(Eigen::Vector2i(0, 0), name);
    gui->setFixedSize(Eigen::Vector2i(10, 90));

    gui->addGroup("Controller");
    gui->addButton("  Start  ", []() {
        std::cout << "Game start." << std::endl;
    })->setTooltip("Start the Game!");
    gui->addButton("  Pause  ", []() {
        std::cout << "Game paused." << std::endl;
    })->setTooltip("Pause the Game!");

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

    GLFWwindow* window = glfwCreateWindow(640, 480, "Game of Life", nullptr, nullptr);
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

    int w = 1000, h = 1000;
    game g(w, h);
    g.init();

    unsigned char* data = new unsigned char[w*h*3];
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            data[ 3 * (i * w + j) + 0 ] = g.valueofPos(i,j)? 255 : 0;
            data[ 3 * (i * w + j) + 1 ] = g.valueofPos(i,j)? 255 : 0;
            data[ 3 * (i * w + j) + 2 ] = g.valueofPos(i,j)? 255 : 0;
        }
    }
    unsigned int texture;
    glGenTextures(2, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, w, h, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
    glGenerateMipmap(GL_TEXTURE_2D);
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    Shader ourShader("vertex.vs", "fragment.frag");
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    GLfloat vertices[] = {
            // Positions          // Colors           // Texture Coords
            1.0f,  1.0f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f, // Top Right
            1.0f, -1.0f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f, // Bottom Right
            -1.0f, -1.0f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f, // Bottom Left
            -1.0f,  1.0f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f  // Top Left
    };
    GLuint indices[] = {  // Note that we start from 0!
            0, 1, 3, // First Triangle
            1, 2, 3  // Second Triangle
    };
    GLuint VAO, VBO, EBO;
    glGenVertexArrays(1, &VAO);glGenBuffers(1, &VBO);glGenBuffers(1, &EBO);
    glBindVertexArray(VAO);
        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

        // Position attribute
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)0);
        glEnableVertexAttribArray(0);
        // Color attribute
        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
        glEnableVertexAttribArray(1);
        // TexCoord attribute
        glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(6 * sizeof(GLfloat)));
        glEnableVertexAttribArray(2);
    glBindVertexArray(0);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//     Game loop
    while (!glfwWindowShouldClose(window)) {
//        glClearColor(0.2f, 0.25f, 0.3f, 1.0f);
        glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        glBindTexture(GL_TEXTURE_2D, texture);
        ourShader.Use();
        glBindVertexArray(VAO);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
        glBindVertexArray(0);
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        // Draw nanogui
        screen->drawContents();
        screen->drawWidgets();

        glfwSwapBuffers(window);
        // Check if any events have been activated (key pressed, mouse moved etc.)
        // and call corresponding response functions
        glfwPollEvents();
    }

    // Terminate GLFW, clearing any resources allocated by GLFW.
    glfwTerminate();

    return 0;
}
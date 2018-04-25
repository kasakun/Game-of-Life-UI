//
// Created by Zeyu Chen on 3/27/18.
//
#include <iostream>
#include <vector>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "game.h"

#define WHITE 1.0, 1.0, 1.0
#define BLACK 0.0, 0.0, 0.0

/*
 * Need:
 * 1. UI, GLUT preferred.
 * 2. LIBRARY
 * 3. RGB(optional)
 * 4. Parallel(optional)
 *
 */

double zoom = 1.0;
int fps = 24;

GLFWwindow* window = nullptr;

int width = 1280;
int height = 960;

GLuint program;
GLuint shader;

int main(int argc, char **argv) {

    if(!glfwInit()) {
        std::cerr << "Fail to init GLFW" << std::endl;
        return 1;
    }
    atexit(glfwTerminate);


    return 0;
}
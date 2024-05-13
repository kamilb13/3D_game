#include <iostream>
#include "GLEWInitializer.h"

GLFWwindow* GLEWInitializer::initGLEW(int width, int height, const char* title) {
    GLFWwindow* window;

    if (!glfwInit()) {
        return nullptr;
    }

    window = glfwCreateWindow(width, height, title, nullptr, nullptr);
    if (!window) {
        glfwTerminate();
        return nullptr;
    }

    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);   
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK) {
        std::cout << "Failed to initialize GLEW\n";
        glfwDestroyWindow(window);
        glfwTerminate();
        return nullptr;
    }

    return window;
}
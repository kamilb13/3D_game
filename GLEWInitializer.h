#ifndef GLEWINITIALIZER_H
#define GLEWINITIALIZER_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>

class GLEWInitializer {
public:
    static GLFWwindow* initGLEW(int width, int height, const char* title);
};

#endif
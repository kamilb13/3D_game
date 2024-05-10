#ifndef FPS_3D_OPENGL_CROSSHAIR_H
#define FPS_3D_OPENGL_CROSSHAIR_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Crosshair {
public:
    static void drawCrosshair(float screen_width, float screen_height);
};

#endif //FPS_3D_OPENGL_CROSSHAIR_H

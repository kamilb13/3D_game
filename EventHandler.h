#ifndef FPS_3D_OPENGL_EVENTHANDLER_H
#define FPS_3D_OPENGL_EVENTHANDLER_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <vector>
#include "Map.h"

class EventHandler {
public:
    static void keyHandler(GLFWwindow *window, bool keys[1024], float cameraSpeed, glm::vec3 *cameraPos, glm::vec3 cameraFront, glm::vec3 cameraUp, float deltaTime, Map map);
    static bool isInsideMapBounds(const glm::vec3& position, float minX, float maxX, float minZ, float maxZ);

};


#endif //FPS_3D_OPENGL_EVENTHANDLER_H

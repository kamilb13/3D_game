#include "EventHandler.h"

void EventHandler::keyHandler(GLFWwindow *window, bool keys[1024], float cameraSpeed, glm::vec3 *cameraPos, glm::vec3 cameraFront, glm::vec3 cameraUp, float deltaTime) {
    if (keys[GLFW_KEY_W]) {
        *cameraPos += cameraSpeed * deltaTime * cameraFront;
    }
    if (keys[GLFW_KEY_S]) {
        *cameraPos -= cameraSpeed * deltaTime * cameraFront;
    }
    if (keys[GLFW_KEY_A]) {
        *cameraPos -= glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed * deltaTime;
    }
    if (keys[GLFW_KEY_D]) {
        *cameraPos += glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed * deltaTime;
    }

    if (keys[GLFW_KEY_ESCAPE]) {
        glfwSetWindowShouldClose(window, true);
    }
}

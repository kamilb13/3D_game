#include "EventHandler.h"

void EventHandler::keyHandler(GLFWwindow *window, bool keys[1024], float cameraSpeed, glm::vec3 *cameraPos, glm::vec3 cameraFront, glm::vec3 cameraUp, float deltaTime, Map map) {
    float speed;

    // SPRINT
    if (keys[GLFW_KEY_LEFT_SHIFT]) {
        speed = cameraSpeed * 3;
    } else {
        speed = cameraSpeed;
    }

    if (keys[GLFW_KEY_W]) {
        glm::vec3 newPos = *cameraPos + speed * deltaTime * cameraFront;
        *cameraPos = newPos;
    }
    if (keys[GLFW_KEY_S]) {
        glm::vec3 newPos = *cameraPos - speed * deltaTime * cameraFront;
        *cameraPos = newPos;
    }
    if (keys[GLFW_KEY_A]) {
        glm::vec3 newPos = *cameraPos - glm::normalize(glm::cross(cameraFront, cameraUp)) * speed * deltaTime;
        *cameraPos = newPos;
    }
    if (keys[GLFW_KEY_D]) {
        glm::vec3 newPos = *cameraPos + glm::normalize(glm::cross(cameraFront, cameraUp)) * speed * deltaTime;
        *cameraPos = newPos;
    }

    if (keys[GLFW_KEY_ESCAPE]) {
        glfwSetWindowShouldClose(window, true);
    }
}
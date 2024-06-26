#include "EventHandler.h"

bool EventHandler::isInsideMapBounds(const glm::vec3& position, Map map) {
    if ((position.x >= map.minX && position.x <= map.maxX) && (position.z >= map.minZ && position.z <= map.maxZ)) {
//        std::cout << "Inside the map" << std::endl;
        return true;
    } else {
//        std::cout << "Outside the map" << std::endl;
        return false;
    }
}

void EventHandler::keyHandler(GLFWwindow* window, bool keys[1024], float cameraSpeed, glm::vec3* cameraPos, glm::vec3 cameraFront, glm::vec3 cameraUp, float deltaTime, Map map) {
    float speed = keys[GLFW_KEY_LEFT_SHIFT] ? cameraSpeed * 3 : cameraSpeed;
    glm::vec3 newPos;

    if (keys[GLFW_KEY_W]) {
        std::cout << "W" << std::endl;
        newPos = *cameraPos + cameraFront * speed * deltaTime;
        if (isInsideMapBounds(newPos, map)) {
            *cameraPos = newPos;
        }
    }
    if (keys[GLFW_KEY_S]) {
        newPos = *cameraPos - cameraFront * speed * deltaTime;
        if (isInsideMapBounds(newPos, map)) {
            *cameraPos = newPos;
        }
    }
    if (keys[GLFW_KEY_A]) {
        newPos = *cameraPos - glm::normalize(glm::cross(cameraFront, cameraUp)) * speed * deltaTime;
        if (isInsideMapBounds(newPos, map)) {
            *cameraPos = newPos;
        }
    }
    if (keys[GLFW_KEY_D]) {
        newPos = *cameraPos + glm::normalize(glm::cross(cameraFront, cameraUp)) * speed * deltaTime;
        if (isInsideMapBounds(newPos, map)) {
            *cameraPos = newPos;
        }
    }

    if (keys[GLFW_KEY_ESCAPE]) {
        glfwSetWindowShouldClose(window, true);
    }
}

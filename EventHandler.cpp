#include "EventHandler.h"

void EventHandler::keyHandler(GLFWwindow *window, bool keys[1024], float cameraSpeed, glm::vec3 *cameraPos, glm::vec3 cameraFront, glm::vec3 cameraUp, float deltaTime) {
    float speed;

    // SPRINT
    if (keys[GLFW_KEY_LEFT_SHIFT]) {
        speed = cameraSpeed * 3;
    }
    else
    {
        speed = cameraSpeed;
    }
    
    if (keys[GLFW_KEY_W]) {
        *cameraPos += speed * deltaTime * cameraFront;
    }
    if (keys[GLFW_KEY_S]) {
        *cameraPos -= speed * deltaTime * cameraFront;
    }
    if (keys[GLFW_KEY_A]) {
        *cameraPos -= glm::normalize(glm::cross(cameraFront, cameraUp)) * speed * deltaTime;
    }
    if (keys[GLFW_KEY_D]) {
        *cameraPos += glm::normalize(glm::cross(cameraFront, cameraUp)) * speed * deltaTime;
    }
    
    

    if (keys[GLFW_KEY_ESCAPE]) {
        glfwSetWindowShouldClose(window, true);
    }
}



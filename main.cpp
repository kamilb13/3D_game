#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <vector>

#include "Crosshair.h"
#include "Camera.h"
#include "Bullet.h"
#include "EventHandler.h"
#include "Cube.h"
#include "Map.h"

#define SCREEN_WIDTH 1920
#define SCREEN_HEIGHT 1080

// do tego zeby jak patrze do przodu to zebym szedl do przodu a nie na sztywno
glm::vec3 cameraPos = glm::vec3(10.0f, 20.0f, 10.0f);
glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);

double rotationX = 0.0f;
double rotationY = 60.0f;
float lastX = SCREEN_WIDTH / 2.0f;
float lastY = SCREEN_HEIGHT / 2.0f;
bool firstMouse = true;

bool keys[1024];
float cameraSpeed = 30.0f;
float deltaTime = 0.0f; // Time between current frame and last frame
float lastFrame = 0.0f;

// Deklaracja prędkości wertykalnej
float verticalVelocity = 2.0f;
// Stała reprezentująca siłę podskoku
float jumpForce = 2.0f;

float gravity = -0.2f; // Stała grawitacji
float posY = -12.0f; // Początkowa pozycja Y postaci
int currentBullet = 0;


void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    if (action == GLFW_PRESS) {
        keys[key] = true;
    } else if (action == GLFW_RELEASE) {
        keys[key] = false;
    }
    if (action == GLFW_PRESS && key == GLFW_KEY_R) {
        currentBullet = 0;
    }
}


Bullet bullet;

Bullet magazine[30];


void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods) {
    if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS) {
        std::cout << "Strzał!" << std::endl;
        if (currentBullet < 30) {
            magazine[currentBullet++].shoot(cameraPos, cameraFront);
        }
        bullet.shoot(cameraPos, cameraFront);
    }
}


void cursorPositionCallback(GLFWwindow* window, double xpos, double ypos) {
    if (firstMouse) {
        lastX = (float) xpos;
        lastY = (float) ypos;
        firstMouse = false;
    }

    double xoffset = xpos - lastX;
    double yoffset = lastY - ypos; // reversed since y-coordinates go from bottom to top

    lastX = xpos;
    lastY = ypos;

    float sensitivity = 0.1f;
    xoffset *= sensitivity;
    yoffset *= sensitivity;

    rotationY += xoffset;
    rotationX += yoffset;

    // Constrain pitch
    if (rotationX > 89.0f)
        rotationX = 89.0f;
    if (rotationX < -89.0f)
        rotationX = -89.0f;
}





int main() {
    GLFWwindow* window;

    if (!glfwInit()) {
        return -1;
    }

    window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "OpenGL Window", nullptr, nullptr);
    if (!window) {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);    //vsync
    glfwSetKeyCallback(window, keyCallback);
    glfwSetCursorPosCallback(window, cursorPositionCallback);
    glfwSetMouseButtonCallback(window, mouseButtonCallback);
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    glEnable(GL_DEPTH_TEST);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glm::mat4 projection = glm::perspective(glm::radians(75.0f), (float)SCREEN_WIDTH / (float)SCREEN_HEIGHT, 0.1f, 1000.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadMatrixf(glm::value_ptr(projection));

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();



    Map map;
    map.generateMapFromFile("../map.txt");



    while (!glfwWindowShouldClose(window)) {
        float currentFrame = glfwGetTime();
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;

        // Kolizja z podstawą sześcianu
        if (posY < 12.0f) {
            posY += 0.7f; // Zatrzymaj postać na wysokości podstawy sześcianu
            //gravity = 0.0f; // Zresetuj grawitację
        }

        glfwPollEvents();
        EventHandler::keyHandler(window, keys, cameraSpeed, &cameraPos, cameraFront, cameraUp, deltaTime);

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glLoadIdentity();



        // Aktualizacja wektora cameraFront na podstawie rotationX i rotationY
        glm::vec3 front;
        front.x = cos(glm::radians(rotationY)) * cos(glm::radians(rotationX));
        front.y = sin(glm::radians(rotationX));
        front.z = sin(glm::radians(rotationY)) * cos(glm::radians(rotationX));
        cameraFront = glm::normalize(front);

        // Ustawienie kamery
        glm::mat4 view = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);
        glMultMatrixf(glm::value_ptr(view));


        if (currentBullet <= 30) {
            for (int i = 0; i < 30; i++) {
                if (magazine[i].isActive) {
                    magazine[i].drawBullet();
                    magazine[i].updateBulletPosition();
                }
            }
        }

        // Przesunięcie postaci na nową pozycję
        glTranslatef(0.0f, posY, 0.0f);


        map.drawMap(10);
        Crosshair::drawCrosshair(SCREEN_WIDTH, SCREEN_HEIGHT);

        glPopMatrix();
        glMatrixMode(GL_PROJECTION);
        glPopMatrix();
        glMatrixMode(GL_MODELVIEW);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
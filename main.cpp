#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <cmath>

#include "GLEWInitializer.h"
#include "Crosshair.h"
#include "Bullet.h"
#include "EventHandler.h"
#include "Map.h"
#include "Target.h"

#define SCREEN_WIDTH 1920
#define SCREEN_HEIGHT 1080
#define SCALE 2
#define M_PI 3.14159265358979323846

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
float deltaTime = 0.0f;
float lastFrame = 0.0f;

float points = 0;

float posY = 1.0f;
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

Bullet magazine[30];

Target targetsTab[5];
glm::vec3 targets[] = {
    glm::vec3(2.1f, 6, 5),
    glm::vec3(2.1f, 4, 3),
    glm::vec3(2.1f, 4, 52),
    glm::vec3(2.1f, 8, 40),
    glm::vec3(2.1f, 5, 23),
};

void initTargets() {
    for (int i = 0; i < 5; i++) {
        targetsTab[i].targetPosition = targets[i];
        targetsTab[i].radius = 2.0f;
    }
}

void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods) {
    if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS) {
        std::cout << "Strzal!" << std::endl;
        if (currentBullet < 30) {
            magazine[currentBullet++].shoot(cameraPos, cameraFront);
        }
        else {
            std::cout << "Pusty magazynek!" << std::endl;
        }
    }
}


void cursorPositionCallback(GLFWwindow* window, double xpos, double ypos) {
    if (firstMouse) {
        lastX = (float) xpos;
        lastY = (float) ypos;
        firstMouse = false;
    }

    double xoffset = xpos - lastX;
    double yoffset = lastY - ypos;

    lastX = xpos;
    lastY = ypos;

    float sensitivity = 0.1f;
    xoffset *= sensitivity;
    yoffset *= sensitivity;

    rotationY += xoffset;
    rotationX += yoffset;

    if (rotationX > 89.0f)
        rotationX = 89.0f;
    if (rotationX < -89.0f)
        rotationX = -89.0f;
}

int main() {
    GLFWwindow* window = GLEWInitializer::initGLEW(SCREEN_WIDTH, SCREEN_HEIGHT, "FPS 3D");
    if (!window) {
        std::cerr << "Failed to initialize GLEW and create GLFW window\n";
        return -1;
    }

    glfwSetKeyCallback(window, keyCallback);
    glfwSetCursorPosCallback(window, cursorPositionCallback);
    glfwSetMouseButtonCallback(window, mouseButtonCallback);

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

    initTargets();

    while (!glfwWindowShouldClose(window)) {
        float currentFrame = glfwGetTime();
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;

        cameraPos.y = 5.0f;

        glfwPollEvents();
        EventHandler::keyHandler(window, keys, cameraSpeed, &cameraPos, cameraFront, cameraUp, deltaTime, map);

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

//        std::cout << "x " << cameraPos.x << std::endl;
//        std::cout << "y " <<  cameraPos.y << std::endl;
//        std::cout << "z " <<  cameraPos.z << std::endl;

        for (int i = 0; i < 5; i++) {
            targetsTab[i].drawFilledCircle(90.0f);
        }
        
        if (currentBullet <= 30) {
            for (int i = 0; i < 30; i++) {
                if (magazine[i].isActive) {
                    magazine[i].drawBullet();
                    magazine[i].updateBulletPosition();
                    for (int j = 0; j < 5; j++) {
                        if (targetsTab[j].checkCollision(magazine[i].currentBulletPosition, 0.2f, &points)) {
                            magazine[i].isActive = false;
                        }
                    }
                }
            }
        }

        // Przesunięcie postaci na nową pozycję
        glTranslatef(0.0f, posY, 0.0f);

        map.drawMap(SCALE);
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

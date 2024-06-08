#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <random>

#define SEGMENTS 20
#define M_PI 3.14159265358979323846
class Target
{
public:
    glm::vec3 targetPosition;
    float radius;
    void drawFilledCircle(float angle);
    bool checkCollision(glm::vec3 bulletPosition, float cubeSize, float* points);
    float randomFloat(float x, float y);
    void changeTarget();

};


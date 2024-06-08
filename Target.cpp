#include "Target.h"

void Target::drawFilledCircle(float angle)
{
    glPushMatrix();
    glTranslatef(targetPosition.x, targetPosition.y, targetPosition.z);
    glRotatef(angle, 0.0f, 1.0f, 0.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(0.0f, 0.0f);
    for (int i = 0; i <= SEGMENTS; i++) {
        float theta = 2.0f * M_PI * static_cast<float>(i) / static_cast<float>(SEGMENTS);
        float x = radius * cos(theta);
        float y = radius * sin(theta);
        glVertex2f(x, y);
    }
    glEnd();
    glPopMatrix();
}

bool Target::checkCollision(glm::vec3 bulletPosition, float cubeSize, float* points)
{
    for (int i = 0; i < 8; i++) {
        glm::vec3 cubePoint = bulletPosition;
        cubePoint.x += (i & 1) ? cubeSize : -cubeSize;
        cubePoint.y += (i & 2) ? cubeSize : -cubeSize;
        cubePoint.z += (i & 4) ? cubeSize : -cubeSize;

        float distanceSquared = glm::distance(cubePoint, targetPosition);
        if (distanceSquared < radius * radius / 2) {
            
            changeTarget();
            *points += 10.0f / radius;
            std::cout << "Cel trafiony. Ilosc punktow: " << *points << std::endl;
            return true;
        }
    }

    float minX = bulletPosition.x - cubeSize;
    float maxX = bulletPosition.x + cubeSize;
    float minY = bulletPosition.y - cubeSize;
    float maxY = bulletPosition.y + cubeSize;
    float minZ = bulletPosition.z - cubeSize;
    float maxZ = bulletPosition.z + cubeSize;

    float closestX = glm::clamp(targetPosition.x, minX, maxX);
    float closestY = glm::clamp(targetPosition.y, minY, maxY);
    float closestZ = glm::clamp(targetPosition.z, minZ, maxZ);

    float distanceSquared = glm::distance(glm::vec3(closestX, closestY, closestZ), targetPosition);
    return distanceSquared < radius * radius / 2;
}

float Target::randomFloat(float x, float y)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<float> dis(x, y);
    return dis(gen);
}

void Target::changeTarget()
{
    float x = 2.1f; // Na stałe bo ma sie renderowac na jednej scianie
    float y = randomFloat(6.0f, 8.0f); // Wysokosc celów
    float z = randomFloat(3.0f, 50.0f);
    float r = randomFloat(1.5f, 3.0f);

    this->targetPosition = glm::vec3(x, y, z);
    this->radius = r;

}

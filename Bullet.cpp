#include "Bullet.h"

void Bullet::shoot(glm::vec3 cameraPosition, glm::vec3 cameraFront)
{
    this->isActive = true;
    this->currentBulletPosition = cameraPosition;
    this->bulletDirection = cameraFront;
}

void Bullet::drawBullet()
{
    glm::vec3 center = currentBulletPosition;

    float halfSize = size / 2.0f;

    //// Front face
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.0f, 0.0f); // Red
    glVertex3f(center.x - halfSize, center.y - halfSize, center.z + halfSize);
    glVertex3f(center.x + halfSize, center.y - halfSize, center.z + halfSize);
    glVertex3f(center.x + halfSize, center.y + halfSize, center.z + halfSize);
    glVertex3f(center.x - halfSize, center.y + halfSize, center.z + halfSize);
    // Back face
    glColor3f(0.0f, 1.0f, 0.0f); // Green
    glVertex3f(center.x - halfSize, center.y - halfSize, center.z - halfSize);
    glVertex3f(center.x - halfSize, center.y + halfSize, center.z - halfSize);
    glVertex3f(center.x + halfSize, center.y + halfSize, center.z - halfSize);
    glVertex3f(center.x + halfSize, center.y - halfSize, center.z - halfSize);
    // Top face
    glColor3f(0.0f, 0.0f, 1.0f); // Blue
    glVertex3f(center.x - halfSize, center.y + halfSize, center.z - halfSize);
    glVertex3f(center.x - halfSize, center.y + halfSize, center.z + halfSize);
    glVertex3f(center.x + halfSize, center.y + halfSize, center.z + halfSize);
    glVertex3f(center.x + halfSize, center.y + halfSize, center.z - halfSize);
    // Bottom face
    glColor3f(1.0f, 1.0f, 0.0f); // Yellow
    glVertex3f(center.x - halfSize, center.y - halfSize, center.z - halfSize);
    glVertex3f(center.x + halfSize, center.y - halfSize, center.z - halfSize);
    glVertex3f(center.x + halfSize, center.y - halfSize, center.z + halfSize);
    glVertex3f(center.x - halfSize, center.y - halfSize, center.z + halfSize);
    //// Right face
    glColor3f(1.0f, 0.0f, 1.0f); // Magenta
    glVertex3f(center.x + halfSize, center.y - halfSize, center.z - halfSize);
    glVertex3f(center.x + halfSize, center.y + halfSize, center.z - halfSize);
    glVertex3f(center.x + halfSize, center.y + halfSize, center.z + halfSize);
    glVertex3f(center.x + halfSize, center.y - halfSize, center.z + halfSize);
    // Left face
    glColor3f(0.0f, 1.0f, 1.0f); // Cyan
    glVertex3f(center.x - halfSize, center.y - halfSize, center.z - halfSize);
    glVertex3f(center.x - halfSize, center.y - halfSize, center.z + halfSize);
    glVertex3f(center.x - halfSize, center.y + halfSize, center.z + halfSize);
    glVertex3f(center.x - halfSize, center.y + halfSize, center.z - halfSize);
    glEnd();
}

void Bullet::updateBulletPosition()
{
    this->currentBulletPosition += bulletDirection * speed;
}
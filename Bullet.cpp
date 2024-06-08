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

    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3f(center.x - halfSize, center.y - halfSize, center.z + halfSize);
    glVertex3f(center.x + halfSize, center.y - halfSize, center.z + halfSize);
    glVertex3f(center.x + halfSize, center.y + halfSize, center.z + halfSize);
    glVertex3f(center.x - halfSize, center.y + halfSize, center.z + halfSize);

    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(center.x - halfSize, center.y - halfSize, center.z - halfSize);
    glVertex3f(center.x - halfSize, center.y + halfSize, center.z - halfSize);
    glVertex3f(center.x + halfSize, center.y + halfSize, center.z - halfSize);
    glVertex3f(center.x + halfSize, center.y - halfSize, center.z - halfSize);

    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex3f(center.x - halfSize, center.y + halfSize, center.z - halfSize);
    glVertex3f(center.x - halfSize, center.y + halfSize, center.z + halfSize);
    glVertex3f(center.x + halfSize, center.y + halfSize, center.z + halfSize);
    glVertex3f(center.x + halfSize, center.y + halfSize, center.z - halfSize);

    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex3f(center.x - halfSize, center.y - halfSize, center.z - halfSize);
    glVertex3f(center.x + halfSize, center.y - halfSize, center.z - halfSize);
    glVertex3f(center.x + halfSize, center.y - halfSize, center.z + halfSize);
    glVertex3f(center.x - halfSize, center.y - halfSize, center.z + halfSize);

    glColor3f(1.0f, 0.0f, 1.0f);
    glVertex3f(center.x + halfSize, center.y - halfSize, center.z - halfSize);
    glVertex3f(center.x + halfSize, center.y + halfSize, center.z - halfSize);
    glVertex3f(center.x + halfSize, center.y + halfSize, center.z + halfSize);
    glVertex3f(center.x + halfSize, center.y - halfSize, center.z + halfSize);

    glColor3f(0.0f, 1.0f, 1.0f); 
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
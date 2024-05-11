#include "Map.h"

void Map::drawMap() {
    drawWall(0, 0, 0, 100.f, 1.0f, 100.f); //floor
    drawWall(45.0f, 1.0f, 0, 55.0f, 10.0f, 1.0f);
}

void Map::drawWall(float x1, float y1, float z1, float x2, float y2, float z2) {
    glBegin(GL_QUADS);
    // Front face
    glColor3f (0.5, 0.5, 0.5);
    glVertex3f(x1, y1, z1);
    glVertex3f(x2, y1, z1);
    glVertex3f(x2, y2, z1);
    glVertex3f(x1, y2, z1);
    glEnd();

    glBegin(GL_QUADS);
    // Back face
    glColor3f (0.5, 0.5, 0.5);
    glVertex3f(x1, y1, z2);
    glVertex3f(x2, y1, z2);
    glVertex3f(x2, y2, z2);
    glVertex3f(x1, y2, z2);
    glEnd();

    glBegin(GL_QUADS);
    // Top face
    glColor3f (0.5, 0.5, 0.5);
    glVertex3f(x1, y2, z1);
    glVertex3f(x2, y2, z1);
    glVertex3f(x2, y2, z2);
    glVertex3f(x1, y2, z2);
    glEnd();

    glBegin(GL_QUADS);
    // Bottom face
    glColor3f (0.5, 0.5, 0.5);
    glVertex3f(x1, y1, z1);
    glVertex3f(x2, y1, z1);
    glVertex3f(x2, y1, z2);
    glVertex3f(x1, y1, z2);
    glEnd();

    glBegin(GL_QUADS);
    // Left face
    glColor3f (0.5, 0.5, 0.5);
    glVertex3f(x1, y1, z1);
    glVertex3f(x1, y2, z1);
    glVertex3f(x1, y2, z2);
    glVertex3f(x1, y1, z2);
    glEnd();

    glBegin(GL_QUADS);
    // Right face
    glColor3f (0.5, 0.5, 0.5);
    glVertex3f(x2, y1, z1);
    glVertex3f(x2, y2, z1);
    glVertex3f(x2, y2, z2);
    glVertex3f(x2, y1, z2);
    glEnd();
}
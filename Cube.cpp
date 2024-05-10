#include "Cube.h"

void Cube::drawCube() {
    // Front face
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.0f, 0.0f); // Red
    glVertex3f(-5.0f, -5.0f, 5.0f);
    glVertex3f(5.0f, -5.0f, 5.0f);
    glVertex3f(5.0f, 5.0f, 5.0f);
    glVertex3f(-5.0f, 5.0f, 5.0f);
    // Back face
    glColor3f(0.0f, 1.0f, 0.0f); // Green
    glVertex3f(-5.0f, -5.0f, -5.0f);
    glVertex3f(-5.0f, 5.0f, -5.0f);
    glVertex3f(5.0f, 5.0f, -5.0f);
    glVertex3f(5.0f, -5.0f, -5.0f);
    // Top face
    glColor3f(0.0f, 0.0f, 1.0f); // Blue
    glVertex3f(-5.0f, 5.0f, -5.0f);
    glVertex3f(-5.0f, 5.0f, 5.0f);
    glVertex3f(5.0f, 5.0f, 5.0f);
    glVertex3f(5.0f, 5.0f, -5.0f);
    // Bottom face
    glColor3f(1.0f, 1.0f, 0.0f); // Yellow
    glVertex3f(-5.0f, -5.0f, -5.0f);
    glVertex3f(5.0f, -5.0f, -5.0f);
    glVertex3f(5.0f, -5.0f, 5.0f);
    glVertex3f(-5.0f, -5.0f, 5.0f);
    // Right face
    glColor3f(1.0f, 0.0f, 1.0f); // Magenta
    glVertex3f(5.0f, -5.0f, -5.0f);
    glVertex3f(5.0f, 5.0f, -5.0f);
    glVertex3f(5.0f, 5.0f, 5.0f);
    glVertex3f(5.0f, -5.0f, 5.0f);
    // Left face
    glColor3f(0.0f, 1.0f, 1.0f); // Cyan
    glVertex3f(-5.0f, -5.0f, -5.0f);
    glVertex3f(-5.0f, -5.0f, 5.0f);
    glVertex3f(-5.0f, 5.0f, 5.0f);
    glVertex3f(-5.0f, 5.0f, -5.0f);
    glEnd();
}
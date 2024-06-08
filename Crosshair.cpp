#include "Crosshair.h"

void Crosshair::drawCrosshair(float screen_width, float screen_height) {
    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    glm::mat4 ortho = glm::ortho(0.0f, screen_width, screen_height, 0.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadMatrixf(glm::value_ptr(ortho));
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();

    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 1.0f);

    // Linie poziome
    glVertex2f(screen_width / 2 - 10, screen_height / 2);
    glVertex2f(screen_width / 2 + 10, screen_height / 2);
    // Linie pionowe
    glVertex2f(screen_width / 2, screen_height / 2 - 10);
    glVertex2f(screen_width / 2, screen_height / 2 + 10);
    glEnd();

}

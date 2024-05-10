#include "Bullet.h"

void Bullet::drawBullet(const glm::vec3& position) {
    // Ustaw pozycję pocisku
    glPushMatrix();
    glTranslatef(position.x, position.y, position.z);

    // Rysuj kwadrat
    glBegin(GL_QUADS);
    glVertex3f(-0.2f, -0.2f, 0.0f);
    glVertex3f(0.2f, -0.2f, 0.0f);
    glVertex3f(0.2f, 0.2f, 0.0f);
    glVertex3f(-0.2f, 0.2f, 0.0f);
    glEnd();

    // Przywróć pierwotną macierz modelu-widoku
    glPopMatrix();
}
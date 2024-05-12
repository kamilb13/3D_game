#ifndef FPS_3D_OPENGL_BULLET_H
#define FPS_3D_OPENGL_BULLET_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>


class Bullet {
public:
    glm::vec3 currentBulletPosition;
    glm::vec3 bulletDirection;
    float size = 0.2f;
    float speed = 3.0f;
    bool isActive;
    void shoot(glm::vec3 cameraPosition, glm::vec3 cameraFront);
    void drawBullet();
    void updateBulletPosition();

};


#endif //FPS_3D_OPENGL_BULLET_H
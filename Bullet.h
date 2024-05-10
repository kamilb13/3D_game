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
    void drawBullet(const glm::vec3& position);
};


#endif //FPS_3D_OPENGL_BULLET_H

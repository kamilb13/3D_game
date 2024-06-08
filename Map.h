#ifndef FPS_3D_OPENGL_MAP_H
#define FPS_3D_OPENGL_MAP_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <vector>
#include <fstream>

class Map {
public:
    int rows;
    int cols;
    std::vector<std::vector<int>> tab;
    void generateMapFromFile(const std::string &filename);
    void drawMap(float scale);
    float minX;
    float minZ;
    float maxX;
    float maxZ;

private:
    static void drawWall(float x1, float y1, float z1, float x2, float y2, float z2);
};


#endif //FPS_3D_OPENGL_MAP_H

#include "Map.h"

void Map::drawWall(float x1, float y1, float z1, float x2, float y2, float z2) {
    glBegin(GL_QUADS);
    // Front face
    glColor3f (0, 0, 1.0f);
    glVertex3f(x1, y1, z1);
    glVertex3f(x2, y1, z1);
    glVertex3f(x2, y2, z1);
    glVertex3f(x1, y2, z1);
    glEnd();

    glBegin(GL_QUADS);
    // Back face
    glColor3f (1.0f, 0, 0);
    glVertex3f(x1, y1, z2);
    glVertex3f(x2, y1, z2);
    glVertex3f(x2, y2, z2);
    glVertex3f(x1, y2, z2);
    glEnd();


    glBegin(GL_QUADS);
    // Bottom face
    glColor3f (0, 1.0f, 0);
    glVertex3f(x1, y1, z1);
    glVertex3f(x2, y1, z1);
    glVertex3f(x2, y1, z2);
    glVertex3f(x1, y1, z2);
    glEnd();

    glBegin(GL_QUADS);
    // Left face
    glColor3f (1.0, 1.0, 0.5);
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

void Map::drawFloor(float x1, float y1, float z1, float x2, float y2, float z2) {
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

void Map::generateMapFromFile(const std::string &filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }

    file >> this->rows >> this->cols;
    tab.resize(rows, std::vector<int>(cols));
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            file >> this->tab[i][j];
        }
    }

    file.close();
}

void Map::drawMap(int scale) {
    int lastX = 0;
    int lastZ = 0;
    drawFloor(0, 0, 0, rows * scale, 1.0f, cols * scale);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (tab[i][j] > 0) {
                drawWall(lastX * scale, 0, lastZ * scale, (lastX + 1) * scale, tab[i][j] * scale,
                         (lastZ + 1) * scale); // Adjusted the coordinates with the scale
            }
            lastX += 1;
        }
        lastX = 0;
        lastZ += 1;
    }
}

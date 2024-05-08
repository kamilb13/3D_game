#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <vector>

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

// do tego zeby jak patrze do przodu to zebym szedl do przodu a nie na sztywno 
glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, 3.0f);
glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);

float rotationX = 0.0f;
float rotationY = 60.0f;
float lastX = SCREEN_WIDTH / 2.0f;
float lastY = SCREEN_HEIGHT / 2.0f;
bool firstMouse = true;

// Deklaracja prędkości wertykalnej
float verticalVelocity = 0.0f;
// Stała reprezentująca siłę podskoku
float jumpForce = 0.5f;

float gravity = -0.2f; // Stała grawitacji
float posY = -12.0f; // Początkowa pozycja Y postaci

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GLFW_TRUE);

    float cameraSpeed = 1.0f;
    if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS)
        cameraSpeed *= 5.0f;

    glm::vec3 cameraRight = glm::normalize(glm::cross(cameraFront, cameraUp));
    glm::vec3 cameraDirection = glm::normalize(glm::cross(cameraRight, cameraUp));

    float maxX = 23.0f;
    float maxY = 23.0f;
    float maxZ = 23.0f;
    float minX = -23.0f;
    float minY = -23.0f;
    float minZ = -23.0f;

    if (key == GLFW_KEY_W && (action == GLFW_PRESS || action == GLFW_REPEAT)) {
        glm::vec3 newPos = cameraPos - cameraSpeed * cameraDirection;
        if (newPos.x > minX && newPos.x < maxX && newPos.y > minY && newPos.y < maxY && newPos.z > minZ && newPos.z < maxZ)
            cameraPos = newPos;
        std::cout << "W" << std::endl;
    }
    if (key == GLFW_KEY_S && (action == GLFW_PRESS || action == GLFW_REPEAT)) {
        glm::vec3 newPos = cameraPos + cameraSpeed * cameraDirection;
        if (newPos.x > minX && newPos.x < maxX && newPos.y > minY && newPos.y < maxY && newPos.z > minZ && newPos.z < maxZ)
            cameraPos = newPos;
        std::cout << "S" << std::endl;
    }
    if (key == GLFW_KEY_A && (action == GLFW_PRESS || action == GLFW_REPEAT)) {
        glm::vec3 newPos = cameraPos - cameraSpeed * cameraRight;
        if (newPos.x > minX && newPos.x < maxX && newPos.y > minY && newPos.y < maxY && newPos.z > minZ && newPos.z < maxZ)
            cameraPos = newPos;
        std::cout << "A" << std::endl;
    }
    if (key == GLFW_KEY_D && (action == GLFW_PRESS || action == GLFW_REPEAT)) {
        glm::vec3 newPos = cameraPos + cameraSpeed * cameraRight;
        if (newPos.x > minX && newPos.x < maxX && newPos.y > minY && newPos.y < maxY && newPos.z > minZ && newPos.z < maxZ)
            cameraPos = newPos;
        std::cout << "D" << std::endl;
    }

    // Podskok przy naciśnięciu klawisza spacji
    if (key == GLFW_KEY_SPACE && action == GLFW_PRESS) {
        posY = 0.0f; // Ustaw prędkość wertykalną na wartość siły podskoku
        std::cout << "SPACJA" << std::endl;
    }
}



void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods)
{
    if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS)
    {
        std::cout << "Strzał!" << std::endl;
    }
}



void cursorPositionCallback(GLFWwindow* window, double xpos, double ypos) {
    if (firstMouse) {
        lastX = xpos;
        lastY = ypos;
        firstMouse = false;
    }

    float xoffset = xpos - lastX;
    float yoffset = lastY - ypos; // reversed since y-coordinates go from bottom to top

    lastX = xpos;
    lastY = ypos;

    float sensitivity = 0.1f;
    xoffset *= sensitivity;
    yoffset *= sensitivity;

    rotationY += xoffset;
    rotationX += yoffset;

    // Constrain pitch
    if (rotationX > 89.0f)
        rotationX = 89.0f;
    if (rotationX < -89.0f)
        rotationX = -89.0f;
}

void drawCube() {
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

void drawBullet(const glm::vec3& position) {
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



int main(void) {
    GLFWwindow* window;

    if (!glfwInit())
        return -1;

    window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "OpenGL Window", NULL, NULL);
    if (!window) {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glfwSetKeyCallback(window, keyCallback);
    glfwSetCursorPosCallback(window, cursorPositionCallback);
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    glEnable(GL_DEPTH_TEST);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(75.0f, (GLfloat)SCREEN_WIDTH / (GLfloat)SCREEN_HEIGHT, 0.1f, 100.0f);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();


    glfwSetMouseButtonCallback(window, mouseButtonCallback);

    while (!glfwWindowShouldClose(window)) {
     

        
        // Kolizja z podstawą sześcianu
        if (posY < 12.0f) {
            posY += 0.7f; // Zatrzymaj postać na wysokości podstawy sześcianu
            //gravity = 0.0f; // Zresetuj grawitację
        }


        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glLoadIdentity();

        // Aktualizacja wektora cameraFront na podstawie rotationX i rotationY
        glm::vec3 front;
        front.x = cos(glm::radians(rotationY)) * cos(glm::radians(rotationX));
        front.y = sin(glm::radians(rotationX));
        front.z = sin(glm::radians(rotationY)) * cos(glm::radians(rotationX));
        cameraFront = glm::normalize(front);

        // Ustawienie kamery
        glm::mat4 view = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);
        glMultMatrixf(glm::value_ptr(view));

        // Przesunięcie postaci na nową pozycję
        glTranslatef(0.0f, posY, 0.0f);

        // Skalowanie kostki na większą - teraz o 5 razy
        glScalef(5.0f, 5.0f, 5.0f);

        drawCube();


        // Rysowanie celownika
        glMatrixMode(GL_PROJECTION);
        glPushMatrix();
        glLoadIdentity();
        gluOrtho2D(0, SCREEN_WIDTH, SCREEN_HEIGHT, 0); // Ustawienie współrzędnych ekranu
        glMatrixMode(GL_MODELVIEW);
        glPushMatrix();
        glLoadIdentity();

        // Rysowanie celownika jako prostokąta
        glBegin(GL_LINES);
        glColor3f(1.0f, 1.0f, 1.0f); // Biały kolor
        // Linie poziome
        glVertex2f(SCREEN_WIDTH / 2 - 10, SCREEN_HEIGHT / 2);
        glVertex2f(SCREEN_WIDTH / 2 + 10, SCREEN_HEIGHT / 2);
        // Linie pionowe
        glVertex2f(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 - 10);
        glVertex2f(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 + 10);
        glEnd();

        glPopMatrix();
        glMatrixMode(GL_PROJECTION);
        glPopMatrix();
        glMatrixMode(GL_MODELVIEW);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}

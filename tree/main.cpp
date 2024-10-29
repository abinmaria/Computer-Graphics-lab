#include <stdio.h>
#include <math.h>
#include <GL/gl.h>
#include <GL/glut.h>

void circle(GLfloat rx, GLfloat ry, GLfloat cx, GLfloat cy) {
    glBegin(GL_TRIANGLE_FAN);
    for (int i = 0; i <= 100; i++) {
        float angle = 2 * 3.1416 * i / 100;
        float x = rx * cosf(angle);
        float y = ry * sinf(angle);
        glVertex2f(x + cx, y + cy);
    }
    glEnd();
}

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw tree foliage with circles
    glColor3f(0.0, 1.0, 0.0); // Green color
    circle(4, 4, -10, 10); // Top circle for foliage
    circle(4, 4, -8, 7); // Right circle for foliage
    circle(4, 4, -12, 7); // Left circle for foliage

    // Draw tree trunk
    glColor3f(0.5, 0.25, 0.0); // Brown color for trunk
    glBegin(GL_QUADS);
    glVertex2f(-11.0f, 0.0f);
    glVertex2f(-9.0f, 0.0f);
    glVertex2f(-9.0f, 5.0f);
    glVertex2f(-11.0f, 5.0f);
    glEnd();

    // Draw house base
    glColor3f(1.0, 0.0, 0.0); // Light brown color for house body
    glBegin(GL_QUADS);
    glVertex2f(3.0f, 0.0f);
    glVertex2f(7.0f, 0.0f);
    glVertex2f(7.0f, 5.0f);
    glVertex2f(3.0f, 5.0f);
    glEnd();

    // Draw house roof (triangle)
    glColor3f(0.6, 0.2, 0.2); // Dark red color for roof
    glBegin(GL_TRIANGLES);
    glVertex2f(2.5f, 5.0f);
    glVertex2f(7.5f, 5.0f);
    glVertex2f(5.0f, 8.0f);
    glEnd();

    // Draw door
    glColor3f(0.3, 0.15, 0.0); // Dark brown color for door
    glBegin(GL_QUADS);
    glVertex2f(4.25f, 0.0f);
    glVertex2f(5.75f, 0.0f);
    glVertex2f(5.75f, 3.0f);
    glVertex2f(4.25f, 3.0f);
    glEnd();

    // Draw windows
    glColor3f(0.0, 0.5, 0.8); // Blue color for windows
    // Left window
    glBegin(GL_QUADS);
    glVertex2f(3.25f, 3.5f);
    glVertex2f(4.25f, 3.5f);
    glVertex2f(4.25f, 4.5f);
    glVertex2f(3.25f, 4.5f);
    glEnd();

    // Right window
    glBegin(GL_QUADS);
    glVertex2f(5.75f, 3.5f);
    glVertex2f(6.75f, 3.5f);
    glVertex2f(6.75f, 4.5f);
    glVertex2f(5.75f, 4.5f);
    glEnd();

    glFlush();
    glutSwapBuffers(); // Swap buffers for double buffering
}

void init(void) {
    glClearColor(0.0, 0.0, 0.0, 1.0); // Black background
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-20, 20, -20, 20, -1, 1); // Set projection with near and far planes
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB); // Use double buffering
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Simple House and Tree Scene");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}


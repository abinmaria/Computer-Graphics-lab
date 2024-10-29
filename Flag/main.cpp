#include <stdio.h>
#include <math.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <GL/glut.h>

void drawFlag() {
    // Set the color for the flag (green)
    glColor3f(0.0f, 1.0f, 0.0f);

    // Draw the flag as a rectangle
    glBegin(GL_QUADS);
    glVertex2f(-0.5f, 0.25f); // Top-left corner
    glVertex2f(0.5f, 0.25f);  // Top-right corner
    glVertex2f(0.5f, -0.25f);  // Bottom-right corner
    glVertex2f(-0.5f, -0.25f); // Bottom-left corner
    glEnd();

    // Set the color for the circle (red)
    glColor3f(1.0f, 0.0f, 0.0f);

    // Draw the circle
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(0.0f, 0.0f); // Center of the circle

    for (int i = 0; i <= 360; i++) {
        float angle = i * 3.14159f / 180.0f;
        glVertex2f(0.2f * cos(angle), 0.2f * sin(angle));
    }
    glEnd();

    // Set the color for the pole (brown)
    glColor3f(0.5f, 0.25f, 0.0f);

    // Draw the pole, extending downwards
    glBegin(GL_QUADS);
    glVertex2f(-0.55f, 0.25f);  // Top-left corner
    glVertex2f(-0.45f, 0.25f);  // Top-right corner
    glVertex2f(-0.45f, -0.5f);   // Bottom-right corner
    glVertex2f(-0.55f, -0.5f);   // Bottom-left corner
    glEnd();
}


void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    drawFlag();

    glFlush();
}

void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1.0f, 1.0f, -1.0f, 1.0f, -1.0f, 1.0f);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Bangladesh Flag");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMainLoop();
    return 0;
}

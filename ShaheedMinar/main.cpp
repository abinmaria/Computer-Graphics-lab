#include <stdio.h>
#include <math.h>
#include <GL/gl.h>
#include <GL/glut.h>
void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Set background color to white
    glClearColor(1.0, 1.0, 1.0, 1.0);

    // Draw the red circle (sun)
    glColor3f(1.0, 0.0, 0.0); // Red color
    float radius = 0.4;
    int num_segments = 100;
    glBegin(GL_POLYGON);
    for (int i = 0; i < num_segments; i++) {
        float theta = 2.0f * 3.1415926f * float(i) / float(num_segments); // get the current angle
        float x = radius * cos(theta); // calculate x
        float y = radius * sin(theta); // calculate y
        glVertex2f(x, y);
    }
    glEnd();

    // Draw the buildings
    glColor3f(0.5, 0.5, 0.5); // Gray color
    glBegin(GL_QUADS);

    // Leftmost building
    glVertex2f(-0.5, -0.5);
    glVertex2f(-0.4, -0.5);
    glVertex2f(-0.4, 0.3);  // Original height
    glVertex2f(-0.5, 0.3);

    // Second building (height increased to 0.6)
    glVertex2f(-0.2, -0.5);
    glVertex2f(-0.1, -0.5);
    glVertex2f(-0.1, 0.6);  // Increased height to 0.6
    glVertex2f(-0.2, 0.6);

    // Center building (height increased to 0.9)
    glVertex2f(-0.05, -0.5);
    glVertex2f(0.05, -0.5);
    glVertex2f(0.05, 0.9);  // Increased height to 0.9
    glVertex2f(-0.05, 0.9);

    // Fourth building (height increased to 0.6)
    glVertex2f(0.1, -0.5);
    glVertex2f(0.2, -0.5);
    glVertex2f(0.2, 0.6);  // Increased height to 0.6
    glVertex2f(0.1, 0.6);

    // Rightmost building
    glVertex2f(0.4, -0.5);
    glVertex2f(0.5, -0.5);
    glVertex2f(0.5, 0.3);  // Original height
    glVertex2f(0.4, 0.3);

    glEnd();

    // Draw the base
    glColor3f(0.5, 0.5, 0.5); // Gray color
    glBegin(GL_QUADS);
    glVertex2f(-0.6, -0.6);
    glVertex2f(0.6, -0.6);
    glVertex2f(0.6, -0.5);
    glVertex2f(-0.6, -0.5);
    glEnd();

    // Draw the black lines inside the center building
    glColor3f(0.0, 0.0, 0.0); // Black color
    glBegin(GL_LINES);

    float x_start = -0.04; // Starting x position of the first line inside the center building
    float x_spacing = 0.02; // Space between lines

    // Adjust the height to match the new center building height
    for (int i = 0; i < 4; i++) {
        glVertex2f(x_start + i * x_spacing, -0.5); // Bottom point of the line
        glVertex2f(x_start + i * x_spacing, 0.9);  // Top point of the line (matching the new center building height)
    }

    glEnd();

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Cityscape with Modified Building Heights");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}


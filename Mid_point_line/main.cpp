#include <stdlib.h>
#include <stdio.h>
#include <GL/gl.h>
#include <GL/glut.h>

int x0, y0, xn, yn;

void display(void) {
    int x, y, dx, dy, pk, k;
    glClear(GL_COLOR_BUFFER_BIT); // Clear the window
    glBegin(GL_POINTS);
    glVertex2i(x0, y0); // Plot the starting point
    glEnd();
    printf("Point: (%d, %d)\n", x0, y0); // Print the starting point

    dx = xn - x0;
    dy = yn - y0;
    pk = 2 * dy - dx;
    x = x0;
    y = y0;

    // Line drawing loop
    for (k = 0; k < dx - 1; ++k) {
        if (pk < 0) {
            pk = pk + 2 * dy;
        } else {
            pk = pk + 2 * dy - 2 * dx;
            ++y;
        }
        ++x;

        glBegin(GL_POINTS);
        glVertex2i(x, y);
        glEnd();

        printf("Point: (%d, %d)\n", x, y); // Print each point
    }

    glFlush();
}

void myInit(void) {
    glClearColor(0.0, 0.0, 0.0, 0.0); // Set background color to black
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 640.0, 0.0, 480.0); // Set coordinate system
}

int main(int argc, char** argv) {
    printf("Value of x0 : ");
    scanf("%d", &x0);
    printf("Value of y0 : ");
    scanf("%d", &y0);
    printf("Value of xn : ");
    scanf("%d", &xn);
    printf("Value of yn : ");
    scanf("%d", &yn);

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(100, 150);
    glutCreateWindow("Mid Point Line");
    myInit();
    glutDisplayFunc(display);
    glutMainLoop();
}

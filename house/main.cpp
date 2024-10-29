#include<windows.h>
#include <GL/glut.h>

void init(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);	// Set display window colour to white

	glMatrixMode(GL_PROJECTION);		// Set projection parameters
	gluOrtho2D(0.0, 400.0, 0.0, 400.0);
}

void drawShapes(void)
{
	glClear(GL_COLOR_BUFFER_BIT);	// Clear display window

	//Set colour to black
	glColor3f(0.0, 0.0, 0.0);
	//Adjust the point size
	glPointSize(5.0);

	//Set colour to red
	glColor3f(1.0, 0.0, 0.0);

	// Draw an outlined triangle
	glBegin(GL_LINES);

		glVertex2i(0, 200);
		glVertex2i(400, 200);

		glVertex2i(200, 400);
		glVertex2i(200,0);


	glEnd();

    glBegin(GL_TRIANGLES); //Begin triangle coordinates

	//Pentagon
	glColor3f (1.0, 0.0, 0.0);
	glVertex3f(100.0f, 0.0f, 0.0f);
	glVertex3f(300.0f, 0.0f, 0.0f);
	glVertex3f(100.0f, 200.0f, 0.0f);

	glVertex3f(100.0f, 200.0f, 0.0f);
	glVertex3f(300.0f, 0.05f, 0.0f);
	glVertex3f(300.0f, 200.0f, 0.0f);

    glColor3f (0.0, 1.0, 0.0);
	glVertex3f(300.0f, 200.0f, 0.0f);
	glVertex3f(200.0f, 300.0f, 0.0f);
	glVertex3f(100.0f, 200.0f, 0.0f);


	glEnd();//End triangle coordinates
    glBegin(GL_LINES);
        glColor3f(0.0, 0.0, 1.0);
		glVertex2i(170,0);
		glVertex2i(230,0);

		glVertex2i(230, 0);
		glVertex2i(230,100);

		glVertex2i(230,100);
		glVertex2i(170,100);

		glVertex2i(170,100);
		glVertex2i(170,0);
    glEnd();

     glBegin(GL_LINES);
        glColor3f(0.0, 0.0, 1.0);
		glVertex2i(120,130);
		glVertex2i(140,130);

		glVertex2i(140,130);
		glVertex2i(140,150);

		glVertex2i(140,150);
		glVertex2i(120,150);

		glVertex2i(120,150);
		glVertex2i(120,130);
    glEnd();

    glBegin(GL_LINES);
        glColor3f(0.0, 0.0, 1.0);
		glVertex2i(250,120);
		glVertex2i(270,120);

		glVertex2i(270,120);
		glVertex2i(270,140);

		glVertex2i(270,140);
		glVertex2i(250,140);

		glVertex2i(250,140);
		glVertex2i(250,120);
    glEnd();



	glFlush();	// Process all OpenGL routines
}

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);						// Initalise GLUT
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);	// Set display mode

	glutInitWindowPosition(50, 100);				// Set window position
	glutInitWindowSize(400, 300);					// Set window size
	glutCreateWindow("OpenGL Program");	// Create display window

	init();							// Execute initialisation procedure
	glutDisplayFunc(drawShapes);		// Send graphics to display window
	glutMainLoop();					// Display everything and wait

	return 0;
}

#include "GL/glut.h"

void cube();

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glRotatef(1, 1, 1, 0);
	cube();

	glutSwapBuffers();
}

void cube()
{
	glBegin(GL_LINE_STRIP);
	//front rectangle 
	glVertex3f(-50, -50, -50);
	glVertex3f(50, -50, -50);
	glVertex3f(50, 50, -50);
	glVertex3f(-50, 50, -50);
	glVertex3f(-50, -50, -50);
	glEnd();
	//back rectangle
	glBegin(GL_LINE_STRIP);
	glVertex3f(-50, -50, 50);
	glVertex3f(50, -50, 50);
	glVertex3f(50, 50, 50);
	glVertex3f(-50, 50, 50);
	glVertex3f(-50, -50, 50);
	glEnd();
	//lines rectangle
	glBegin(GL_LINES);
	glVertex3f(-50, -50, 50);
	glVertex3f(-50, -50, -50);
	glVertex3f(50, -50, 50);
	glVertex3f(50, -50, -50);
	glVertex3f(50, 50, 50);
	glVertex3f(50, 50, -50);
	glVertex3f(-50, 50, 50);
	glVertex3f(-50, 50, -50);
	glVertex3f(-50, -50, 50);
	glVertex3f(-50, -50, -50);
	glEnd();
}

void timer(int = 0)
{
	display();
	glutTimerFunc(10, timer, 0);
}


int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(300, 300);
	glutInitWindowPosition(200, 310);
	glutCreateWindow("Cube");
	glClearColor(0, 0, 0, 1.0f);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-100, 100, -100, 100, -100, 100);
	glViewport(-12.0, -12.0, 12.0, 12.0);
	glutDisplayFunc(display);
	timer();

	glutMainLoop();
}
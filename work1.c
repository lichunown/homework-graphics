#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

#define RANDOM_MNUM (10000)

void display();

float m_random(){
	return (float)(rand()%RANDOM_MNUM)/RANDOM_MNUM;
}
float m_randfloat(float min, float max){
	float t = m_random();
	// printf("y:%f  max-min:%f  r:%f\n",t,(max - min),min + t*(max - min));
	return min + t*(max - min);
}
int main(int argc, char* argv[]){
	srand((int)time(0));
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(800, 800);
	glViewport(0,0,800,800);
	gluOrtho2D(0,800,0,800);  
	glutCreateWindow("work1");	
	glClearColor(0, 0, 0, 0);
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}

void display(){
	glClear(GL_COLOR_BUFFER_BIT);
	// for(int i=0;i<20;i++){printf("%f\n",m_randfloat(-1,-0.6));}
	glBegin(GL_POINTS);//draw point
	glColor3f(1., 1., 1.);
	for(int i = 0; i<100; i++){
		glColor3f(m_random(), m_random(), m_random());
		glVertex2f(m_randfloat(-1,-0.3),m_randfloat(0.5,1));
	}
	glEnd();
	glBegin(GL_LINES);//draw line
	for(int i = 0; i<10; i++){
		// glColor3f(m_random(), m_random(), m_random());
		glColor3f(m_random(), m_random(), m_random());
		glVertex2f(m_randfloat(-1,-0.3),m_randfloat(0,0.5));
		glVertex2f(m_randfloat(-1,-0.3),m_randfloat(0,0.5));
	}
	glEnd();
	glBegin(GL_POLYGON);//draw polygon
	for(int i = 0; i<5; i++){
		glColor3f(m_random(), m_random(), m_random());
		glVertex2f(m_randfloat(-1,-0.3),m_randfloat(-0.5,0));
	}
	glEnd();
	glBegin(GL_TRIANGLES);//draw polygon
	for(int i = 0; i<2; i++){
		glColor3f(m_random(), m_random(), m_random());
		glVertex2f(m_randfloat(-1,-0.3),m_randfloat(-1,-0.5));
		glVertex2f(m_randfloat(-1,-0.3),m_randfloat(-1,-0.5));
		glVertex2f(m_randfloat(-1,-0.3),m_randfloat(-1,-0.5));
	}
	glEnd();
	glBegin(GL_LINE_STRIP);//draw polygon
	for(int i = 0; i<10; i++){
		glColor3f(m_random(), m_random(), m_random());
		glVertex2f(m_randfloat(-0.3,0.3),m_randfloat(0,0.5));
	}
	glEnd();
	glBegin(GL_QUADS);//draw polygon
	for(int i = 0; i<1; i++){
		glColor3f(m_random(), m_random(), m_random());
		glVertex2f(m_randfloat(-0.3,0.3),m_randfloat(-0.5,0));
		glVertex2f(m_randfloat(-0.3,0.3),m_randfloat(-0.5,0));
		glVertex2f(m_randfloat(-0.3,0.3),m_randfloat(-0.5,0));
		glVertex2f(m_randfloat(-0.3,0.3),m_randfloat(-0.5,0));
	}
	glEnd();
	glBegin(GL_TRIANGLE_STRIP);//draw polygon
	for(int i = 0; i<5; i++){
		glColor3f(m_random(), m_random(), m_random());
		glVertex2f(m_randfloat(-0.3,0.3),m_randfloat(-1,-0.5));
	}
	glEnd();
	glBegin(GL_LINE_LOOP);//draw polygon
	for(int i = 0; i<10; i++){
		glColor3f(m_random(), m_random(), m_random());
		glVertex2f(m_randfloat(0.3,1),m_randfloat(0,0.5));
	}
	glEnd();
	glBegin(GL_QUAD_STRIP);//draw polygon
	for(int i = 0; i<8; i++){
		glColor3f(m_random(), m_random(), m_random());
		glVertex2f(m_randfloat(0.3,1),m_randfloat(-0.5,0));
	}
	glEnd();
	glBegin(GL_TRIANGLE_FAN);//draw polygon
	for(int i = 0; i<5; i++){
		glColor3f(m_random(), m_random(), m_random());
		glVertex2f(m_randfloat(0.3,1),m_randfloat(-1,-0.5));
	}
	glEnd();
	glFlush();
}
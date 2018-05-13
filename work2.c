#include <stdio.h>
#include <math.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

typedef struct M_point{
	int x, y;
} M_point;

typedef struct M_color{
	float r,g,b;
}M_color;

void display();
// void m_plotline(M_point a, M_point b, M_color color);
void m_plotline_f(M_point a, M_point b, M_color color);
int main(int argc, char* argv[]){
	glutInit(&argc, argv);
	// glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowPosition(0, 0);
	glMatrixMode(GL_PROJECTION);  
	// glLoadIdentity();  
	gluOrtho2D(0.0, 800.0, 0.0, 800.0);  
	glutInitWindowSize(800, 800);
	glutCreateWindow("work2");	
	glClearColor(0, 0, 0, 0);
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
// void m_plotline(M_point pa, M_point pb, M_color color){
// 	glBegin(GL_POINTS);
// 	glColor3f(color.r, color.g, color.b);
// 	int a, b, delta1, delta2, d, x, y;
// 	a = pa.y - pb.y;
// 	b = pb.x - pa.x;
// 	d = a * 2 + b;
// 	delta1 = 2 * a;
// 	delta2 = 2 * (a + b);
// 	x = pa.x;
// 	y = pa.y;
// 	glVertex2i(x,y);
// 	while(x < pb.x){
// 		if(d < 0){
// 			x++; y++;
// 			d += delta2;
// 		}else{
// 			x++;
// 			d += delta1;
// 		}
// 		printf("x:%d   y:%d\n",x,y);
// 		glVertex2i(x,y);
// 	}
// 	glEnd();
// }
float m_abs(float n){
	return (n > 0) ? n : -1 * n;
}
void m_plotline_f(M_point pa, M_point pb, M_color color){
	glBegin(GL_POINTS);
	glColor3f(color.r, color.g, color.b);
	float a, b, delta1, delta2, d, x, y;
	// printf("%f, %f\n\n",(float)(pb.y-pa.y),m_abs((float)(pb.y-pa.y)/(pb.x-pa.x)));
	if(m_abs((float)(pb.y-pa.y)/(pb.x-pa.x)) <= 1){
		if(pb.y-pa.y > 0){//1
			printf("type1:\n");
			a = (pa.y - pb.y)/800.0;
			b = (pb.x - pa.x)/800.0;
			d = a * 2 + b;
			delta1 = 2 * a;
			delta2 = 2 * (a + b);
			x = (float)pa.x/800;
			y = (float)pa.y/800;
			glVertex2f(x,y);
			while(x < pb.x/800.0){
				// printf("d: %f\n",d);
				if(d < 0){
					x += 0.01; y += 0.01;
					d += delta2;
				}else{
					x += 0.01;
					d += delta1;
				}
				// printf("x:%f   y:%f\n",x,y);
				glVertex2f(x,y);
			}
			glEnd();
		}else{//8
			printf("type8:\n");
			a = (pa.y - pb.y)/800.0;
			b = (pb.x - pa.x)/800.0;
			d = a * 2 - b;
			delta1 = 2 * a;
			delta2 = 2 * (a - b);
			x = (float)pa.x/800;
			y = (float)pa.y/800;
			glVertex2f(x,y);
			while(x < pb.x/800.0){
				// printf("x:%f   y:%f   d=%f\n",x,y,d);
				if(d > 0){
					x += 0.01; y -= 0.01;
					d += delta2;
				}else{
					x += 0.01;
					d += delta1;
				}
				// printf("x:%f   y:%f\n",x,y);
				glVertex2f(x,y);
			}
			glEnd();
		}
	}else{
		if(pb.y-pa.y > 0){//2
			printf("type2:\n");
			a = (pa.y - pb.y)/800.0;
			b = (pb.x - pa.x)/800.0;
			d = a * 2 + b;
			delta1 = 2 * b;
			delta2 = 2 * (a + b);
			x = (float)pa.x/800;
			y = (float)pa.y/800;
			glVertex2f(x,y);
			while(x < pb.x/800.0){
				// if(x < pb.x/800.0 )break;
				// printf("x: %f  pb.x:%f \n",x,pb.x);
				if(d > 0){
					y += 0.01; x += 0.01;
					d += delta2;
				}else{
					y += 0.01;
					d += delta1;
				}
				// printf("x:%f   y:%f\n",x,y);
				glVertex2f(x,y);
			}
			glEnd();
		}else{//7
			printf("type7:\n");
			a = -(pa.y - pb.y)/800.0;
			b = (pb.x - pa.x)/800.0;
			d = a * 2 + b;
			delta1 = 2 * b;
			delta2 = 2 * (a + b);
			x = (float)pa.x/800;
			y = (float)pa.y/800;
			glVertex2f(x,y);
			while(y >= pb.y/800.0){
				// printf("d: %f\n",d);
				if(d > 0){
					y -= 0.01; x += 0.01;
					d += delta2;
				}else{
					y -= 0.01;
					d += delta1;
				}
				// printf("x:%f   y:%f\n",x,y);
				glVertex2f(x,y);
			}
			glEnd();
		}
	}
	// a = (pa.y - pb.y)/800.0;
	// b = (pb.x - pa.x)/800.0;
	// d = a * 2 + b;
	// delta1 = 2 * a;
	// delta2 = 2 * (a + b);
	// x = (float)pa.x/800;
	// y = (float)pa.y/800;
	// glVertex2f(x,y);
	// while(x < pb.x){
	// 	if(d < 0){
	// 		x += 0.01; y += 0.01;
	// 		d += delta2;
	// 	}else{
	// 		x += 0.01;
	// 		d += delta1;
	// 	}
	// 	// printf("x:%f   y:%f\n",x,y);
	// 	glVertex2f(x,y);
	// }
	// glEnd();
}
void m_plotline_o(int x1,int y1,int x2,int y2,M_color color){
	M_point a,b;
	if(x1 > x2){
		a.x = x2;
		a.y = y2;
		b.x = x1;
		b.y = y1;
	}else{
		a.x = x1;
		a.y = y1;
		b.x = x2;
		b.y = y2;
	}
	printf("plot a(%d,%d) b(%d,%d)\n",a.x,a.y,b.x,b.y);
	m_plotline_f(a,b,color);
}
void display(){
	glClear(GL_COLOR_BUFFER_BIT);
	M_color color={1,1,1};
	M_point p = {100,200};
	m_plotline_o(p.x, p.y, 400, 800,color);
	m_plotline_o(p.x, p.y, 800, 800,color);
	m_plotline_o(p.x, p.y, 800, 400,color);
	m_plotline_o(p.x, p.y, 800, 0,color);
	m_plotline_o(p.x, p.y, 800, -400,color);
	m_plotline_o(p.x, p.y, 800, -800,color);
	m_plotline_o(p.x, p.y, 400, -800,color);
	m_plotline_o(p.x, p.y, 0, -800,color);
	m_plotline_o(p.x, p.y, -400, -800,color);
	m_plotline_o(p.x, p.y, -800, -800,color);
	m_plotline_o(p.x, p.y, -800, -400,color);
	m_plotline_o(p.x, p.y, -800, 0,color);
	m_plotline_o(p.x, p.y, -800, 400,color);
	m_plotline_o(p.x, p.y, -800, 800,color);
	m_plotline_o(p.x, p.y, -400, 800,color);
	m_plotline_o(p.x, p.y, 0, 800,color);
	glFlush();
}
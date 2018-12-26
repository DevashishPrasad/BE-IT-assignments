#include <GL/freeglut.h>
#include <GL/gl.h>
#include <iostream>
#include <cstdlib>

using namespace std;

typedef struct Point
{
	int x;
	int y;
}Point;

void init()
{
	// making background color black as first  
    // 3 arguments all are 0.0 
    glClearColor(0.0, 0.0, 0.0, 1.0); 
      
    // making picture color white (in RGB mode),
    glColor3f(1.0, 1.0, 1.0); 
      
    // breadth of picture boundary is 1 pixel 
    glPointSize(3.0);  

	// coordinate system
	glMatrixMode(GL_PROJECTION);

	// setting window dimension in X- and Y- direction 
	gluOrtho2D(0.0, 1200.0, 0.0, 800.0);
}

// Custom Function for drawing a line
void drawLine(int x1, int y1, int x2, int y2)
{	
	glLineWidth(2.5); 
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_LINES);
		glVertex3f(x1, y1, 0.0);
		glVertex3f(x2, y2, 0);
	glEnd(); 
}

void drawShape()
{
	// Getting max window sizes
	Point Max;
	Max.x = glutGet(GLUT_WINDOW_WIDTH);
	Max.y = glutGet(GLUT_WINDOW_HEIGHT);
	
	// Setting the origin point
	Point Origin;
	Origin.x = 0;
	Origin.y = 0;
	
	// Setting fake origin point
	Point FakeOrigin;
	FakeOrigin.x = Max.x/2;
	FakeOrigin.y = Max.y/2;
	
	// UPPER SHAPE
	// setting dimensions of UPPER Shape
	int Ulen = 250;
	int Uwid = 200;
	
	// set adjust for upper shape
	int upadjust = 50;
	// Setting Fake Center
	Point FakeCenterU;
	FakeCenterU.x = FakeOrigin.x + 250/2 + upadjust;
	FakeCenterU.y = FakeOrigin.y + 200/2 + upadjust;
		
	// drawing the lines
	// UPPER SHAPE Screen Shape
	drawLine(FakeOrigin.x + upadjust, FakeOrigin.y + upadjust, FakeOrigin.x + upadjust , FakeOrigin.y + Uwid +upadjust);
	drawLine(FakeOrigin.x + upadjust, FakeOrigin.y + upadjust, FakeOrigin.x + Ulen + upadjust, FakeOrigin.y + upadjust);
	drawLine(FakeOrigin.x + upadjust, FakeOrigin.y + Uwid + upadjust, FakeOrigin.x + Ulen + upadjust, FakeOrigin.y + Uwid + upadjust);
	drawLine(FakeOrigin.x + Ulen + upadjust, FakeOrigin.y + upadjust, FakeOrigin.x + Ulen + upadjust, FakeOrigin.y + Uwid + upadjust);
	// UPPER SHAPE Outer Shape
	drawLine(FakeCenterU.x, FakeOrigin.y + upadjust, FakeOrigin.x + upadjust, FakeCenterU.y);
	drawLine(FakeOrigin.x + upadjust, FakeCenterU.y, FakeCenterU.x , FakeOrigin.y + Uwid + upadjust);
	drawLine(FakeCenterU.x, FakeOrigin.y + Uwid + upadjust, FakeOrigin.x + Ulen + upadjust, FakeCenterU.y);
	drawLine(FakeOrigin.x + Ulen + upadjust, FakeCenterU.y, FakeCenterU.x, FakeOrigin.y + upadjust);  
	// UPPER SHAPE Inner Shape
	drawLine((FakeOrigin.x + Ulen + upadjust)/4, (FakeOrigin.y + Uwid + upadjust)/4, (FakeOrigin.x + Ulen + upadjust)/4 , FakeOrigin.y + Uwid + upadjust - (FakeOrigin.y + Uwid + upadjust)/4);
	//drawLine(Max.x/4, Max.y/4, Max.x - Max.x/4 , Max.y/4);
	//drawLine(Max.x - Max.x/4, Max.y/4, Max.x - Max.x/4 , Max.y - Max.y/4);
	//drawLine(Max.x/4 , Max.y - Max.y/4, Max.x - Max.x/4 , Max.y - Max.y/4);
	
}
void start()
{
	init();

	drawShape();
	
	glFlush();
}

int main(int argc, char **argv)
{
	// OpenGL Glut Init
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

	// Set the window size
    glutInitWindowSize(1200, 800);
	glutInitWindowPosition(0, 0);

	int winid = glutCreateWindow("OpenGL - Creating a line");
	
	// Start with the program
    glutDisplayFunc(start);

    glutMainLoop();

   	return 0;
}

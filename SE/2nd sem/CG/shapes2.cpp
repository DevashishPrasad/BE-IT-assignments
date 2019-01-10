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
	// setting dimensions of both Shapes
	int Ulen = 250;
	int Uwid = 200;
	
	
	
	//------------- UPPER SHAPE -------------
	// set adjust for upper shape
	int upadjust = 50;
	
	// Setting fake origin point
	Point FakeOrigin;
	FakeOrigin.x = (Max.x/2) + upadjust;
	FakeOrigin.y = (Max.y/2) + upadjust;
	
	// Setting Fake Center
	Point FakeCenterU;
	FakeCenterU.x = FakeOrigin.x + Ulen/2;
	FakeCenterU.y = FakeOrigin.y + Uwid/2;
		
	// drawing the lines
	// UPPER SHAPE Screen Shape
	drawLine(FakeOrigin.x, FakeOrigin.y, FakeOrigin.x, FakeOrigin.y + Uwid);
	drawLine(FakeOrigin.x, FakeOrigin.y, FakeOrigin.x + Ulen, FakeOrigin.y);
	drawLine(FakeOrigin.x, FakeOrigin.y + Uwid, FakeOrigin.x + Ulen, FakeOrigin.y + Uwid);
	drawLine(FakeOrigin.x + Ulen, FakeOrigin.y, FakeOrigin.x + Ulen, FakeOrigin.y + Uwid);
	// UPPER SHAPE Outer Shape
	drawLine(FakeCenterU.x, FakeOrigin.y, FakeOrigin.x, FakeCenterU.y);
	drawLine(FakeOrigin.x, FakeCenterU.y, FakeCenterU.x , FakeOrigin.y + Uwid);
	drawLine(FakeCenterU.x, FakeOrigin.y + Uwid, FakeOrigin.x + Ulen, FakeCenterU.y);
	drawLine(FakeOrigin.x + Ulen, FakeCenterU.y, FakeCenterU.x, FakeOrigin.y);  
	// UPPER SHAPE Inner Shape old method
	//drawLine((FakeOrigin.x + Ulen + upadjust)/4, (FakeOrigin.y + Uwid + upadjust)/4, (FakeOrigin.x + Ulen + upadjust)/4 , FakeOrigin.y + Uwid + upadjust - (FakeOrigin.y + Uwid + upadjust)/4);
	//drawLine(Max.x/4, Max.y/4, Max.x - Max.x/4 , Max.y/4);
	//drawLine(Max.x - Max.x/4, Max.y/4, Max.x - Max.x/4 , Max.y - Max.y/4);
	//drawLine(Max.x/4 , Max.y - Max.y/4, Max.x - Max.x/4 , Max.y - Max.y/4);
	// UPPER SHAPE Inner Shape new method
	drawLine(FakeOrigin.x + (FakeCenterU.x - FakeOrigin.x)/2, FakeOrigin.y + (FakeCenterU.y - FakeOrigin.y)/2, FakeOrigin.x + (FakeCenterU.x - FakeOrigin.x)/2, FakeCenterU.y + (FakeCenterU.y - FakeOrigin.y)/2);
	drawLine(FakeOrigin.x + (FakeCenterU.x - FakeOrigin.x)/2, FakeCenterU.y + (FakeCenterU.y - FakeOrigin.y)/2, FakeCenterU.x + (FakeCenterU.x - FakeOrigin.x)/2, FakeCenterU.y + (FakeCenterU.y - FakeOrigin.y)/2);
	drawLine(FakeCenterU.x + (FakeCenterU.x - FakeOrigin.x)/2, FakeCenterU.y + (FakeCenterU.y - FakeOrigin.y)/2, FakeCenterU.x + (FakeCenterU.x - FakeOrigin.x)/2,  FakeOrigin.y + (FakeCenterU.y - FakeOrigin.y)/2);
	drawLine(FakeCenterU.x + (FakeCenterU.x - FakeOrigin.x)/2,  FakeOrigin.y + (FakeCenterU.y - FakeOrigin.y)/2, FakeOrigin.x + (FakeCenterU.x - FakeOrigin.x)/2, FakeOrigin.y + (FakeCenterU.y - FakeOrigin.y)/2);
	
	
	//------------ LOWER SHAPE -------------
	// set adjust for lower shape
	int downadjust = -300;
	
	// Setting fake origin point 2
	Point FakeOrigin2;
	FakeOrigin2.x = (Max.x/2) + downadjust;
	FakeOrigin2.y = (Max.y/2) + downadjust;
	
	// LOWER SHAPE
	// Setting Fake Center
	Point FakeCenterD;
	FakeCenterD.x = FakeOrigin2.x + Ulen/2;
	FakeCenterD.y = FakeOrigin2.y + Uwid/2;
		
	// drawing the lines
	// LOWER SHAPE Screen Shape
	drawLine(FakeOrigin2.x, FakeOrigin2.y, FakeOrigin2.x, FakeOrigin2.y + Uwid);
	drawLine(FakeOrigin2.x, FakeOrigin2.y, FakeOrigin2.x + Ulen, FakeOrigin2.y);
	drawLine(FakeOrigin2.x, FakeOrigin2.y + Uwid, FakeOrigin2.x + Ulen, FakeOrigin2.y + Uwid);
	drawLine(FakeOrigin2.x + Ulen, FakeOrigin2.y, FakeOrigin2.x + Ulen, FakeOrigin2.y + Uwid);
	// LOWER SHAPE Outer Shape
	drawLine(FakeCenterD.x, FakeOrigin2.y, FakeOrigin2.x, FakeCenterD.y);
	drawLine(FakeOrigin2.x, FakeCenterD.y, FakeCenterD.x , FakeOrigin2.y + Uwid);
	drawLine(FakeCenterD.x, FakeOrigin2.y + Uwid, FakeOrigin2.x + Ulen, FakeCenterD.y);
	drawLine(FakeOrigin2.x + Ulen, FakeCenterD.y, FakeCenterD.x, FakeOrigin2.y);  
	// LOWER SHAPE Inner Shape old method
	//drawLine((FakeOrigin.x + Ulen + upadjust)/4, (FakeOrigin.y + Uwid + upadjust)/4, (FakeOrigin.x + Ulen + upadjust)/4 , FakeOrigin.y + Uwid + upadjust - (FakeOrigin.y + Uwid + upadjust)/4);
	//drawLine(Max.x/4, Max.y/4, Max.x - Max.x/4 , Max.y/4);
	//drawLine(Max.x - Max.x/4, Max.y/4, Max.x - Max.x/4 , Max.y - Max.y/4);
	//drawLine(Max.x/4 , Max.y - Max.y/4, Max.x - Max.x/4 , Max.y - Max.y/4);
	// LOWER SHAPE Inner Shape new method
	drawLine(FakeOrigin2.x + (FakeCenterD.x - FakeOrigin2.x)/2, FakeOrigin2.y + (FakeCenterD.y - FakeOrigin2.y)/2, FakeOrigin2.x + (FakeCenterD.x - FakeOrigin2.x)/2, FakeCenterD.y + (FakeCenterD.y - FakeOrigin2.y)/2);
	drawLine(FakeOrigin2.x + (FakeCenterD.x - FakeOrigin2.x)/2, FakeCenterD.y + (FakeCenterD.y - FakeOrigin2.y)/2, FakeCenterD.x + (FakeCenterD.x - FakeOrigin2.x)/2, FakeCenterD.y + (FakeCenterD.y - FakeOrigin2.y)/2);
	drawLine(FakeCenterD.x + (FakeCenterD.x - FakeOrigin2.x)/2, FakeCenterD.y + (FakeCenterD.y - FakeOrigin2.y)/2, FakeCenterD.x + (FakeCenterD.x - FakeOrigin2.x)/2,  FakeOrigin2.y + (FakeCenterD.y - FakeOrigin2.y)/2);
	drawLine(FakeCenterD.x + (FakeCenterD.x - FakeOrigin2.x)/2,  FakeOrigin2.y + (FakeCenterD.y - FakeOrigin2.y)/2, FakeOrigin2.x + (FakeCenterD.x - FakeOrigin2.x)/2, FakeOrigin2.y + (FakeCenterD.y - FakeOrigin2.y)/2);
	
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

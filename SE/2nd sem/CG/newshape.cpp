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

int rx1, ry1, rx2, ry2, rx3, ry3, rx4, ry4;

void init()
{
	// making background color black as first  
    // 3 arguments all are 0.0 
    glClearColor(1.0, 1.0, 1.0, 1.0); 
      
    // making picture color white (in RGB mode),
    glColor3f(0.5, 0.5, 0.5); 
      
    // breadth of picture boundary is 1 pixel 
    glPointSize(2.5);  

	// coordinate system
	glMatrixMode(GL_PROJECTION);

	// setting window dimension in X- and Y- direction 
	gluOrtho2D(0.0, 1200.0, 0.0, 800.0);
}

// Custom Function for drawing a line
void drawLine(int x1, int y1, int x2, int y2)
{	
	glLineWidth(2.5); 
	glColor3f(0.0, 0.0, 1.0);
	glBegin(GL_LINES);
		glVertex3f(x1, y1, 0.0);
		glVertex3f(x2, y2, 0);
	glEnd(); 
}

void drawShape()
{
	// Getting max window sizes
	Point Max, SMax;
	SMax.x = glutGet(GLUT_WINDOW_WIDTH);
	SMax.y = glutGet(GLUT_WINDOW_HEIGHT);
	
	Max.x = rx3;
	Max.y = ry3;
	
	// Getting center of axes
	Point AxisCenter;
	AxisCenter.x = Max.x/2;
	AxisCenter.y = Max.y/2;
	
	// Setting the origin point
	Point Origin;
	Origin.x = rx1;
	Origin.y = ry1;
	
	// drawing the lines
	// Rectangle Shape
	drawLine(Origin.x, Origin.y, Max.x, Origin.y);
	drawLine(Origin.x, Origin.y, Origin.x, Max.y);
	drawLine(Origin.x, Max.y, Max.x, Max.y);
	drawLine(Max.x, Origin.y, Max.x, Max.y);
	// Quadrant Lines
	drawLine(SMax.x, SMax.y/2, 0, SMax.y/2);
	drawLine(SMax.x/2, 0, SMax.x/2, SMax.y);
	// Outer Shape
	drawLine(AxisCenter.x, Origin.y, Origin.x, AxisCenter.y);
	drawLine(Origin.x, AxisCenter.y, AxisCenter.x, Max.y);
	drawLine(AxisCenter.x, Max.y, Max.x, AxisCenter.y);
	drawLine(Max.x, AxisCenter.y, AxisCenter.x, Origin.y);  
	//// Inner Shape old method
	//drawLine(Max.x/4, Max.y/4, Max.x/4 , Max.y - Max.y/4);
	//drawLine(Max.x/4, Max.y/4, Max.x - Max.x/4 , Max.y/4);
	//drawLine(Max.x - Max.x/4, Max.y/4, Max.x - Max.x/4 , Max.y - Max.y/4);
	//drawLine(Max.x/4 , Max.y - Max.y/4, Max.x - Max.x/4 , Max.y - Max.y/4);
	
	//Easy way Inner shape using mid points
	//drawLine(AxisCenter.x/2, AxisCenter.y/2, AxisCenter.x/2, (Max.y + AxisCenter.y)/2);
	//drawLine(AxisCenter.x/2, (Max.y + AxisCenter.y)/2, (AxisCenter.x + Max.x)/2,  (Max.y + AxisCenter.y)/2);
	//drawLine((AxisCenter.x + Max.x)/2,  (Max.y + AxisCenter.y)/2, (AxisCenter.x + Max.x)/2, AxisCenter.y/2);
	//drawLine((AxisCenter.x + Max.x)/2, AxisCenter.y/2, AxisCenter.x/2, AxisCenter.y/2);
	
}
void start()
{
	init();
	drawShape();
	glFlush();
}

int main(int argc, char **argv)
{
	cout<<"\n\n Please enter the coordinates for a rectangle or square - ";
	cout<<"\n Point 1 (x,y) - ";
	cin>>rx1>>ry1;
	cout<<"\n Point 2 (x,y) - ";
	cin>>rx2>>ry2;
	cout<<"\n Point 3 (x,y) - ";
	cin>>rx3>>ry3;
	cout<<"\n Point 4 (x,y) - ";
	cin>>rx4>>ry4;	
	
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

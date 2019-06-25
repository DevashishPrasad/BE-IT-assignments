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
	gluOrtho2D(0.0, 1024.0, 0.0, 750.0);
}

// Custom Function for drawing a line
void drawLine(int x1, int y1, int x2, int y2)
{	
	glLineWidth(2.5); 
	glColor3f(0.0, 0.0, 1.0);
	glBegin(GL_LINES);
		glVertex3f(x1, y1, 0);
		glVertex3f(x2, y2, 0);
	glEnd(); 
}

/*void drawLine(int x1, int y1, int x2, int y2)
{
	//DDA Function for line generation 
	// calculate dx & dy
    int dx = abs(x1 - x2); 
    int dy = abs(y1 - y2); 
  
    // calculate steps required for generating pixels 
    int steps = dx > dy ? dx : dy; 
  
    // calculate increment in x & y for each steps 
    float Xinc = dx / (float) steps; 
    float Yinc = dy / (float) steps; 
  
    // Put pixel for each step 
    float X = x1; 
    float Y = y1; 

	glBegin(GL_POINTS);

    for (int i = 0; i <= steps; i++) 
    { 
        glVertex2i(X,Y);
		X += Xinc;       // increment in x at each step 
        Y += Yinc;       // increment in y at each step 
        //delay(100);        
    }
    
    glEnd();
}*/

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
	AxisCenter.x = (Max.x - rx1)/2 + rx1;
	AxisCenter.y = (Max.y - ry1)/2 + ry1;
	
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
	drawLine(0, SMax.y/2, SMax.x, SMax.y/2);
	drawLine(SMax.x/2, 0, SMax.x/2, SMax.y);
	// Outer Shape
	drawLine(Origin.x, AxisCenter.y, AxisCenter.x, Origin.y);
	drawLine(Origin.x, AxisCenter.y, AxisCenter.x, Max.y);
	drawLine(AxisCenter.x, Max.y, Max.x, AxisCenter.y);
	drawLine(Max.x, AxisCenter.y, AxisCenter.x, Origin.y);  
	//// Inner Shape old method
	//drawLine(Max.x/4, Max.y/4, Max.x/4 , Max.y - Max.y/4);
	//drawLine(Max.x/4, Max.y/4, Max.x - Max.x/4 , Max.y/4);
	//drawLine(Max.x - Max.x/4, Max.y/4, Max.x - Max.x/4 , Max.y - Max.y/4);
	//drawLine(Max.x/4 , Max.y - Max.y/4, Max.x - Max.x/4 , Max.y - Max.y/4);
	
	//Easy way Inner shape using mid points
	drawLine((AxisCenter.x - Origin.x)/2 + Origin.x, (AxisCenter.y - Origin.y)/2 + Origin.y, (AxisCenter.x - Origin.x)/2 + Origin.x, (AxisCenter.y - Origin.y)/2 + AxisCenter.y);
	drawLine((AxisCenter.x - Origin.x)/2 + Origin.x, (AxisCenter.y - Origin.y)/2 + AxisCenter.y, (AxisCenter.x - Origin.x)/2 + AxisCenter.x, (AxisCenter.y - Origin.y)/2 + AxisCenter.y);
	drawLine((AxisCenter.x - Origin.x)/2 + AxisCenter.x, (AxisCenter.y - Origin.y)/2 + AxisCenter.y, (AxisCenter.x - Origin.x)/2 + AxisCenter.x,  (AxisCenter.y - Origin.y)/2 + Origin.y);
	drawLine((AxisCenter.x - Origin.x)/2 + AxisCenter.x,  (AxisCenter.y - Origin.y)/2 + Origin.y, (AxisCenter.x - Origin.x)/2 + Origin.x, (AxisCenter.y - Origin.y)/2 + Origin.y);
	
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
    	glutInitWindowSize(1024, 750);
	glutInitWindowPosition(0, 0);

	int winid = glutCreateWindow("OpenGL - Creating a line");
	
	// Start with the program
    	glutDisplayFunc(start);

    	glutMainLoop();

   	return 0;
}

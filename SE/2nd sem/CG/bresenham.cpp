#include <GL/freeglut.h>
#include <GL/gl.h>
#include <iostream>
#include <cstdlib>
#include <math.h>

using namespace std;

typedef struct Point
{
	int x;
	int y;
}Point;

int radius;

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
	gluOrtho2D(0.0, 1024.0, 0.0, 764.0);
}

/*void drawLine(int x1, int y1, int x2, int y2)
{
	//DDA Function for line generation 
	// calculate dx & dy
    int dx = abs(x1 - x2); 
    int dy = abs(y1 - y2); 
  
	glColor3f(1.0, 0.0, 0.0);
    
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
		X += Xinc;        // increment in x at each step 
        Y += Yinc;        // increment in y at each step 
    }

  	glEnd(); 
}
*/

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

// Bresenham Circle algorithm
void drawCircle(int r, int cx, int cy)
{
	Point p;
	
	p.x = 0;
	p.y = r;
	
	glColor3f(0.0, 1.0, 0.0);
	
	glBegin(GL_POINTS);
	
	// Center
	glVertex2i(cx,cy);
	// Starting Point
	glVertex2i(p.x+cx , p.y+cy);

	// Initialize decision parameter	
	float Pi = 3 - 2*r;
	
	while(p.x <= p.y)
	{
		if(Pi < 0)
		{
			p.x++;
			Pi += 4*p.x + 6;
		}
		else
		{
			p.x++;
			p.y--;
			Pi += 4*(p.x-p.y) + 16;
		}
		
		glVertex2i(cx+p.x, cy+p.y);//First Octant
		glVertex2i(cx+p.y, cy+p.x);//Second Octant
		glVertex2i(cx+p.y, cy-p.x);//Third Octant
		glVertex2i(cx+p.x, cy-p.y);//Fourth Octant
		glVertex2i(cx-p.x, cy-p.y);//Fifth Octant
		glVertex2i(cx-p.y, cy-p.x);//Sixth Octant
		glVertex2i(cx-p.y, cy+p.x);//Seventh Octant
		glVertex2i(cx-p.x, cy+p.y);//Eighth Octant
	}
	
	glEnd();
}

void start()
{
	init();

	// Getting max window sizes
	Point Max;
	Max.x = glutGet(GLUT_WINDOW_WIDTH);
	Max.y = glutGet(GLUT_WINDOW_HEIGHT);
	
	// Setting fake origin point
	Point Origin;
	Origin.x = Max.x/2;
	Origin.y = Max.y/2;

	// Draw Outer Circle
	drawCircle(radius,Origin.x,Origin.y);			
	// Draw Inner Circle
	drawCircle(radius/2,Origin.x,Origin.y);			
	
	// Calculate The X
	int x = (radius*radius) - ((radius/2)*(radius/2));
	x = sqrt(x);
	
	// Draw Triangle
	drawLine(Origin.x-x,Origin.y-radius/2,Origin.x+x,Origin.y-radius/2);
	drawLine(Origin.x-x,Origin.y-radius/2,Origin.x,Origin.y+radius);
	drawLine(Origin.x,Origin.y+radius,Origin.x+x,Origin.y-radius/2);

    glFlush(); 
}
int main(int argc, char **argv)
{
	cout<<"\n Enter the Radius of Outer Circle ";
	cin>>radius;

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    	glutInitWindowSize(1024, 764);
	glutInitWindowPosition(0, 0);

	int winid = glutCreateWindow("OpenGL - Creating a line");

    	glutDisplayFunc(start);
 	glutMainLoop();
 
   	return 0;
}

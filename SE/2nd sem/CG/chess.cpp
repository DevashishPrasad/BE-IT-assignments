#include <GL/freeglut.h>
#include <GL/gl.h>
#include <iostream>
#include <cstdlib>
#include <math.h>

#define PI 3.14159265

using namespace std;

struct Color {
	float r;
	float g;
	float b;
};

typedef struct Point
{
	int x;
	int y;
}Point;

Point d1,d2;

void init()
{
	// making background color black as first  
    // 3 arguments all are 0.0 
    glClearColor(0.0, 0.0, 0.0, 1.0); 
      
    // making picture color white (in RGB mode),
    glColor3f(1.0, 1.0, 1.0); 
      
    // breadth of picture boundary is 1 pixel 
    //glPointSize(2.0);  

	// // coordinate system
	// glMatrixMode(GL_PROJECTION);

	// setting window dimension in X- and Y- direction 
	gluOrtho2D(0.0, 1200.0, 0.0, 800.0);
}

// Custom Function for drawing a line using DDA line generation algorithm
void drawLine(int X0, int Y0, int X1, int Y1)
{
    
	//DDA Function for line generation 
	// calculate dx & dy
    float dx = X1 - X0; 
    float dy = Y1 - Y0; 
  
    // calculate steps required for generating pixels 
    float steps = fabs(dx) > fabs(dy) ? fabs(dx) : fabs(dy); 
  
    // calculate increment in x & y for each steps 
    float Xinc = dx / (float) steps; 
    float Yinc = dy / (float) steps; 
  
    // Put pixel for each step 
    float X = X0; 
    float Y = Y0; 
    glBegin(GL_POINTS);

    for (int i = 0; i <= steps; i++) 
    { 
   		
        glVertex2i(ceil(X), ceil(Y));
		X += Xinc;        // increment in x at each step 
        Y += Yinc;        // increment in y at each step 
    }

  	glEnd();  
  	
 	glFlush(); 	
}

int rotatex(int x, int y, double angle)
{
    //x′=xcosθ−ysinθ 
	return x*cos( angle * PI / 180.0 ) - y*sin( angle * PI / 180.0 );
}

int rotatey(int x, int y, double angle)
{
    //y′=xsinθ+ycosθ
	return x*sin( angle * PI / 180.0 ) + y*cos( angle * PI / 180.0 );    
}

int translatex(int x, int tx)
{
	return x - tx;
}

int translatey(int y, int ty)
{
	return y - ty;
}


void boundaryfill(int x, int y)
{
	Color c;
    
    glReadPixels(x, y, 1, 1, GL_RGB, GL_FLOAT, &c);
    
    cout<<" \n "<<x<<" "<<y<<" "<<" - ";
	cout<<c.r<<" "<<c.g<<" "<<c.b<<" \n ";

	if(c.r==0.0f && c.g ==0.0f && c.b==0.0f && c.r!=1.0f && c.g !=1.0f && c.b!=1.0f)
    {
    	// glColor3f((float) nr/255, (float) ng/255, (float) nb/255);
		glColor3f(1.0,1.0,1.0);
    	
    	glBegin(GL_POINTS);
        	glVertex2i(x, y);
  		glEnd();  
  		
  		glFlush();
  		
  		boundaryfill(x+1, y);
  		boundaryfill(x, y-1);
  		boundaryfill(x-1, y);
  		boundaryfill(x, y+1);
    }
}


void drawChess()
{
	
	// Getting max window sizes
	Point Max;
	Max.x = glutGet(GLUT_WINDOW_WIDTH);
	Max.y = glutGet(GLUT_WINDOW_HEIGHT);
	
	// Setting the origin point
	Point Origin;
	Origin.x = Max.x/2;
	Origin.y = Max.y/2;

	Point od1,od2;
	
	od1 = d1;
	od2 = d2;
	
	d1.x += Origin.x;	
	d1.y += Origin.y;
	d2.x += Origin.x;	
	d2.y += Origin.y;

	// Draw borders of the chess board
	drawLine(rotatex(d1.x,d1.y,40.00), rotatey(d1.x,d1.y,40.00), rotatex(d2.x,d1.y,40.00), rotatey(d2.x,d1.y,40.00));	
	drawLine(rotatex(d1.x,d2.y,40.00), rotatey(d1.x,d2.y,40.00), rotatex(d2.x,d2.y,40.00), rotatey(d2.x,d2.y,40.00));
	drawLine(rotatex(d1.x,d2.y,40.00), rotatey(d1.x,d2.y,40.00), rotatex(d1.x,d2.y,40.00), rotatey(d1.x,d2.y,40.00));
	drawLine(rotatex(d2.x,d1.y,40.00), rotatey(d2.x,d1.y,40.00), rotatex(d2.x,d2.y,40.00), rotatey(d2.x,d2.y,40.00));


/*	
	// Draw borders of the chess board
	drawLine(d1.x, d1.y, d2.x, d1.y);	
	drawLine(d1.x, d2.y, d2.x, d2.y);
	drawLine(d1.x, d1.y, d1.x, d2.y);
	drawLine(d2.x, d1.y, d2.x, d2.y);

	
	Point fromx;
	
	fromx.x = abs(od1.x - od2.x)/4;
	fromx.y = abs(od1.y - od2.y)/4;
	 
	//cout<<"\n "<<d1.x<<" "<<d1.y<<" "<<d2.x<<" "<<d2.y;

	int xinc = fromx.x;
	int yinc = fromx.y;

	 // Draw inner vertical lines
	 for(int i=0;i<3;i++)
	 {
	 	drawLine(d1.x + fromx.x, d1.y, d1.x + fromx.x, d2.y);
	 	fromx.x += xinc;
	 }
	
	 // Draw inner horizontal lines
	 for(int i=0;i<3;i++)
	 {
	 	drawLine(d1.x, d1.y + fromx.y, d2.x, d1.y + fromx.y);
		fromx.y += yinc;
	}
	
	boundaryfill(d1.x+10,d1.y+10);		
*/
	glFlush();
}

void start()
{
	init();

	drawChess();
	
	//glFlush();
}

int main(int argc, char **argv)
{
	// Take input of coordinates
	cout<<"\n Enter the points for chessboard ";
	cout<<"\n Point 1 - ";
	cin>>d1.x>>d1.y;
	cout<<"\n Point 2 - ";
	cin>>d2.x>>d2.y;

	// OpenGL Glut Init
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE);

	// Set the window size
    glutInitWindowSize(1200, 800);
	glutInitWindowPosition(0, 0);

	glutCreateWindow("OpenGL - Creating a line");
	
	// Start with the program
    glutDisplayFunc(start);
	
    glutMainLoop();
   	return 0;
}	

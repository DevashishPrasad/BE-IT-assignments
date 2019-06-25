#include <GL/freeglut.h>
#include <GL/gl.h>
#include <iostream>

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

void drawLine()
{
	init();

	//DDA Function for line generation 
	int X0=300, Y0=300, X1=30, Y1=30;
    
	// calculate dx & dy glMatrixMode(GL_PROJECTION);
    int dx = abs(X1 - X0); 
    int dy = abs(Y1 - Y0); 
  
    // calculate steps required for generating pixels 
    int steps = dx > dy ? dx : dy; 
  
    // calculate increment in x & y for each steps 
    float Xinc = dx / (float) steps; 
    float Yinc = dy / (float) steps; 
  
    // Put pixel for each step 
    float X = X0; 
    float Y = Y0; 

	glBegin(GL_POINTS);

    for (int i = 0; i <= steps; i++) 
    { 
        glVertex2i(X,Y);
		X += Xinc;        // increment in x at each step 
        Y += Yinc;        // increment in y at each step 
        //delay(100);        
    }

  	glEnd(); 
    glFlush(); 
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    glutInitWindowSize(1200, 800);
	glutInitWindowPosition(0, 0);

	int winid = glutCreateWindow("OpenGL - Creating a line");

    glutDisplayFunc(drawLine);
    glutMainLoop();
 
   	return 0;
}

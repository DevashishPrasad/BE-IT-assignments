
    /*
    Draw a 4X4 chessboard rotated 45 ̊ with the horizontal axis. Use Bresenham algorithm to draw
    all the lines. Use seed fill algorithm to fill black squares of the rotated chessboard
    */
    #include<iostream>
    using namespace std;
    #include<GL/glut.h>
    #include<math.h>
    //------------------------------------------------------------
    struct PIXEL
    {
    	int x,y;
    };

    struct COLOR
    {
    	float r,g,b;
    };
     
    //------------------------------------------------------------
    void autoInit();
    void Display();
    void Mouse(int ,int ,int ,int );

    //------------------------------------------------------------

    struct PIXEL start,temp;
    struct COLOR fillcolor;
    static int flag=0;

    //------------------------------------------------------------
    int main(int argc,char **argv)
    {
    	glutInit( &argc , argv );
    	glutInitDisplayMode( GLUT_SINGLE | GLUT_RGB );
    	glutInitWindowPosition(0,0);
    	glutInitWindowSize(640,480);
    	glutCreateWindow("POLYGON FILLING");
   	autoInit();
    	glutDisplayFunc(Display);
    	glutMouseFunc(Mouse);
    	glutMainLoop();
    }

    //------------------------------------------------------------

    void autoInit()
    {
    	glClearColor(1,1,1,0);
    	glColor3f(0,0,0);
    	gluOrtho2D(0,640,0,480);
    }
    COLOR getPixelColor(int X, int Y)
    {
     	COLOR temp;
    	glReadPixels(X,Y,1,1,GL_RGB, GL_FLOAT, &temp);
    	return temp;
    }
    void setPixelColor(int X, int Y, COLOR color)
    {
       	glColor3f(color.r, color.g, color.b);
    	glBegin(GL_POINTS);
    		glVertex2i(X,Y);
    	glEnd();
    	glFlush();
    }
    void seedFill(int X, int Y, COLOR oldColor, COLOR fillColor)
    {
    	COLOR current;
    	current= getPixelColor(X,Y);
    	if(current.r == oldColor.r && current.g == oldColor.g && current.b == oldColor.b)
    	{
    		setPixelColor(X,Y, fillColor);
    		seedFill(X+1,Y, oldColor, fillColor);
    		seedFill(X,Y-1, oldColor, fillColor);
    		seedFill(X-1,Y, oldColor, fillColor);
    		seedFill(X,Y+1, oldColor, fillColor);
    	}
    }

    void Display()
    {
    	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    	glColor3f(1.0,0.0,0.0);//red
    	glRecti(10,30,60,10);
    	glColor3f(0.0,1.0,0.0);//green
    	glRecti(90,30,140,10);
    	glColor3f(0.0,0.0,1.0);//blue
    	glRecti(170,30,220,10);
    	glColor3f(1.0,1.0,0.0);//red-green
    	glRecti(250,30,300,10);
    	glColor3f(0.0,1.0,1.0);//green-blue
    	glRecti(330,30,380,10);
    	glColor3f(1.0,0.0,1.0);//blue-red
    	glRecti(410,30,460,10);

    	glFlush();
    }

    void Mouse(int button,int state,int x,int y)
    {
    	if(button==GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    	{
    		if(flag==0)  // to accept first point
    		{
    			flag=1;
    			glColor3f(0,0,0);
    			glBegin(GL_POINTS);
    				glVertex2i(x,480-y);
    				start.x=x;
    				start.y=480-y;
    				temp=start;
    			glEnd();
    			glFlush();
    		}
    		else if(flag==1)//to draw edges of poly
    		{
    			glColor3f(0,0,0);			
    			glBegin(GL_LINES);
    				glVertex2i(temp.x,temp.y);
    				glVertex2i(x,480-y);
    				temp.x=x;
    				temp.y=480-y;
    			glEnd();
    			glFlush();
    		}
    		else if(flag==2)  //accept desired color
    		{
     			fillcolor=getPixelColor(x,480-y);
    			flag=3;
    		}
    		else if(flag==3) //fill polygon
    		{
     			COLOR fillColor={fillcolor.r,fillcolor.g,fillcolor.b};
    			COLOR oldColor= { 1.0f,1.0f,1.0f};
    			seedFill(x,480-y,oldColor,fillColor);
    			flag=4;
    		}
    	}
    	if(button==GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
    	{
    		flag=2;
    		glColor3f(0,0,0);
    		glBegin(GL_LINES);
    			glVertex2i(temp.x,temp.y);
    			glVertex2i(start.x,start.y);
    		glEnd();
    		glFlush();
    	}
    }

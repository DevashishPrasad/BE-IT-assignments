/* Name : Devashish Prasad
RoLL NO : 23364
*/

#include<stdio.h>
#include<stdlib.h>
#include<dos.h>

char file[20];			//global declaration
char dir[20];
char file2[20];
char buffer[200];
int h1,h2;

union REGS i,o;
struct SREGS s;

void createdir()		//creating a directory
{


	printf("\n enter the name of directory : ");
	scanf("%s",dir);
	i.h.ah = 0x39;
	i.x.dx = FP_OFF(dir);
	s.ds = FP_SEG(dir);

	intdosx(&i,&o,&s);
	printf("\n Directory created...");
}



void createfile()		//creating a file
{

printf("\n enter the name of file : ");
	scanf("%s",file);
	i.h.ah = 0x3C;
	i.x.dx = FP_OFF(file);
	i.x.cx = 00;                // mode  of file
	s.ds = FP_SEG(file);		// 00 - READ MODE
								// 01 - WRITE MODE
								// 10 - READ & WRITE

	intdosx(&i,&o,&s);

	if(o.x.cflag)          //if operarion is performed then cx return 0
		printf("\n Error creating file...");
	else
		printf("\n file created...");

}
void deletefile()		//deleting A File
{
	   printf("\n enter the name of file : ");
	   scanf("%s",file);
	   i.h.ah = 0x41;
	   i.x.dx =  FP_OFF(file);
	   s.ds =  FP_SEG(file);

	   intdosx(&i,&o,&s);
	   printf("\n File deleted...");
}



void copyf()      //copying a file
{

	printf("Enter source file name      : ");
	scanf("%s", file);
	printf("Enter destination file name : ");
	scanf("%s", file2);

	i.h.ah = 0x3D;			//Open source file in read mode
	i.h.al = 00;
	i.x.dx = FP_OFF(file);
	s.ds = FP_SEG(file);

	intdosx(&i, &o, &s);
	h1 = o.x.ax;

	if(o.x.cflag)
	{
		printf("Can't open the source file !! \n");
		return;
	}

	i.h.ah = 0x3C;			//Create destination file
	i.x.dx = FP_OFF(file2);
	s.ds = FP_SEG(file2);

	intdosx(&i, &o, &s);
	h2 = o.x.ax;

	if(o.x.cflag)
	{
		printf("Can't create the destination file !! \n");
		return;
	}

	i.h.ah = 0x3D;			//Open destination file in write mode
	i.h.al = 01;
	i.x.dx = FP_OFF(file2);
	s.ds = FP_SEG(file2);

	intdosx(&i, &o, &s);

	if(o.x.cflag) {
		printf("Can't open the destination file !! \n");
		return;
	}


	i.h.ah = 0x3F;			//Read source file contents into buffer
	i.x.cx = 0xFFFF;
	i.x.bx = h1;
	i.x.dx = FP_OFF(buffer);
	s.ds = FP_SEG(buffer);

	intdosx(&i, &o, &s);

	if(o.x.cflag)
	{
		printf("Can't read from the source file !! \n");
		return;
	}

	i.h.ah = 0x40;			//Write contents from buffer to dest file
	i.x.cx = strlen(buffer);
	i.x.bx = h2;
	i.x.dx = FP_OFF(buffer);
	s.ds = FP_SEG(buffer);

	intdosx(&i, &o, &s);

	if(o.x.cflag)
	{
		printf("Can't write to destination file !! \n");
		return;
	}


	i.h.ah = 0x3E;			//Close the source file
	i.x.bx = h1;

	intdos(&i, &o);

	if(o.x.cflag) {
		printf("Can't close the source file !! \n");
		return;
	}

	i.h.ah = 0x3E;			//Close the destination file
	i.x.bx = h2;

	intdos(&i, &o);

	if(o.x.cflag) {
	printf("Can't close the destination file !! \n");
		return;
	}

	printf("File successfully copied !! \n");
}
int main()
{
	int ch;
	do
	{
	printf("\n================================================================");
	printf("\n FILE OPERATION");
	printf("\n 1. Create A File");
	printf("\n 2. Create A Directory ");
	printf("\n 3. Copy A File ");
	printf("\n 4. Delete A File ");
	printf("\n 5. Exit ");

	printf("\n Enter Your Choice :-");
	scanf("%d",&ch);

	switch(ch)
	{
		case 1:

			createfile();			//function calling

		break;

		case 2:

			createdir();			//create file  function calling
		break;

		case 3:
			copyf();			//copy file function calling

		break;

		case 4:
			deletefile();			//delete file Function calling
		break;

		case 5:
		return 0;

		default:
		printf("\n Please enter The Choice Between 1-5");

	}
	}while(ch!=5);
	getch();
	return 0;
}

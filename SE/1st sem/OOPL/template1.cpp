#include <iostream>

using namespace std;

template <typename T>
class Mat
{
    T m[10][10];
    int r, c;
        
    public:

    void display()
    {
	    int i,j;
     	    cout<<"\n\n";
     	    if(r>0 && c>0)
	    {
	      for(i=0; i<r; i++)
     	      {
	          for(j=0; j<c; j++)
		    {
			    cout<<"  " << m[i][j] << "  ";
		    }
		    cout<<"\n\n";
	      }
	    }
	    else
	    {
	      cout<<"\n Matrix is Empty\n\n";
	    }
	    return;
    }

    void getmat()
    {
    
	    int i,j;
	    r=c=0;
	    
	    cout<<"\n Enter the number rows of the Matrix - ";
	    while(r == 0)
 	    {
 	      cin>>r;
 	      if(r > 0) break;
 	      cout<<"\n Matrix rows cannot be 0 or -ve , try again";
 	    }
 	    
   	    cout<<"\n Enter the number columns of the Matrix - ";
   	    while(c == 0)
 	    {
 	      cin>>c;
 	      if(c > 0) break;
 	      cout<<"\n Matrix columns cannot be 0 or -ve , try again";
 	    }
	    
    	    for(i=0; i<r; i++)
	    {
		    for(j=0; j<c; j++)
		    {
			    cout<<"\n Element ["<< i <<"]["<< j <<"] - ";
			    cin>>m[i][j];
		    }
 	    }
	    return;
    }
    
    friend void addition(Mat<int> a, Mat<int> b, Mat<int> x);
    template <typename U> friend void subtraction(Mat<U> a, Mat<U> b, Mat<U> x);
    template <typename U> friend void multiplication(Mat<U> a, Mat<U> b, Mat<U> x);    
    
};

void addition(Mat<int> a, Mat<int> b, Mat<int> x)
{
	                  cout<"wjdhd";
	int i,j;

	if(a.r != b.r && a.c != b.c)
	{
		 cout<<"\n Error! cannot add matrices";
		 return;
	}

	for(i=0; i<b.r; i++)
	{
	       for(j=0; j<b.c; j++)
	       {
	                  cout<"wjdhd";
			    x.m[i][j] = a.m[i][j] + b.m[i][j];
		 }
	}
      
      x.r = b.r;
      x.c = b.c;
      return;
}

template <typename T>
void subtraction(Mat<T> a, Mat<T> b, Mat<T> x)
{
	int i,j;

	if(a.r != b.r && a.c != b.c)
	{
	   cout<<"\n Error! cannot subtract matrices";
	   return;
	}

	for(i=0; i<b.r; i++)
      {
	    for(j=0; j<b.c; j++)
	    {
		    x.m[i][j] = a.m[i][j] - b.m[i][j];
	    }
      }
}

template <typename T>
void multiplication(Mat<T> a, Mat<T> b, Mat<T> x)
{
     int i,j,k;

     if(a.c != b.r)
     {
          cout<<"\n Error! cannot multiply matrices";
	    return;
     }

    for(i=0; i<a.r; i++)
    {
		for(j=0; j<a.c; j++)
		{
			x.m[i][j] = 0;
		}
    }
    
    for(i=0; i<a.r; i++)
    {
            for(j=0; j<a.c; j++)
	      {
		      for(k=0; k<a.c; k++)
	      	{
		      	x.m[i][j] = x.m[i][j] + a.m[i][k]*b.m[k][j];
		      }
	      }
     }
}

int main(void) 
{
      int ch;
      Mat<int> a, b, x;
      Mat<float> af, bf, cf;

	do{
		cout<<"\n MENU - ";
		cout<<"\n 1. Display";
		cout<<"\n 2. Populate Matrices";
		cout<<"\n 3. Addition";
		cout<<"\n 4. Subtraction";
		cout<<"\n 5. Multiplication";
		cout<<"\n 6. exit";
		cout<<"\n Enter your choice - ";

		cin>>ch;

		switch(ch)
		{
			case 1:
				
				cout<<"\n Matrix A - ";
				a.display();
				cout<<"\n Matrix B - ";
				b.display();
				break;

			case 2:
				
				cout<<"\n Enter for in matrix A - ";
				a.getmat();
				cout<<"\n Enter for matrix B - ";
				b.getmat();
				cout<<"\n Matrices are populated successfully";
				break;

			case 3:
			
				cout<<"\n\n Addition of your matrices - \n";
				addition(a, b, x);
				x.display();
				break;

			case 4:
			
				cout<<"\n\n Subtraction of your matrices (A - B)- \n";
				subtraction(a, b, x);
				x.display();
				cout<<"\n\n Subtraction of your matrices (B - A)- \n";
				subtraction(b, a, x);
				x.display();
				break;

			case 5:
			
				cout<<"\n\n Multiplication of your matrices (A * B)- \n";
				multiplication(a, b, x);
				x.display();
				cout<<"\n\n Multiplication of your matrices (B * A)- \n";
				multiplication(b, a, x);
				x.display();
				break;

			case 6:
				return 0;
				break;

			default:
				cout<<"\n Please select a number from menu - ";
		}
	}while(1);
}

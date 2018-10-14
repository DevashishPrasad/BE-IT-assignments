#include <iostream>

using namespace std;

template <typename T>
class Mat
{
    T m[10][10], n[10][10], x[10][10];
    int r1, c1, r2, c2;
        
    public:

    void display()
    {
	    int i,j;
        cout<<"\n\n";
    
	    if(r1>0 && c1>0)
	    {
	      for(i=0; i<r1; i++)
          {
	        for(j=0; j<c1; j++)
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

		if(r2>0 && c2>0)
	    {
	      for(i=0; i<r2; i++)
          {
	        for(j=0; j<c2; j++)
		    {
			    cout<<"  " << n[i][j] << "  ";
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
	    r1=c1=r2=c2=0;
	    
	    cout<<"\n Enter the number rows of the Matrix 1 - ";
	    while(r1 == 0)
 	    {
 	      cin>>r1;
 	      if(r1 > 0) break;
 	      cout<<"\n Matrix rows cannot be 0 or -ve , try again";
 	    }
 	    
   	    cout<<"\n Enter the number columns of the Matrix - ";
   	    while(c1 == 0)
 	    {
 	      cin>>c1;
 	      if(c1 > 0) break;
 	      cout<<"\n Matrix columns cannot be 0 or -ve , try again";
 	    }
	    
    	for(i=0; i<r1; i++)
	    {
		    for(j=0; j<c1; j++)
		    {
			    cout<<"\n Element ["<< i <<"]["<< j <<"] - ";
			    cin>>m[i][j];
		    }
 	    }

		cout<<"\n Enter the number rows of the Matrix 2 - ";
	    while(r2 == 0)
 	    {
 	      cin>>r2;
 	      if(r2 > 0) break;
 	      cout<<"\n Matrix rows cannot be 0 or -ve , try again";
 	    }
 	    
   	    cout<<"\n Enter the number columns of the Matrix - ";
   	    while(c2 == 0)
 	    {
 	      cin>>c2;
 	      if(c2 > 0) break;
 	      cout<<"\n Matrix columns cannot be 0 or -ve , try again";
 	    }
	    
    	for(i=0; i<r2; i++)
	    {
		    for(j=0; j<c2; j++)
		    {
			    cout<<"\n Element ["<< i <<"]["<< j <<"] - ";
			    cin>>n[i][j];
		    }
 	    }
	    return;
    }
    
	void addition()
	{
		int i,j;

		if(r1 != r2 && c1 != c2)
		{
			cout<<"\n Error! cannot add matrices";
			return;
		}

		for(i=0; i<r1; i++)
		{
			for(j=0; j<c1; j++)
			{
					x[i][j] = m[i][j] + n[i][j];
					cout<< " "<< x[i][j] << " ";
			}
			cout<<endl;
		}
		return;
	}

	void subtraction()
	{
		int i,j;

		if(r1 != r2 && c1 != c2)
		{
			cout<<"\n Error! cannot subtract matrices";
			return;
		}

		for(i=0; i<r1; i++)
		{
			for(j=0; j<c1; j++)
			{
				x[i][j] = m[i][j] - n[i][j];
				cout<< " " <<x[i][j] << " ";
			}
			cout<<endl;
		}
	}

	void multiplication()
	{
		int i,j,k;

		if(c1 != r2)
		{
			cout<<"\n Error! cannot multiply matrices";
			return;
		}

		for(i=0; i<r1; i++)
		{
			for(j=0; j<c1; j++)
			{
				x[i][j] = 0;
			}
		}
		
		for(i=0; i<r1; i++)
		{
			for(j=0; j<c1; j++)
			{
				for(k=0; k<c1; k++)
				{
					x[i][j] = x[i][j] + m[i][k] * n[k][j];
				}
				cout<<" "<<x[i][j]<<" ";
			}
			cout<<endl;
		}
	}
};

int main(void) 
{
      int ch;
      Mat<int> a;
      Mat<float> b;

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
				
				cout<<"\n Int Matrix - ";
				a.display();
				cout<<"\n Float Matrix - ";
				b.display();
				break;

			case 2:
				
				cout<<"\n Enter for Int matrix - ";
				a.getmat();
				cout<<"\n Enter for Float matrix - ";
				b.getmat();
				cout<<"\n Matrices are populated successfully";
				break;

			case 3:
			
				cout<<"\n\n Addition of your matrices - \n";
				cout<<"\n INT - \n";
				a.addition();
				cout<<"\n FLOAT - \n";
				b.addition();
				break;

			case 4:
			
				cout<<"\n\n Subtraction of your matrices - \n";
				cout<<"\n INT - \n";
				a.subtraction();
				cout<<"\n FLOAT - \n";
				b.subtraction();
				break;

			case 5:
			
				cout<<"\n\n Multiplication of your matrices (A * B)- \n";
				cout<<"\n INT - \n";
				a.multiplication();
				cout<<"\n FLOAT - \n";
				b.multiplication();
				break;

			case 6:
				return 0;
				break;

			default:
				cout<<"\n Please select a number from menu - ";
		}
	}while(1);
}

#include<iostream>
using namespace std;

template<class T>
class matrix
{
   T a[10][10];
   int r,c;
  public:
   matrix()
   {
    a[10][10]=0;                                
    r=c=0;
   } 
    matrix(T b[10][10], int m, int n)
    {
      a[10][10]=b[10][10];
      r=m;
      c=n;
     } 
    void create()
    {
      int i=0,j;
      for(i=0;i<r;i++)
      {
         for(j=-0;j<c;j++)
         cin>>a[i][j];
      }
    }
    
    void display()
    {
      int i,j;
      for(i=0;i<r;i++)
      {
         for(j=0;j<c;j++)
         cout<<a[i][j]<<" ";
         cout<<"\n";
      }
       cout<<"\n";
     } 
     friend void addition(matrix<int>m1,matrix<float>m2);
   };
   
   void addition(matrix<int>m1,matrix<float>m2)
   {
     float c1[10][110];
     matrix<float>m3(c1,3,3);
     int i,j=0;
      for(i=0;i<m1.r;i++)
      {       
         for(j=0;j<m1.c;j++)
         {
           m3.a[i][j]=0;
           m3.a[i][j]=m1.a[i][j]+m2.a[i][j];
         }
       }
      m3.display(); 
   }       
   int main()
   {
     
    int a[10][10],choice,m1,m2,n1,n2;
    float b[10][10],c[10][110];
    cout<<"Enter for Matrix A\n";
    cout<<"Enter number of rows :";
    cin>>m1;
    cout<<"\nEnter bumber of columns :";
    cin>>n1;
    matrix<int>M1(a,m1,n1);
    cout<<"\nEnter for Matrix B\n";
    cout<<"Enter number of rows :";
    cin>>m2;
    cout<<"\nEnter bumber of columns :";
    cin>>n2;
    matrix<float>M2(b,m2,n2);
      
    do
    {
      cout<<"1.Read Matrix\n";
      cout<<"2.Display Matrix\n";
      cout<<"3.Perform Addition\n";
      cout<<"4.Perform Substraction\n";
      cout<<"5.Perform Multiplication\n";
      cout<<"6.Exit\n";
      cout<<"Enter your choice\n";
      cin>>choice;
      switch(choice)
      {
        case 1:cout<<"Enter elements of matrix A (integer elements)";
               M1.create();
               cout<<"Enter elements of matrix B (float elements)"; 
               M2.create();
               break;   
        case 2:cout<<"Matrix A:\n";
               M1.display();
               cout<<"Matrix B:\n"; 
               M2.display();
               break;
        case 3:if(!(m1==m2 && n1==n2))       
                 cout<<"Cannot perform addition\n";
               else
                 addition(M1,M2);
               break;  
      }
      }while(choice!=4);            
     
    
     return 0;
   }  
     
     

         

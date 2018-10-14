#include<iostream>
#include<math.h>

using namespace std;

class complex
{
    int real;
    int imag;

    public:
    complex()
    {
        real=0;
        imag=0;
    }

    void display()
    {
        cout<<"("<<float(real)<<")"<<"+"<<"("<<float(imag)<<")"<<"i\n";
    }

    void insert()
    {
        cin>>real>>imag;
    }

    complex operator*(complex c)
    {
        complex c1;
        c1.real=(real*c.real)-(imag*c.imag);
        c1.imag=(real*c.imag)+(c.real*imag);
        return c1;
    }

    complex operator/(complex c)
    {
        complex c1;
        c1.real=((real+c.real)+(imag*c.imag))/(pow(c.real,2)+pow(c.imag,2));
        c1.imag=((c.real*imag)-(real*c.imag))/(pow(c.real,2)+pow(c.imag,2));
        return c1;
    }

    friend complex operator +(complex c1,complex c2);
    friend complex operator -(complex c1,complex c2);

};

complex operator+(complex c1,complex c2)
{
    complex c;
    c.real=c1.real+c2.real;
    c.imag=c1.imag+c2.imag;
    return c;
}

complex operator-(complex c1,complex c2)
{
    complex c;
    c.real=c1.real-c2.real;
    c.imag=c1.imag-c2.imag;
    return c;
}

int main()
{
    complex c,c1,c2;
    int choice,a,b;
    do
    {
        cout<<"\n\n1.Addition\n";
        cout<<"2.Subtraction\n";
        cout<<"3.Multiplication\n";
        cout<<"4.Division\n";
        cout<<"5.EXIT\n";
        cout<<"Enter your choice :- ";
        cin>>choice;

        switch(choice)
        {
          case 1:
        		 cout<<"Enter real & imaginary number A -";         
                 c1.insert();
                 cout<<"Enter real & imaginary number B -";
                 c2.insert();
                 c=c1+c2;
                 cout<<"\n\nAddition of 2 Complex Numbers A -";
                 c.display();
                 break;
          case 2:
		         cout<<"Enter real & imaginary number A -";
                 c1.insert();
                 cout<<"Enter real & imaginary number B -";
                 c2.insert();
                 c=c1-c2;
                 cout<<"\n\nSubtraction of 2 Complex Numbers -";
                 c.display();
                 break;
          case 3:
		         cout<<"Enter real & imaginary number A-";
                 c1.insert();
                 cout<<"Enter real & imaginary number B-";
                 c2.insert();
                 c=c1*c2;
                 cout<<"\n\nMultiplication of 2 Complex Numbers :-";
                 c.display();
                 break;
         case 4: 
 		         cout<<"Enter real & imaginary number :-";
                 c1.insert();
                 cout<<"Enter real & imaginary number :-";
                 c2.insert();
                 c=c1/c2;
                 cout<<"\n\nDivision of 2 Complex Numbers :-";
                 c.display();
                 break;
        case 5: 
                return 0;
        default:
                cout<<"Enter correct choice\n";
        }
    }while(choice!=5);
    
    return 0;
}

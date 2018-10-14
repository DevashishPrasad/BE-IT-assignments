#include<iostream>
using namespace std;
class Shape
{
    protected:
    double d1,d2;
    public:
    void input(double a,double b)
    {
        d1=a;
        d2=b;
    }
    virtual double compute_area()
    {
      cout<<"Not Executed\n";
    }
    void display(double area)
    {
      cout<<"Area :"<<area<<endl;
    }
};

class triangle: public Shape
{
    public:
    double compute_area()
    {
      return(0.5*d1*d2);
    }
};

class rectangle: public Shape
{
    public:
    double compute_area()
    {
      return(d1*d2);
    }
};

int main()
{
    Shape *s;
    triangle t1;
    double a,b,c;
    s=&t1;
    cout<<"Computing Area of Triangle\n";
    cout<<"Enter Number 1:- ";
    cin>>a;
    cout<<"Enter Number 2:- ";
    cin>>b;
    s->input(a,b);
    c=s->compute_area();
    s->display(c);
    rectangle r1;
    s=&r1;
    cout<<"Computing Area of Rectangle\n";
    cout<<"Enter Number 1:- ";
    cin>>a;
    cout<<"Enter Number 2:- ";
    cin>>b;
    s->input(a,b);
    c=s->compute_area();
    s->display(c);
    return 0;
}

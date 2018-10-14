#include<iostream>
#include<iomanip>

using namespace std;

class exception1
{
    double x,y;
    public:
    void input()
    {
        double a,b;
        cout<<"\nEnter a and b :";
        cin>>a>>b;
        x=a;
        y=b;
    }
    double division()
    {
        try
        {
            input();
            if(y==0)
                throw y;
            else
                return(x/y);
        }
        catch(double y)
        {
            cout<<"Divide by zero exception\n";
            cout<<"Enter correct values\n";
            division();
        }
    }
    void display(double z)
    {
        cout<<"a/b ="<<std::setprecision(2)<<z;
    }

};
int main()
{
    exception1 e1;
    double c;
    c=e1.division();
    e1.display(c);
    return 0;
}

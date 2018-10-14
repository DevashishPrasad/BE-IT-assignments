#include<iostream>
using namespace std;

class prsnlinfo
{
   protected:
       char name[20];
       char dob[20];
       char blood_grp[5];
};

class info
{
  protected:
    int height;
    int weight;
};

class add
{
 protected:
  int policy_no;
  char add[100];
};

class details : public prsnlinfo,public info,public add
{
 protected:
    int tel_no;
    int license_no;
 public:
    void create(int i)
    {
        cout<<"\nRecord No. "<<i;
        cout<<"\nEnter Name:-";
        cin>>name;
        cout<<"\nEnter DOB(dd/mm/yy):-";
        cin>>dob;
        cout<<"\nEnter Blood Group:-";
        cin>>blood_grp;
        cout<<"\nEnter Height:-";
        cin>>height;
        cout<<"\nEnter Weight:-";
        cin>>weight;
        cout<<"\nEnter Policy Number:-";
        cin>>policy_no;
        cout<<"\nEnter Address:-";
        cin>>add;
        cout<<"\nEnter Phone No.:-";
        cin>>tel_no;
        cout<<"\nEnter License Number:-";
        cin>>license_no;
    }
    void display()
    {
        cout<<name<<"\t"<<dob<<"\t"<<blood_grp<<"\t"<<height<<"\t"<<weight<<"\t"<<policy_no<<"\t\t"<<add<<"\t"<<tel_no<<"\t\t"<<license_no<<"\n";
    }
};

int main()
{
    details d[20];
    int choice,i,n=0;
    do
    {
        cout<<"\n1.Build Master Table\n";
        cout<<"2.Display Records\n";
        cout<<"";
        cout<<"";
        cout<<"";
        cout<<"";
        cout<<"Enter your choice :-";
        cin>>choice;
        switch(choice)
        {
            case 1: cout<<"Enter the number of entries";
                    cin>>n;
                    for(i=0;i<n;i++)
                    {
                      d[i].create(i+1);
                    }
                    break;
             case 2:if(n==0)
                      cout<<"First create master table\n";
                    else
                    {
                     cout<<"Name\tDOB\tBlood\tHeight\tWeight\tPolicyNo.\tAddress\tPhoneNo.\tLicenseNo\n";
                     for(i=0;i<n;i++)
                     {
                        d[i].display();
                     }
                    }
                    break;
        }
    }while(choice!=3);
    return 0;
}

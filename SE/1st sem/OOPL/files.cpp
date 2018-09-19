#include <iostream>
#include <fstream>

using namespace std;

class Student
{
    char *name;
    int rollno;
    int marks;

    public:
    friend void input(Student s[], int n);
    friend void read( int n);
};

void input(Student s[], int n)
{
    int i;

    for(i = 0; i < n; i++)
    {
        cout<<"\n\nRecord number "<<i+1<<endl;
        s[i].name = new char[20];
        cout<<"Enter name - "<<endl;
        cin>>s[i].name;
        cout<<"Enter rollno - "<<endl;
        cin>>s[i].rollno;
        cout<<"Enter marks - "<<endl;
        cin>>s[i].marks;
    }
}

void write(Student s[], int n)
{
    fstream f;
    f.open("abc.txt",ios::out);
    int i;

    for(i = 0; i < n; i++)
    {
        f.write((char *) &s[i], sizeof(s[i]));
    }
    f.close();
    cout<<"\n\nRecords written in file successfully"<<endl;
}

void read(int n)
{
    cout<<"\n\nReading records from file"<<endl;
    fstream f;
    f.open("abc.txt",ios::in);
    int i;
    
    Student temp;
    
    cout<<"NAME\tROLLNO\tMARKS"<<endl;
    for(i = 0; i < n; i++)
    {
        f.read((char *) &temp, sizeof(temp));
        cout<<i+1<<temp.name<<"\t"<<temp.rollno<<"\t"<<temp.marks<<endl;
    }
    
    f.close();
}

int main()
{
    int n=0;
    Student *s;
    
    while(n == 0)
    {
        cout<<"Enter the number of records to be writen - "<<endl;
        cin>>n;
        if(n>0)
        {
            s = new Student[n];
            break;
        }
        cout<<"Invalid value...  Please try again"<<endl;
    }
    
    input(s, n);
    write(s, n);
    read(n);

    return EXIT_SUCCESS;
}

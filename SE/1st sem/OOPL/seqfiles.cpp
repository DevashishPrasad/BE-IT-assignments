#include<iostream>
#include <string.h>
#include <fstream>

using namespace std;

class Student
{

    char *name;
    char *phone;
    int id;
    long int salary;
    
    public:
    Student()
    {
         name = new char[20];
         phone= new char[20];
    }
    
    friend void createdb(Student record[100], int n);
    friend void display(Student record[100]);
    friend void add(Student record[100], int n, fstream *fp);
    friend void search(int id, fstream *fp);
    friend void modify(int id, fstream *fp);
    friend void  del(int id, fstream *fp);
};

void createdb(Student record[100], int n)
{
    fstream fp;
    Student student;

    int i,j,flg=0;
    for(i=0; i<n; i++)
    {
        fp.open("database.txt", ios::in);
        cout<<"\n\nRecord Number - "<<i+1;
        cout<<"\nEnter the id of the employee - ";
        while(1)
        {
            flg = 0;
            cin>>record[i].id;
            while(fp.read((char *) &student, sizeof(student)))
            {  cout<<"kjkjkj";
               if(student.id == record[i].id)
                {
                    flg = 1;
                    cout<<"\nID already exist, please enter another ID -";
                    break;
                }
            }
            if(flg == 0) break;

        }
        fp.close();
        cout<<"\nEnter the name of the employee - ";
        cin>>record[i].name;
        cout<<"\nEnter the phone number of the employee - ";
        
        while(1)
        {
            cin>>record[i].phone;
            if(strlen(record[i].phone) == 10) break;
            else cout<<"\nInvalid phone number, Please try again - ";
        }
        
        cout<<"\nEnter the salary of the employee - ";
        cin>>record[i].salary;
        
        fp.open("database.txt", ios::out);
        if(fp.write((char *) &record[i], sizeof(&record[i]))) cout<<"TRUE";
        fp.close();
    }
}
void display(Student record[100])
{
    fstream fp;
    Student student;

    fp.open("database.txt",ios::in);

    if(fp == NULL) return;
    else
    {
         cout<<"\nID\tPHONE     \tSALARY\t\tNAME";
         while()
         {
             fp.read((char *) &student, sizeof(student));
             cout<<"sdsdsd";
             cout<<student.id<<"\t"<< student.phone<<"\t"<<student.salary<<"\t"<<student.name;
         }
    }
    fp.close();
}

void add(Student record[100], int n, fstream *fp)
{
    Student student;
    fp->open("database.txt",ios::app);
    int i,flg=0;
    for(i=0; i<n; i++)
    {
        cout<<"\n\nRecord Number - "<<i+1;
        cout<<"\nEnter the id of the employee - ";
        while(1)
        {
            flg = 0;
            cin>>record[i].id;
            while(fp->read((char *) &student, sizeof(student)))
                if(student.id == record[i].id)
                {
                    flg = 1;
                    cout<<"\nID already exist, please enter another ID -";
                    break;
                }
            if(flg == 0) break;
        }
        cout<<"\nEnter the name of the employee - ";
        cin>>record[i].name;
        cout<<"\nEnter the phone number of the employee - ";
        while(1)
        {
            cin>>record[i].phone;
            if(strlen(record[i].phone) == 10) break;
            else cout<<"\nInvalid phone number, Please try again - ";
        }
        cout<<"\nEnter the salary of the employee - ";
        cin>>record[i].salary;
        fp->write((char *) &record[i], sizeof(student));
    }
    fp->close();
}
void search(int id, fstream *fp)
{
    Student student;
    fp->open("database.txt",ios::in);

    int i,val=-1;

    while(fp->read((char *) &student, sizeof(student)))
        if(student.id == id)
        {
            val = 1;
            break;
        }

    if(val == -1)
        cout<<"\nNo record found...";
    else
    {
        cout<<"\nRecord Found";
        cout<<"\nID\tPHONE     \tSALARY\t\tNAME";
        cout<<"\n"<<student.id<<"\t"<< student.phone<<"\t"<< student.salary;
        cout<<"\t\t";
        puts(student.name);
    }

    fp->close();
}
void modify(int id, fstream *fp)
{
    Student student,s;
    fp->open("database.txt",ios::in);
    fstream np; 
    np.open("temp.txt",ios::out);

    int i,val=-1;

    while(fp->read((char *) &student, sizeof(student)))
    {   
        if(student.id == id)
        {
            cout<<"\nEnter the name of the employee - ";
            cin>>student.name;
            cout<<"\nEnter the phone number of the employee - ";
            while(1)
            {
                cin>>student.phone;
                if(strlen(student.phone) == 10) break;
                else cout<<"\nInvalid phone number, Please try again - ";
            }
            cout<<"\nEnter the salary of the employee - ";
            cin>>student.salary;
            np.write((char *) &student, sizeof(Student));
            continue;
        }
        np.write((char *) &student, sizeof(student));
    }

    fp->close();
    np.close();
    remove("database.txt");
    rename("temp.txt","database.txt");
}
void del(int id, fstream *fp)
{
    Student student,s;
    fp->open("database.txt",ios::in);
    fstream np;
    np.open("temp.txt",ios::out);

    int i,val=-1;

    while(fp->read((char *) &student, sizeof(student)))
    {   
        if(student.id == id)
        {
            continue;
        }
        fp->write((char *) &student, sizeof(student));
    }

    fp->close();
    np.close();
    remove("database.txt");
    rename("temp.txt","database.txt");
}

int main(void) {

    int ch,no=0,i;
    Student records[100];
    fstream fp;

    do{
        cout<<"\n\n\n ******* MENU ******* ";
        cout<<"\n 1. Create databse";
        cout<<"\n 2. Display database";
        cout<<"\n 3. Add record";
        cout<<"\n 4. Search record";
        cout<<"\n 5. Modify record";
        cout<<"\n 6. Delete record";
        cout<<"\n 7. exit";
        cout<<"\n Enter your choice - ";
        cin>>ch;

        switch(ch)
        {
            case 1:
                    cout<<"\nCreating new Database - ";
                    cout<<"\nEnter the number of Records to be entered - ";
                    cin>>no;
                    createdb(records, no);
                    break;
            case 2:    
                    display(records);
                    break;
            case 3:
                    cout<<"\nAdding records - ";
                    cout<<"\nEnter the number of Records to be entered - ";
                    cin>>no;
                    add(records, no, &fp);
                    break;
            case 4:
                    cout<<"\nEnter the ID of the employee to be searched - ";
                    cin>>i;
                    search(i, &fp);
                    break;
            case 5:
                    cout<<"\nEnter the ID of the employee to be modified - ";
                    cin>>i;
                    modify(i, &fp);
                    break;
            case 6:

                    cout<<"\nEnter the ID of the employee to be  deld - ";
                    cin>>i;
                    del(i, &fp);
                    break;
            case 7:
                    return 0;
            default:
                    cout<<"\nPlease select a number form menu - ";
                    break;
        }
    }while(1);
    return 0;
}

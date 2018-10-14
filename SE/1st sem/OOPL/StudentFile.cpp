#include <iostream>
#include<fstream>
#include<cstring>
#include<iomanip>

using namespace std;

class Student
{
public:
 int rollno;
 char name[20],city[20],year[20],div[20];
 Student()
{
  strcpy(name,"");
  strcpy(city,"");
  strcpy(year,"");
  strcpy(div,"");
  rollno=0;
}
 Student(int rollno,char name[20],char city[20],char year[20],char div[20])
 {
  strcpy(this->name,name);
  strcpy(this->city,city);
  this->rollno=rollno;
  strcpy(this->year,year);
  strcpy(this->div,div);
 }
 int getRollNo()
 {
  return rollno;
 }
 void displayRecord()
 {

        cout<<endl<<setw(5)<<rollno<<setw(10)<<name<<setw(9)<<year<<setw(13)<<div<<setw(10)<<city;

        cout<<"\n--------------------------------------------------";
 }
};
//==========File Operations ===========
class FileOperations
{
 fstream file;
public:
 FileOperations(char* filename)
{
file.open(filename,ios::in|ios::out|ios::ate|ios::binary);
}
 void insertRecord(int rollno, char name[20],char year[20], char div[20],char city[20])
 {
  Student s1(rollno,name,year,div,city);
  file.seekp(0,ios::end);
  file.write((char *)&s1,sizeof(Student));
  file.clear();
 }
 void displayAll()
 {
  Student s1;
  file.seekg(0,ios::beg);
  while(file.read((char *)&s1, sizeof(Student)))
  {
   s1.displayRecord();
  }
  file.clear();
 }
 void displayRecord(int rollNo)
 {
  Student s1;
  file.seekg(0,ios::beg);
  bool flag=false;
  while(file.read((char*)&s1,sizeof(Student)))
  {
   if(s1.getRollNo()==rollNo)
   {
    s1.displayRecord();
    flag=true;
    break;
   }
  }
  if(flag==false)
  {
   cout<<"\nRecord of "<<rollNo<<"is not present.";
  }
  file.clear();
 }
 void modify(int rollno)
 {
  ofstream outFile("new.txt",ios::binary);
  file.seekg(0,ios::beg);
  bool flag=false;
  Student s1;

  while(file.read((char *)&s1, sizeof(Student)))
  {
   if(s1.getRollNo()==rollno)
   {

       cout<<endl<<"Enter Name To Update: ";
       cin>>s1.name;

       cout<<endl<<"Enter Learning Year To Update : ";
       cin>>s1.year;

       cout<<endl<<"Enter Division To Update : ";
       cin>>s1.div;

       cout<<endl<<"Enter address To Update: ";
       cin>>s1.city;
       outFile.write((char *)&s1, sizeof(Student));
       cout<<"\n------------ Data Successfully Updated --------------";
    flag=true;
    continue;
   }
   outFile.write((char *)&s1, sizeof(Student));
  }
  if(!flag)
  {
   cout<<"\nRecord of "<<rollno<<" is not present.";
  }
  file.close();
  outFile.close();
  remove("student.txt");
  rename("new.txt","student.txt");
  file.open("student.txt",ios::in|ios::out|ios::ate|ios::binary);
 }
 void deleteRecord(int rollno)
 {
  ofstream outFile("new.txt",ios::binary);
  file.seekg(0,ios::beg);
  bool flag=false;
  Student s1;

  while(file.read((char *)&s1, sizeof(Student)))
  {
   if(s1.getRollNo()==rollno)
   {
        flag=true;
        continue;
   }
   outFile.write((char *)&s1, sizeof(Student));
  }
  if(!flag)
  {
   cout<<"\nRecord of "<<rollno<<" is not present.";
  }
  file.close();
  outFile.close();
  remove("student.txt");
  rename("new.txt","student.txt");
  file.open("student.txt",ios::in|ios::out|ios::ate|ios::binary);
 }
 ~FileOperations()
 {
  file.close();
  cout<<"\nFile Closed.";
 }
};
int main() {
 ofstream newFile("student.txt",ios::app|ios::binary);
  newFile.close();
  FileOperations file((char*)"student.txt");
     int rollNo,choice=0;
     char div[20],year[20];
     char name[20],city[20];
     while(choice!=5)
     {
         //clrscr();
         cout<<"\n\n---------------Student Database---------------\n\n";
         cout<<"1 --> Add New Record\n";
         cout<<"2 --> Display All Records\n";
         cout<<"3 --> Display by RollNo\n";
         cout<<"4 --> Modify The Student Data\n";
         cout<<"5 --> Deleting a Record\n";
         cout<<"6 --> Exit\n";
         cout<<"\n-------------------------------------------------\n\n";
         cout<<"Choose your choice : ";
         cin>>choice;
         switch(choice)
         {
             case 1 : //New Record
                           cout<<endl<<"Enter Roll_No : ";
                           cin>>rollNo;

                           cout<<endl<<"Enter Name : ";
                           cin>>name;

                           cout<<endl<<"Enter Learning Year  : ";
                           cin>>year;

                           cout<<endl<<"Enter Division  : ";
                           cin>>div;

                           cout<<endl<<"Enter address : ";
                           cin>>city;

                           file.insertRecord(rollNo,name,city,year,div);
                           cout<<"\nRecord Inserted.";

                           break;
             case 2 :
                            cout<<"\n--------------------------------------------------";
                           cout<<endl<<setw(5)<<"ROLL"<<setw(10)<<"NAME"<<setw(10)<<"YEAR"<<setw(10)<<"DIV"<<setw(10)<<"CITY";
                            cout<<"\n--------------------------------------------------";
                            file.displayAll();
                            break;
             case 3 :
                           cout<<"\nEnter Roll Number : ";
                           cin>>rollNo;
                           cout<<"\n---------------------------------------------------";
                           cout<<endl<<setw(5)<<"ROLL"<<setw(10)<<"NAME"<<setw(10)<<"YEAR"<<setw(10)<<"DIV"<<setw(10)<<"CITY";
                           cout<<"\n---------------------------------------------------";
                           file.displayRecord(rollNo);

                           break;
             case 4:
                           cout<<"\nEnter RollNo Which Data You Want To Modify : ";
                           cin>>rollNo;
                           file.modify(rollNo);
                           break;
            case 5:
                           cout<<"Enter rollNo Which Record You Want To Modify";
                           cin>>rollNo;
                           file.deleteRecord(rollNo);
                           break;
            case 6:
                           break;
            default:
                         cout<<"\nPlease Enter The Correct Choice.";
         }

     }

 return 0;
}
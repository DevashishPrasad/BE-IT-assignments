#include<iostream>
#include<iomanip>
using namespace std;

class Personal_Details
{

   public:
   		   string name;
				string DOB;
				string bgroup;

           void getPersonalDetails()
           {
            	cout<<"\n--------------------------------------";
           	   cout<<"\nEnter The Name : ";
           	   cin>>name;
           	   cout<<"\nEnter The DOB(In dd-mm-yyyy) : ";
           	   cin>>DOB;
           	   cout<<"\nEnter The bgroup : ";
           	   cin>>bgroup;
           	}

 };

class Professional_Details
{


   public:
				string Experience;
				string Experties;

           void getProfessionalDetails()
           {
            	cout<<"\nEnter The Experience (In Years) : ";
           	   cin>>Experience;
           	   cout<<"\nEnter The Experties ( If Multiple Enter Comma Seperated ) : ";
           	   cin>>Experties;
           	}
 };

class Academic_Details
{

   public:
				float degree_percentile;

           void getAcademicDetails()
           {
            	cout<<"\nEnter Percentage Got In Degree : ";
           	   cin>>degree_percentile;
       	 	}
 };

 class Resume:public Personal_Details,public Professional_Details,public Academic_Details
 {
 	 public:
            void DisplayData()
 	         {
 	          	cout<<"\n----------------------------------------";
 	          	cout<<setw(60)<<"\n\t\tRESUME";
 	          	cout<<"\n----------------------------------------";
                cout<<"\nName : \t"<<name<<"\n\nDate Of Birth : \t"<<DOB<<"\n\nBlood Group : \t"<<bgroup<<"\n\nYear Of Experience : \t"<<Experience<<" Yrs"<<"\n\nSkills : \t"<<Experties<<"\n\nDegree Percentile : \t"<<degree_percentile;
                cout<<"\n----------------------------------------";
             }




 };
 int main()
 {
 		int choice=0;
 		Resume rm;
 		do
 		{
 		  cout<<"\n\n\t\t------------Main Menu--------------";
 		  cout<<"\n\n\t\t1.Read Details\n\t\t2.Display Bio-Data\n\t\t3.Exit";
 		  cout<<"\n\n\t\t--------------------------------------";
 		  cout<<"\n\t\tEnter Your Choice : ";
 		  cin>>choice;
 		  switch(choice)
 		  {
 		     case 1:
 		        		 	rm.getPersonalDetails();
 		        		 	rm.getProfessionalDetails();
 		        		 	rm.getAcademicDetails();
 		        		 	break;
 		     case 2:
 		        		   rm.DisplayData();
 		        		   break;
 		     case 3:
 		       			break;
 		     default:
 		     				cout<<"\nEnter Valid Choice.";
 		  }

 		}while(choice != 3);
 }


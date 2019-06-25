//============================================================================
// Name        : Assignement2.cpp
// Author      : Devashish Krishna Prasad
// Version     : 1.0
// Copyright   : GNU Public License
// Description : Hospital management priority queue
//============================================================================

#include <iostream>
#include "Queue.h"
#include "Queue.cpp"
#include <iomanip>
#include <string.h>

using namespace std;

enum diseases {heartattack = 6, cancer = 5, fracture = 4, malaria = 3, chickenpox = 2,others = 1};

struct Patient
{
	char disease[20];
	char name[20];
	int id;
	char phone[10];
};

class Hospital
{
	Patient patient;

	public:

	void getPatient();
	void display(int sr);
	int getPriority();
	int getId();
};

void Hospital::getPatient()
{
	cout<<"\n Enter the details for the patient - ";
	cout<<"\n Name - ";
	cin>>patient.name;
	cout<<"\n Disease - ";
	cin>>patient.disease;
	cout<<"\n ID - ";
	cin>>patient.id;
	while(1)
	{
		cout<<"\n Phone - ";
		cin>>patient.phone;
		if(strlen(patient.phone) != 10)
		{
			cout<<"\n\n Invalid Phone Number, Try Again!";
			continue;
		}
		else
			break;
	}
}

void Hospital::display(int sr=1)
{
	cout<<setw(15)<<sr<<"\t";
	cout<<setw(15)<<patient.name<<"\t";
	cout<<setw(15)<<patient.disease<<"\t";
	cout<<setw(15)<<patient.id<<"\t";
	cout<<setw(15)<<patient.phone<<endl;
	cout<<"----------------------------------------------------------------------------------------------------\n";
}

int Hospital::getId()
{
	return patient.id;
}
int Hospital::getPriority()
{
	diseases d;

	if(!strcmp(patient.disease,"heartattack") || !strcmp(patient.disease,"HeartAttack") || !strcmp(patient.disease,"Heartattack"))
		d = heartattack;
	else if(!strcmp(patient.disease,"cancer") || !strcmp(patient.disease,"Cancer"))
		d = cancer;
	else if(!strcmp(patient.disease,"fracture") || !strcmp(patient.disease,"Fracture"))
		d = fracture;
	else if(!strcmp(patient.disease,"malaria") || !strcmp(patient.disease,"Malaria"))
		d = malaria;
	else if(!strcmp(patient.disease,"chickenpox") || !strcmp(patient.disease,"Chickenpox")|| !strcmp(patient.disease,"ChickenPox"))
		d = chickenpox;
	else
		d = others;

	return d;
}

void maketable()
{
	cout<<"\n\n\n=================================================================================================\n";
	cout<<setw(15)<<"SR\t";
	cout<<setw(15)<<"NAME \t";
	cout<<setw(15)<<"DISEASE \t";
	cout<<setw(15)<<"ID \t";
	cout<<setw(15)<<"PHONE \t"<<endl;
	cout<<"====================================================================================================\n";
}
int main() {

	Hospital h,*t;
	Queue <Hospital> PriorityQueue;
	int choice,temp = 1;

	do
	{
		cout<<"\n\n\n.===================================.";
		cout<<"\n|               MENU                |";
		cout<<"\n|===================================|";
		cout<<"\n| 1. Add a patient in the queue     |";
		cout<<"\n| 2. Display all patients the queue |";
		cout<<"\n| 3. Serve next patient in queue    |";
		cout<<"\n| 4. Delete the current queue       |";
		cout<<"\n| 5. Exit                           |";
		cout<<"\n*===================================*";
		cout<<"\n Enter your choice - ";
		cin>>choice;

		switch(choice)
		{
			case 1:
				temp = 1;
				while(temp)
				{
					h.getPatient();
					t = PriorityQueue.display();
					temp = 0;

					for(int i=0; i<PriorityQueue.length() ;i++)
					{
						if(t[i].getId() == h.getId())
						{
							temp = 1;
							cout<<"\n Entered ID of patient is not unique";
						}
					}
					if(temp == 1)
						continue;
					else
						temp = 0;

					PriorityQueue.enqueue(h, h.getPriority());
					cout<<"\n\n Patient added to the queue successfully ";
				}
				break;
			case 2:
				if(!PriorityQueue.isempty())
				{
					cout<<"\n\n Patients waiting in the Queue are - \n";
					maketable();
					t = PriorityQueue.display();
					for(int i=0; i<PriorityQueue.length() ;i++)
						t[i].display(i+1);
				}
				else
					cout<<"\n\n No patients in the queue";
				break;
			case 3:
				if(!PriorityQueue.isempty())
				{
					cout<<"\n\n Following Patient was served successfully - \n";
					maketable();
					PriorityQueue.dequeue().display();
				}
				else
					cout<<"\n\n No patients in the queue";
				break;
			case 4:
				while(!PriorityQueue.isempty())
					PriorityQueue.dequeue();
				cout<<"\n\n Queue was deleted successfully ";
				break;
			case 5:
				return 0;
		}
	}while(1);

	return 0;
}

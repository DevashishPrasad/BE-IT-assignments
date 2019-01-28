//============================================================================
// Name        : Assignement2.cpp
// Author      : Devashish Krishna Prasad
// Version     : 1.0
// Copyright   : GNU Public Licence
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
	void display();
	int getPriority();
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
	cout<<"\n Phone - ";
	cin>>patient.phone;
}

void Hospital::display()
{
	cout<<setw(20)<<patient.name<<" ";
	cout<<setw(20)<<patient.disease<<" ";
	cout<<setw(5)<<patient.id<<" ";
	cout<<setw(10)<<patient.phone<<endl;
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

int main() {

	Hospital h,*t;
	Queue <Hospital> PriorityQueue;
	int choice;

	do
	{
		cout<<"\n\n\n=====================================";
		cout<<"\n                MENU";
		cout<<"\n=====================================";
		cout<<"\n 1. Add a patient in the queue";
		cout<<"\n 2. Display all patients the queue";
		cout<<"\n 3. Serve next patient in queue";
		cout<<"\n 4. Delete the current queue";
		cout<<"\n 5. Exit";
		cout<<"\n\n\n=====================================";
		cout<<"\n Enter your choice - ";
		cin>>choice;

		switch(choice)
		{
			case 1:
				h.getPatient();
				PriorityQueue.enqueue(h, h.getPriority());
				cout<<"\n\n Patient added to the queue successfully ";
				break;
			case 2:
				cout<<"\n\n Patients waiting in the Queue are - \n";
				cout<<setw(20)<<"NAME ";
				cout<<setw(20)<<"DISEASE ";
				cout<<setw(5)<<"ID ";
				cout<<setw(10)<<"PHONE "<<endl;
				t = PriorityQueue.display();
				for(int i=0; i<PriorityQueue.length() ;i++)
					t[i].display();
				break;
			case 3:
				if(!PriorityQueue.isempty())
				{
					cout<<"\n\n Following Patient was served successfully - \n";
					cout<<setw(20)<<"NAME ";
					cout<<setw(20)<<"DISEASE ";
					cout<<setw(5)<<"ID ";
					cout<<setw(10)<<"PHONE "<<endl;
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

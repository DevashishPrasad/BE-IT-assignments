//============================================================================
// Name        : Assignement2.cpp
// Author      : Devashish Krishna Prasad
// Version     : 1.0
// Copyright   : GNU Public Licence
// Description : Hospital management priority queue
//============================================================================

#include <iostream>
#include "Queue.h"
using namespace std;

enum diseases {heartattack = 6, cancer = 5, fracture = 4, malaria = 3, chickenpox = 2,others = 1};
struct Patient
{
	char disease[20];
	char name[40];
	int id;
	char phone[10];
};

class Hospital
{
	Patient *patient;

	public:

	void create();
	void addPatient();
	void displayAll();
	void servePatient();
	void deleteAll();
};

void Hospital::create()
{
	int total;
	cout<<"\n\n Creating a new queue";
	cout<<"\n Enter the maximum number of patients in queue - ";
	cin>>total;
	patient = new Patient[total];
	cout<<"\n Queue created successfully";
}

void Hospital::addPatient()
{
	cout<<"\n Enter the details for the patient - ";
	cout<<"";
}

void Hospital::displayAll()
{

}

void Hospital::servePatient()
{

}

void Hospital::deleteAll()
{

}

int main() {

	Hospital h;
	Queue <Hospital> PriorityQueue;
	int choice;

	do
	{
		cout<<"\n\n\n----------- MENU -------------";
		cout<<"\n 1. Create a Queue for patients";
		cout<<"\n 2. Add patients in the queue";
		cout<<"\n 3. Display all patients the queue";
		cout<<"\n 4. Serve the patient in queue";
		cout<<"\n 5. Delete the current queue";
		cout<<"\n 6. Exit";
		cout<<"\n Enter your choice - ";
		cin>>choice;

		switch(choice)
		{
			case 1:
				h.create();
				break;
			case 2:
				h.addPatient();
				break;
			case 3:
				h.displayAll();
				break;
			case 4:
				h.servePatient();
				break;
			case 5:
				h.deleteAll();
				break;
			case 6:
				return 0;
		}
	}while(1);

	return 0;
}


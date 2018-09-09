#include <stdio.h>
#include <iostream>
#include <string.h>

using namespace std;

class Book
{
	char *name;
	char *auth;
	char *publish;
	int *stk;
	float *price;
	static int trans;
	public:
	static int flg;
	Book()
	{
		name = new char[100];
		auth = new char[100];
		publish = new char[100];
		stk = new int;
		price = new float;
	}
	void add()
	{
		cout<<"\n\n\nEnter the details for the book- ";
		cout<<"\nTitle : ";
		cin>>name;
		cout<<"\nAuthor : ";
		cin>>auth;
		cout<<"\nPublisher :";
		cin>>publish;
		cout<<"\nStock : ";
		cin>>*stk;
		cout<<"\nPrice : ";
		cin>>*price;
	}
	void display()
	{
		cout<<"\n"<<name<<"\t"<<auth<<"\t"<<publish<<"\t\t"<<*stk<<"\t"<<*price;
	}
	void search(char *temp)
	{
		if(!strcmp(name,temp))
		{
			Book::flg = 1;
			cout<<"\n"<<name<<"\t"<<auth<<"\t"<<publish<<"\t\t"<<*stk<<"\t"<<*price;
		}
	}
};

int Book::flg;

int main()
{
	Book b[50] ;
	int max, i, ch, n;
	cout<<"\nEnter the number of books to be entered in the database - ";
	cin>>max;

	for(i=0; i<max; i++)
		b[i].add();
		
	cout<<"\nDatabase created successfully ";
	
	do
	{
		cout<<"\n\n\n *******  MENU  *******";
		cout<<"\n 1. ADD a book";
		cout<<"\n 2. DISPLAY all books";
		cout<<"\n 3. SEARCH a book";
		cout<<"\n 4. MODIFY a book";
		cout<<"\n 5. PURCHASE books";		
		cout<<"\n 5. TRANSACTIONS";		
		cout<<"\n 6. EXIT";
		cout<<"\n Enter your choice - ";
		cin>>ch;
		
		switch(ch)
		{
			case 1: 
					cout<<"\n Enter the number of books to be added - ";
					cin>>n;
					for(i=max; i<max+n; i++)
						b[i].add();
					max += n;
					cout<<"\n Books added sucessfully";
					break;
			case 2:
					cout<<"\n Displaying all books in database";
					cout<<"\nName\tAuthor\tPublisher\tStock\tPrice";		
					for(i=0; i<max; i++)
						b[i].display();
					break;
			case 3:
					Book::flg = 0;
					char *temp;
					temp = new char[100];
					cout<<"\n Enter the name of book you want to search - ";
					cin>>temp;		
					for(i=0; i<max; i++)
						b[i].search(temp);
					if(!Book::flg) cout<<"\nNo books found with name "<<temp;
					delete temp;
					break;
			case 6: 
					return 0;
			default:
					cout<<"\nPlease, enter a valid choice";
		}
	}while(1);
	
	return 0;
}


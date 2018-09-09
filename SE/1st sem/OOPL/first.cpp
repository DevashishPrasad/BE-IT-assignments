#include<stdio.h>
#include<iostream>

using namespace std;
class Weather
{
	int day, ht, lt, sf, rf;
	static int avght, avglt, avgsf, avgrf, cnt;
	
	public:
	
	// Constructor
	Weather()
	{
		day = 9999;
		ht = 9999;
		lt = -9999;
		sf = 9999;
		rf = 9999;
	}
	
	// Functions
	void add_details(int d)
	{
		day = d;
		ht = lt = 0;
		while(ht == 0 && lt == 0)
		{
			cout<<"\nEnter the High Temperature - ";
			cin>>ht;
			cout<<"\nEnter the Low Temperature - ";
			cin>>lt;

			if(ht>=lt)
				break;

			ht = lt = 0;
			cout<<"\nHigh temperature cannot be less than low temperature\nPlease enter the values again";
		}
		cout<<"\nEnter the Snow Fall - ";
		cin>>sf;
		cout<<"\nEnter the Rain Fall - ";
		cin>>rf;
				
	}
	void display()
	{
		cout<<"\n"<< day <<"\t"<< ht <<"\t"<< lt <<"\t"<< sf <<"\t"<< rf;		
	}
	
	void average();
	static void init();
	static void dispAvg();
};
 
int Weather::avght; 
int Weather::avglt;
int Weather::avgsf;
int Weather::avgrf;
int Weather::cnt;

void Weather::init()
{
	avght=0; avglt=0; avgsf=0; avgrf=0; cnt=0;
}
	
void Weather::average()
{
	if(ht != 9999)
	{
		cnt++;
		avght += ht;
		avglt += lt;
		avgsf += sf;
		avgrf += rf;
	}
}
void Weather::dispAvg()
{
	// Handling Floating point exception
	if(cnt)
	{
		avght = avght/cnt;
		avglt = avglt/cnt;
		avgsf = avgsf/cnt;
		avgrf = avgrf/cnt;
		
		cout<<"\nAverage of data - ";
		cout<<"\nHigh Temp - "<< avght;
		cout<<"\nLow Temp - "<< avglt;
		cout<<"\nSnow Fall - "<< avgsf;
		cout<<"\nRain Fall - "<< avgrf;
	}
	else
		cout<<"\n\n\nNo data Available\n\n\n";
}

int main()
{
	int ch, n=0, i, d;
	Weather w[30];
	
	do{
		cout<<"\n-------------- MENU --------------";
		cout<<"\n1. Add Details";
		cout<<"\n2. Display data for Month";
		cout<<"\n3. Display Average";
		cout<<"\n4. Exit";
		cout<<"\n----------------------------------";
		cout<<"\nEnter your choice - ";
		cin>>ch;
		
		switch(ch)
		{
			case 1:
					cout<<"\nEnter the number of days to be populated - ";
					n = 0;
					while(n == 0)
					{
						cin>>n;
						if(n!=0 && n<30)
							break;
						n=0;
						cout<<"\nUnacceptable value, please try again - ";
					}
					for(i=0; i<n; i++)
					{
						cout<<"\n\n\nEnter the Day - ";
						d = 0;
						while(d == 0)
						{
							cin>>d;
							if(d!=0 && d<30)
								break;
							d=0;
							cout<<"\nUnacceptable value, please try again - ";
						}
						w[d-1].add_details(d);
					}
					break;
			case 2:
					cout<<"\nData for the month - ";
					cout<<"\nDAY\tHT\tLT\tSF\tRF";
					for(i=0; i<30; i++)
					{
						w[i].display();
					}
					break;	
			case 3: 
					Weather::init();
					
					for(i=0; i<30; i++)
						w[i].average();
						
					Weather::dispAvg();
					break;	
			case 4:
					return 0;
			default:
					cout<<"\nPlease Select a choice from menu";
		}
	}while(true);
	
	return 0;
}

#include<iostream>
#include <string.h>
#include <fstream>

using namespace std;

class Database{

    char *name;
    char *phone;
    int id;
    long int salary;
    
    public:
    
    friend void createdb(struct database record[100], int n,fstream *fp);
    friend void display(struct database record[100], fstream *fp);
    friend void add(struct database record[100], int n, fstream *fp);
    friend void search(int id, fstream *fp);
    friend void modify(int id, fstream *fp);
    friend void delete(int id, fstream *fp);
};

void createdb(struct database record[100], int n,fstream *fp)
{
	fp = fopen("database.txt","w+");
	struct database student;

    int i,j,flg=0;
    for(i=0; i<n; i++)
    {
        printf("\n\nRecord Number - %d ",i+1);
        printf("\nEnter the id of the employee - ");
        while(1)
        {
            flg = 0;
            scanf ("%d", &record[i].id);
            while(fread(&student, sizeof(struct database),1, fp))
                if(student.id == record[i].id)
                {
                    flg = 1;
                    printf("\nID already exist, please enter another ID -");
					break;
                }
            if(flg == 0) break;

        }
        printf("\nEnter the name of the employee - ");
        scanf ("%s", &record[i].name);
        printf("\nEnter the phone number of the employee - ");
        while(1)
        {
            scanf ("%s", &record[i].phone);
            if(strlen(record[i].phone) == 10) break;
            else printf("\nInvalid phone number, Please try again - ");
        }
        printf("\nEnter the salary of the employee - ");
        scanf ("%ld", &record[i].salary);
		fwrite(&record[i], sizeof(struct database), 1, fp);
    }
	fclose(fp);
}
void display(struct database record[100], fstream *fp)
{
    char ch;
    struct database student;

	fp = fopen("database.txt","r");

	if(fp == NULL) return;
	else
	{
		printf("\nID\tPHONE     \tSALARY\t\tNAME");
		while(fread(&student, sizeof(struct database),1, fp))
		{
			printf("\n%d\t%s\t%ld\t\t%s", student.id, student.phone, student.salary, student.name);
		}
	}
	fclose(fp);
}
void add(struct database record[100], int n, fstream *fp)
{
	struct database student;
    fp = fopen("database.txt","a+");
    int i,flg=0;
    for(i=0; i<n; i++)
    {
        printf("\n\nRecord Number - %d ",i+1);
        printf("\nEnter the id of the employee - ");
        while(1)
        {
            flg = 0;
            scanf ("%d", &record[i].id);
            while(fread(&student, sizeof(struct database),1, fp))
                if(student.id == record[i].id)
                {
                    flg = 1;
                    printf("\nID already exist, please enter another ID -");
					break;
                }
            if(flg == 0) break;
        }
        printf("\nEnter the name of the employee - ");
        scanf ("%s", &record[i].name);
        printf("\nEnter the phone number of the employee - ");
        while(1)
        {
            scanf ("%s", &record[i].phone);
            if(strlen(record[i].phone) == 10) break;
            else printf("\nInvalid phone number, Please try again - ");
        }
        printf("\nEnter the salary of the employee - ");
        scanf ("%ld", &record[i].salary);
		fwrite(&record[i], sizeof(struct database), 1, fp);
    }
	fclose(fp);
}
void search(int id, fstream *fp)
{
	struct database student;
    fp = fopen("database.txt","r");

    int i,val=-1;

    while(fread(&student, sizeof(struct database),1, fp))
        if(student.id == id)
        {
            val = 1;
            break;
        }

    if(val == -1)
        printf("\nNo record found...");
    else
    {
        printf("\nRecord Found");
        printf("\nID\tPHONE     \tSALARY\t\tNAME");
        printf("\n%d\t%s\t%ld",student.id, student.phone, student.salary);
        printf("\t\t");
        puts(student.name);
    }

	fclose(fp);
}
void modify(int id, fstream *fp)
{
	struct database student,s;
    fp = fopen("database.txt","r");
	fstream np = fopen("temp.txt","w");

    int i,val=-1;

    while(fread(&student, sizeof(struct database),1, fp))
	{   
		if(student.id == id)
		{
			printf("\nEnter the name of the employee - ");
			scanf ("%s", &student.name);
			printf("\nEnter the phone number of the employee - ");
			while(1)
			{
				scanf ("%s", &student.phone);
				if(strlen(student.phone) == 10) break;
				else printf("\nInvalid phone number, Please try again - ");
			}
			printf("\nEnter the salary of the employee - ");
			scanf ("%ld", &student.salary);
			fwrite(&student, sizeof(struct database), 1, np);
			continue;
		}
		fwrite(&student, sizeof(struct database),1, np);
	}

	fclose(fp);
	fclose(np);
	remove("database.txt");
	rename("temp.txt","database.txt");
}
void delete(int id, fstream *fp)
{
    struct database student,s;
    fp = fopen("database.txt","r");
	fstream np = fopen("temp.txt","w");

    int i,val=-1;

    while(fread(&student, sizeof(struct database),1, fp))
	{   
		if(student.id == id)
		{
			continue;
		}
		fwrite(&student, sizeof(struct database),1, np);
	}

	fclose(fp);
	fclose(np);
	remove("database.txt");
	rename("temp.txt","database.txt");
}

int main(void) {

	int ch,no=0,i;
    Database records[100];
	fstream fp;

	do{
		printf("\n\n\n ******* MENU ******* ");
		printf("\n 1. Create databse");
		printf("\n 2. Display database");
		printf("\n 3. Add record");
		printf("\n 4. Search record");
		printf("\n 5. Modify record");
		printf("\n 6. Delete record");
		printf("\n 7. exit");
		printf("\n Enter your choice - ");
		scanf("%d",&ch);

		switch(ch)
		{
			case 1:
                    printf("\nCreating new Database - ");
					printf("\nEnter the number of Records to be entered - ");
					scanf("%d",&no);
                    createdb(records, no, &fp);
					break;
			case 2:    
                    display(records, &fp);
					break;
			case 3:
					printf("\nAdding records - ");
					printf("\nEnter the number of Records to be entered - ");
					scanf("%d",&no);
					add(records, no, &fp);
					break;
			case 4:
					printf("\nEnter the ID of the employee to be searched - ");
					scanf("%d",&i);
                    search(i, &fp);
					break;
			case 5:
		            printf("\nEnter the ID of the employee to be modified - ");
					scanf("%d",&i);
                    modify(i, &fp);
					break;
			case 6:

                    printf("\nEnter the ID of the employee to be deleted - ");
					scanf("%d",&i);
                    delete(i, &fp);
                    break;
			case 7:
				return 0;
			default:
				printf("\nPlease select a number form menu - ");
				break;
		}
	}while(1);
	return 0;
}

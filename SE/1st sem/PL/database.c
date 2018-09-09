/*
 ============================================================================
 Name        : database.c
 Author      : Devashish (23364)
 Version     : 1.0
 Copyright   : GNU public
 Description : Database using array of structures
 Problem     : Create a database using array of structures and perform 
               following operations - 
               1. Create database
               2. Display database
               3. Add record
               4. Search record
               5. Modify record
               6. Delete record
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct database{
    char name[100];
    char phone[10];
    int id;
    long int salary;
};

void createdb(struct database record[100], int n)
{
    int i,j,flg=0;
    for(i=0; i<n; i++)
    {
        printf("\n\nRecord Number - %d ",i+1);
        printf("\nEnter the id of the employee - ");
        while(1)
        {
            flg = 0;
            scanf ("%d", &record[i].id);
            for(j = 0; j<i; j++)
                if(record[i].id == record[j].id)
                {
                    flg = 1;
                    printf("\nID already exist, please enter another ID -");
                }
            if(flg == 0) break;
        }
        printf("\nEnter the name of the employee - ");
        // scanf ("%[^\n]%*c", record[i].name);
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
    }
}
void display(struct database record[100], int n)
{
    int i;
    
    printf("\nID\tPHONE     \tSALARY\t\tNAME");
    for(i=0; i<n; i++)
    {
        printf("\n%d\t%s\t%ld",record[i].id, record[i].phone, record[i].salary);
        printf("\t\t");
        puts(record[i].name);
    }
}
int add(struct database record[100], int n)
{
    int i,j,flg=0;
    printf("\n\nRecord Number - %d ",n+1);
    printf("\nEnter the id of the employee - ");
    while(1)
    {
        flg = 0;
        scanf ("%d", &record[n].id);
        for(j = 0; j<i; j++)
            if(record[n].id == record[j].id)
            {
                flg = 1;
                printf("\nID already exist, please enter another ID -");
            }
        if(flg == 0) break;
    }
    printf("\nEnter the name of the employee - ");
    scanf ("%s", &record[n].name);
    printf("\nEnter the phone number of the employee - ");
    while(1)
    {
        scanf ("%s", &record[n].phone);
        if(strlen(record[n].phone) == 10) break;
        else printf("\nInvalid phone number, Please try again - ");
    }
    printf("\nEnter the salary of the employee - ");
    scanf ("%ld", &record[n].salary);
    n++;
    return n;
}
void search(struct database record[100],int no, int id)
{
    int i,val=-1;

    for(i = 0; i<no; i++)
        if(record[i].id == id)
        {
            val = i;
            break;
        }
    
    if(val == -1)
        printf("\nNo record found...");
    else
    {
        printf("\nRecord Found");
        printf("\nID\tPHONE     \tSALARY\t\tNAME");
        printf("\n%d\t%s\t%ld",record[val].id, record[val].phone, record[val].salary);
        printf("\t\t");
        puts(record[val].name);
    }
}
void modify(struct database record[100],int no, int id)
{
    int i,val=-1;

    for(i = 0; i<no; i++)
        if(record[i].id == id)
        {
            val = i;
            break;
        }
    
    if(val == -1)
        printf("\nNo Record  with ID %d Exist...",id);
    else
    {
        printf("\nEnter the name of the employee - ");
        scanf ("%s", &record[val].name);
        printf("\nEnter the phone number of the employee - ");
        while(1)
        {
            scanf ("%s", &record[val].phone);
            if(strlen(record[val].phone) == 10) break;
            else printf("\nInvalid phone number, Please try again - ");
        }
        printf("\nEnter the salary of the employee - ");
        scanf ("%ld", &record[val].salary);
    }
}
void delete(struct database record[100],int no, int id)
{
    int i,val=-1;

    for(i = 0; i<no; i++)
        if(record[i].id == id)
        {
            val = i;
            break;
        }
    
    if(val == -1)
        printf("\nNo Record  with ID %d Exist...",id);
    else
    {
        record[val].id = NULL;
        strcpy(record[val].name, "---");
        strcpy(record[val].phone, "----------");
        record[val].salary = 0;
        printf("\nRecord Deleted");
    }
}

int main(void) {

	int ch,no=0,i;
    struct database records[100];
               
	do{
		printf("\n ******* MENU ******* ");
		printf("\n 1. Create database");
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
                    createdb(records, no);
					break;
			case 2:
                    if(no == 0)
						printf("\nError! Database is empty, please create database and then proceed\n");
					else
                        display(records, no);
					break;
			case 3:
					if(no == 0)
						printf("\nError! Database is empty, please create database and then proceed\n");
					else
                        no = add(records, no);
					break;
			case 4:
					if(no == 0)
						printf("\nError! Database is empty, please create database and then proceed\n");
					else
                    {
                        printf("\nEnter the ID of the employee to be searched - ");
					    scanf("%d",&i);
                        search(records, no, i);  
                    }
					break;
			case 5:
		            if(no == 0)
						printf("\nError! Database is empty, please create database and then proceed\n");
					else
                    {
                        printf("\nEnter the ID of the employee to be modified - ");
					    scanf("%d",&i);
                        modify(records, no, i);  
                    }

					break;
			case 6:
                    
                    if(no == 0)
						printf("\nError! Database is empty, please create database and then proceed\n");
					else
                    {
                        printf("\nEnter the ID of the employee to be deleted - ");
					    scanf("%d",&i);
                        delete(records, no, i);  
                    }

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

/*
 ============================================================================
 Name        : database.c
 Author      : Devashish (23364)
 Version     : 1.0
 Copyright   : GNU Public License
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

typedef struct database
{
    char name[100];
    long int phone;
    float bill;
}user;

void createdb(user record[100], int n)
{
    int i,j,flg=0;
    for(i=0; i<n; i++)
    {
        printf("\n\nRecord Number - %d ",i+1);
        printf("\nEnter the name of the user - ");
        scanf("%s", &record[i].name);
        printf("\nEnter the bill of the user - ");
        scanf("%f", &record[i].bill);
        printf("\nEnter the phone - ");
        scanf("%ld", &record[i].phone);
    }
}
void display(user record[100], int n)
{
    int i;

    printf("\nNAME\tBILL\tPHONE\n");
    for(i=0; i<n; i++)
    {
        printf("\n");
        puts(record[i].name);
        printf("\t%f\t%ld",record[i].bill, record[i].phone);
    }
}
int add(struct database record[100], int n)
{
    printf("\n\nRecord Number - %d ",n);
    printf("\nEnter the name of the user - ");
    scanf("%s", &record[n].name);
    printf("\nEnter the bill of the user - ");
    scanf("%f", &record[n].bill);
    printf("\nEnter the phone - ");
    scanf("%ld", &record[n].phone);
    n++;
    return n;
}
void QuickSort(user record[100],int first,int last)
{
    int i, j, pivot, cmp=0;

    user temp;

    if(first<last)
    {
        pivot=first;
        i=first;
        j=last;

        while(i<j)
        {
            while(strcmp(record[i].name, record[pivot].name) >= 0 && i<last)
                i++;

            while(strcmp(record[j].name, record[pivot].name) < 0)
                j--;

            cmp++;
            if(i<j)
            {
                temp=record[i];
                record[i]=record[j];
                record[j]=temp;
            }
        }

        temp=record[pivot];
        record[pivot]=record[j];
        record[j]=temp;

        QuickSort(record,first,j-1);
        QuickSort(record,j+1,last);
    }
}

int main(void) {

	int ch,no=0;
    struct database records[100];

	do{
		printf("\n\n\n\n ******* MENU ******* ");
		printf("\n 1. Create database");
		printf("\n 2. Display database");
		printf("\n 3. Add record");
		printf("\n 4. Descending order (Quick Sort)");
		printf("\n 5. exit");
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
                        QuickSort(records, 0, no);
                        printf("\n\nSorted records");
                        display(records, no);
                    }
					break;
			case 5:
                    return 0;
			default:
				printf("\nPlease select a number form menu - ");
				break;
		}
	}while(1);
	return 0;
}

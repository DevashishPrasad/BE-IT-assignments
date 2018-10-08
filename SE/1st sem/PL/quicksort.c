/*
 ============================================================================
 Name        : database.c
 Author      : Devashish (23364)
 Version     : 1.0
 Copyright   : GNU Public License
 Description : Database using array of structures
 Problem     : Accept mobile user information eg(mobile, name, bill)
               1. Display the data in descending order of name 
                  using recursive quick sort
               2. Display pivot positioning and its corresponding
                  list in each pass
               3. Display the number of passes and comparisons for
                  different test cases (worst, average, best cases)
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

    printf("\nNAME\t\tBILL\t\t\tPHONE\n");
    for(i=0; i<n; i++)
    {
        printf("\n");
        printf("%s\t\t%f\t\t\t%ld", record[i].name, record[i].bill, record[i].phone);
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

int p = 0, no=0;

void QuickSort(user record[100],int first,int last)
{
    int i, j, k, pivot, cmp=0, swap=0;

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
                swap++;
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

    p++;
    printf("\n PASS %d - ", p);

    for (k = 0; k < no; k++)       
        printf("  %s  ", record[k].name);

    printf("\n Compariosns - %d ", cmp);
    printf("\n Swaps - %d ", cmp);
}

int main(void) {

	int ch;
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

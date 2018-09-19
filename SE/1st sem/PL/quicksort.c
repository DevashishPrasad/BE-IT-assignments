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
        scanf("%f", &record[i].percent);
        printf("\nEnter the phone - ");
        scanf("%ld", &record)
    }
}
void display(user record[100], int n)
{
    int i;

    printf("\nNAME\tBILL\tPHONE");
    for(i=0; i<n; i++)
    {
        printf("\n");
        puts(record[i].name);
        printf("\t%f\t%ld",record[i].roll, record[i].percent);
        // printf("\t\t");
    }
}
int add(struct database record[100], int n)
{
    int i,j,flg=0;
    printf("\n\nRecord Number - %d ",i+1);
    printf("\nEnter the name of the user - ");
    scanf("%s", &record[i].name);
    printf("\nEnter the bill of the user - ");
    scanf("%f", &record[i].percent);
    printf("\nEnter the phone - ");
    scanf("%ld", &record)
    n++;
    return n;
}
void QuickSort(user record[100],int first,int last)
{
   int i, j, pivot, temp;

   if(first<last){
      pivot=first;
      i=first;
      j=last;

      while(i<j){
         while(record[i].name <= record[i] && i<last)
            i++;
         while(record[j].name > record[pivot].name)
            j--;
         if(i<j){
            temp=number[i];
            number[i]=number[j];
            number[j]=temp;
         }
      }

      temp=number[pivot];
      number[pivot]=number[j];
      number[j]=temp;
      quicksort(number,first,j-1);
      quicksort(number,j+1,last);

   }
}

int main(void) {

	int ch,no=0,i;
    struct database records[100];

	do{
		printf("\n\n\n\n ******* MENU ******* ");
		printf("\n 1. Create database");
		printf("\n 2. Display database");
		printf("\n 3. Add record");
		printf("\n 4. Ascending order (Quick Sort)");
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
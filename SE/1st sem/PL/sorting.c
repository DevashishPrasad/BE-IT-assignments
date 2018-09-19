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

struct database{
    char name[100];
    int roll;
    float percent;
};
void createdb(struct database record[100], int n)
{
    int i,j,flg=0;
    for(i=0; i<n; i++)
    {
        printf("\n\nRecord Number - %d ",i+1);
        printf("\nEnter the roll no of the student - ");
        while(1)
        {
            flg = 0;
            scanf ("%d", &record[i].roll);
            for(j = 0; j<i; j++)
                if(record[i].roll == record[j].roll)
                {
                    flg = 1;
                    printf("\nroll no already exist, please enter another roll no-");
                }
            if(flg == 0) break;
        }
        printf("\nEnter the name of the student - ");
        scanf ("%s", &record[i].name);
        printf("\nEnter the percentage of the student - ");
        scanf ("%f", &record[i].percent);
    }
}
void display(struct database record[100], int n)
{
    int i;

    printf("\nROLL\tpercentage\tNAME");
    for(i=0; i<n; i++)
    {
        printf("\n%d\t%f",record[i].roll, record[i].percent);
        printf("\t\t");
        puts(record[i].name);
    }
}
int add(struct database record[100], int n)
{
    int i,j,flg=0;
    printf("\n\nRecord Number - %d ",n+1);
    printf("\nEnter the roll of the student - ");
    while(1)
    {
        flg = 0;
        scanf ("%d", &record[n].roll);
        for(j = 0; j<i; j++)
            if(record[n].roll == record[j].roll)
            {
                flg = 1;
                printf("\nRoll no already exist, please enter another Roll no -");
            }
        if(flg == 0) break;
    }
    printf("\nEnter the name of the student - ");
    scanf ("%s", &record[n].name);
    
    printf("\nEnter the percentage of the student - ");
    scanf ("%ld", &record[n].percent);
    n++;
    return n;
}
void selectionSort(struct database record[100], int n)
{
    int i, j, k, max_idx, swap=0, com=0;
    struct database temp;

    printf("\nInitial - ");
    for (k = 0; k < n; k++)       
        printf("%d ", record[k].roll);

    for (i = 0; i < n-1; i++)
    {
        max_idx = i;
        for (j = i+1; j < n; j++)
        {
            com++;
            if (record[j].roll > record[max_idx].roll)
            {
                max_idx = j;
            }
        }
         
        swap++;
        temp = record[i];
        record[i] = record[max_idx];
        record[max_idx] = temp;

        printf("\nPASS %d - ",i);
        for (k = 0; k < n; k++)       
            printf("%d ", record[k].roll);
    }
    printf("\nComparisons - %d",com);
    printf("\nSwaps - %d",swap);
}

void bubbleSort(struct database record[100], int n)
{
    int i, j, k,com=0,swap=0;
    struct database temp;

    printf("\nInitial - ");
    for (k = 0; k < n; k++)       
        printf("%d ", record[k].roll);

    for (i = 0; i < n-1; i++)       
    {    
        for (j = 0; j < n-i-1; j++) 
        {
            com++;
            if (record[j].roll > record[j+1].roll)
            {
                swap++;
                temp = record[j];
                record[j] = record[j+1];
                record[j+1] = temp;
            }
        }

        printf("\nPASS %d - ",i);
        for (k = 0; k < n; k++)       
           printf("%d ", record[k].roll);
    }

    printf("\nComparisons - %d",com);
    printf("\nSwaps - %d",swap);
}

void binarySearch(struct database record[100], int no, int search)
{
    bubbleSort(record, no);
    int c, first, last, middle;
    
    first = 0;
    last = no - 1;
    middle = (first+last)/2;
    
    while (first <= last) 
    {
        if (record[middle].roll < search)
            first = middle + 1;    
        else if (record[middle].roll == search) 
        {
            printf("\n\n%d found at location %d.\n", search, middle+1);
            break;
        }
        else
            last = middle - 1;
    
        middle = (first + last)/2;
    }
    if (first > last)
        printf("\n\nNot found! %d isn't present in the database.\n", search);
}

void binSearch(struct database record[100], int no, int search, int first, int last)
{
    bubbleSort(record, no);
    int middle;
    middle = (first+last)/2;
    
    if (first == last)
    {
        printf("\n\nNot found! %d isn't present in the database.\n", search);
        return;
    }
    else if (record[middle].roll == search) 
    {
        printf("\n\n%d found in the list\n", search);
        return;
    }
    else if (record[middle].roll < search)
    {
        first = middle + 1;
        binSearch(record, no/2, search, first, last);
    }
    else
    {
        first = 0;
        last = middle - 1;
        binSearch(record, no/2, search, first, last);
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
		printf("\n 4. Ascending order (Bubble Sort)");
		printf("\n 5. Descending order (Selection Sort)");
		printf("\n 6. Search (Binary Search)");
        printf("\n 7. Search (Binary Search recursion)");
		printf("\n 8. exit");
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
                        bubbleSort(records, no);
                        printf("\n\nSorted records");
                        display(records, no);
                    }
					break;
			case 5:
		            if(no == 0)
						printf("\nError! Database is empty, please create database and then proceed\n");
					else
                    {
                        selectionSort(records, no);
                        printf("\n\nSorted records");
                        display(records, no);
                    }

					break;
			case 6:
                    if(no == 0)
						printf("\nError! Database is empty, please create database and then proceed\n");
					else
                    {
                        printf("\nEnter the roll of the student to be searched - ");
					    scanf("%d",&i);
                        binarySearch(records, no, i);
                    }
					break;
			case 7:
                    if(no == 0)
						printf("\nError! Database is empty, please create database and then proceed\n");
					else
                    {
                        printf("\nEnter the roll of the student to be searched - ");
					    scanf("%d",&i);
                        bubbleSort(records, no);
                        binSearch(records, no, i, 0, no/2);
                    }
					break;
			case 8:
                    return 0;
			default:
				printf("\nPlease select a number form menu - ");
				break;
		}
	}while(1);
	return 0;
}


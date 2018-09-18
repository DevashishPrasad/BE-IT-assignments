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

// void selectionSort(int arr[], int n)
// {
//     int i, j, min_idx;
 
//     // One by one move boundary of unsorted subarray
//     for (i = 0; i < n-1; i++)
//     {
//         // Find the minimum element in unsorted array
//         min_idx = i;
//         for (j = i+1; j < n; j++)
//           if (arr[j] < arr[min_idx])
//             min_idx = j;
 
//         // Swap the found minimum element with the first element
//         swap(&arr[min_idx], &arr[i]);
//     }
// }
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
    printf("\nEnter the phone number of the student - ");
    
    printf("\nEnter the percentage of the student - ");
    scanf ("%ld", &record[n].percent);
    n++;
    return n;
}
void search(struct database record[100],int no, int roll)
{
    int i,val=-1;

    for(i = 0; i<no; i++)
        if(record[i].roll == roll)
        {
            val = i;
            break;
        }

    if(val == -1)
        printf("\nNo record found...");
    else
    {
        printf("\nRecord Found");
        printf("\nroll\tPHONE     \tSALARY\t\tNAME");
        printf("\n%d\t%s\t%ld",record[val].roll, record[val].phone, record[val].salary);
        printf("\t\t");
        puts(record[val].name);
    }
}

void swap(struct database *record1, struct database *record2)
{
    struct database *temp;
    temp = record1;
    record1 = record2;
    record2 = temp;
}
 
void bubbleSort(struct database record[100], int n)
{
   int i, j;
   for (i = 0; i < n-1; i++)       
       for (j = 0; j < n-i-1; j++) 
           if (record[j].roll > record[j+1].roll)
              swap(&record[j], &record[j+1]);
}

int main(void) {

	int ch,no=0,i;
    struct database records[100];

	do{
		printf("\n\n\n ******* MENU ******* ");
		printf("\n 1. Create database");
		printf("\n 2. Display database");
		printf("\n 3. Add record");
		printf("\n 4. Ascending order (Bubble Sort)");
		printf("\n 5. Descending order (Selection Sort)");
		printf("\n 6. Search (Binary Search)");
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
                        bubbleSort(records, no);
                        display(records, no);
                    }
					break;
			// case 5:
		    //         if(no == 0)
			// 			printf("\nError! Database is empty, please create database and then proceed\n");
			// 		else
            //         {
            //             printf("\nEnter the roll of the student to be modified - ");
			// 		    scanf("%d",&i);
            //             modify(records, no, i);
            //         }

			// 		break;
			// case 6:

            //         if(no == 0)
			// 			printf("\nError! Database is empty, please create database and then proceed\n");
			// 		else
            //         {
            //             printf("\nEnter the roll of the student to be deleted - ");
			// 		    scanf("%d",&i);
            //             no = delete(records, no, i);
            //         }

			// 		break;
			case 7:
				return 0;
			default:
				printf("\nPlease select a number form menu - ");
				break;
		}
	}while(1);
	return 0;
}


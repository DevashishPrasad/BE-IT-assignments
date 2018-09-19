#include <iostream>

using namespace std;

template <class T>
class Matrix
{
    T *a, *b, *c;
    int r1, c1, r2, c2;

    public:
    
    Matrix(int ro1, int co1, int ro2, int co2)
    {
        r1 = ro1;
        r2 = ro2;
        c1 = co1;
        c1 = co2;

        a = new T[r1][c1];
        b = new T[r2][c2];
    }
    void display()
    {
        int i,j;
        printf("\n");
        for(i=0; i<r1; i++)
        {
            for(j=0; j<c1; j++)
            {
                printf(" %d ", a[i][j]);
            }
            printf("\n");
        }
    }

    void getmat()
    {
        int i,j;
        for(i=0; i<r1; i++)
        {
            for(j=0; j<c1; j++)
            {
                printf("\nElement [%d][%d] - ",i,j);
                scanf("%d", &a[i][j]);
            }
        }
        return;
    }

    void addition(int a[10][10], int b[10][10], int c[10][10], int r1, int c1, int r2, int c2)
    {
        int i,j;

        if(r1 != r2 && c1 != c2)
        {
            printf("\nError! cannot add matrices");
            return;
        }

        for(i=0; i<r2; i++)
        {
            for(j=0; j<c2; j++)
            {
                c[i][j] = a[i][j] + b[i][j];
            }
        }

        return;
    }

    void subtraction(int a[10][10], int b[10][10], int c[10][10], int r1, int c1, int r2, int c2)
    {
        int i,j;

        if(r1 != r2 && c1 != c2)
        {
            printf("\nError! cannot subtract matrices");
            return;
        }

        for(i=0; i<r2; i++)
        {
            for(j=0; j<c2; j++)
            {
                c[i][j] = a[i][j] - b[i][j];
            }
        }
    }

    void multiplication(int a[10][10], int b[10][10], int c[10][10], int r1, int c1, int r2, int c2)
    {
        int i,j,k;

        if(c1 != r2)
        {
            printf("\nError! cannot multiply matrices");
            return;
        }

        for(i=0; i<r2; i++)
        {
            for(j=0; j<c2; j++)
            {
                c[i][j] = 0;
            }
        }

        for(i=0; i<r2; i++)
        {
            for(j=0; j<c2; j++)
            {
                for(k=0; k<c2; k++)
                {
                    c[i][j] = c[i][j] + a[i][k]*b[k][j];
                }
            }
        }
    }
    void transpose(int a[10][10], int c[10][10], int r1, int c1, int r2, int c2)
    {
        int i,j;

        for(i=0; i<r1; i++)
        {
            for(j=0; j<c1; j++)
            {
                c[i][j] = a[j][i];
            }
        }
        return;
    }

    void saddle(int a[10][10], int r1, int c1)
    {
        int i, j, ind=0, k, min, max, flg=0;

        for(i=0; i<r1; i++)
        {
            min = a[i][0];
            for(j=0; j<c1; j++)
            {
                if(min > a[i][j])
                {
                    min = a[i][j];
                    ind = j;
                }
            }
            max = a[0][ind];
            for(k=0; k < r1; k++)
            {
                if(max < a[k][ind])
                {
                    max = a[k][ind];
                }
            }

            if(min == max)
            {
                flg = 1;
                printf("\n %d \n",min);
            }
        }

        if(flg == 0)
            printf("\n Not found");

    }
};
int main(void) {

	int ch;
	int a[10][10], b[10][10], c[10][10];
	int r1=0, c1=0, r2=0, c2=0;


	do{
		printf("\n MENU - ");
		printf("\n 1. Display");
		printf("\n 2. Populate Matrices");
		printf("\n 3. Addition");
		printf("\n 4. Subtraction");
		printf("\n 5. Multiplication");
		printf("\n 6. Transpose");
		printf("\n 7. Saddle point");
		printf("\n 8. exit");
		printf("\nEnter your choice - ");

		scanf("%d",&ch);

		switch(ch)
		{
			case 1:
				if(r1 == 0 || r2 == 0 || c1 == 0 || c2 == 0)
					printf("\n\nError! Matrices are empty");
				else
				{
					printf("\n Matrix A - ");
					display(a, r1, c1);
					printf("\n Matrix B - ");
					display(b, r2, c2);
				}
				break;

			case 2:
				printf("\nEnter the number rows of Matrix A - ");
				scanf("%d",&r1);
				printf("\nEnter the number columns of Matrix A - ");
				scanf("%d",&c1);
				printf("\nEnter the number rows of Matrix B - ");
				scanf("%d",&r2);
				printf("\nEnter the number columns of Matrix B - ");
				scanf("%d",&c2);
				printf("\n Enter the Elements in matrix A - ");
				getmat(a, r1, c1);
				printf("\n Enter the Elements in matrix B - ");
				getmat(b, r2, c2);
				break;

			case 3:
				if(r1 == 0 || r2 == 0 || c1 == 0 || c2 == 0)
					printf("\n\nError! Matrices are empty");
				else
				{
					printf("\n\nAddition of your matrices - \n");
					addition(a, b, c, r1, c1, r2, c2);
					display(c, r1, c1);
				}
				break;

			case 4:
				if(r1 == 0 || r2 == 0 || c1 == 0 || c2 == 0)
					printf("\n\nError! Matrices are empty");
				else
				{
					printf("\n\nSubtraction of your matrices (A - B)- \n");
					subtraction(a, b, c, r1, c1, r2, c2);
					display(c, r1, c1);
					printf("\n\nSubtraction of your matrices (B - A)- \n");
					subtraction(b, a, c, r1, c1, r2, c2);
					display(c, r1, c1);
				}
				break;

			case 5:
				if(r1 == 0 || r2 == 0 || c1 == 0 || c2 == 0)
					printf("\n\nError! Matrices are empty");
				else
				{
					printf("\n\nMultiplication of your matrices (A * B)- \n");
					multiplication(a, b, c, r1, c1, r2, c2);
					display(c, r2, c1);
					printf("\n\nMultiplication of your matrices (B * A)- \n");
					multiplication(b, a, c, r1, c1, r2, c2);
					display(c, r2, c1);
				}
				break;

			case 6:
				if(r1 == 0 || r2 == 0 || c1 == 0 || c2 == 0)
					printf("\n\nError! Matrices are empty");
				else
				{
					printf("\n Transpose of A - \n");
					transpose(a, c, r1, c1, r2, c2);
					display(c, r2, c1);
					printf("\n Transpose of B - \n");
					transpose(b, c, r1, c1, r2, c2);
					display(c, r2, c1);
				}
				break;

			case 7:
				if(r1 == 0 || r2 == 0 || c1 == 0 || c2 == 0)
					printf("\n\nError! Matrices are empty");
				else
				{
					printf("\n Saddle of A - \n");
					saddle(a, r1, c1);
					printf("\n Saddle of B - \n");
					saddle(b, r2, c2);
				}
				break;

			case 8:
				exit(0);

			default:
				printf("\nPlease select a number from menu - ");
		}
	}while(1);
}

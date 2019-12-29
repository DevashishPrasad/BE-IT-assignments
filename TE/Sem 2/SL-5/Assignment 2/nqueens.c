#include<stdlib.h>
#include<stdio.h>
#include<math.h>

// Declare global variables
int no_queens,size_chessboard;
// Declare the chessboard
int chessboard[100][100];
// Declare the queens
int queens[50][2];

void print_board(){
	int i,j,k;
	// Place queens on chessboard
	for(k=0;k<no_queens;k++){
		if(queens[k][0] != -1 && queens[k][1] != -1)
			chessboard[queens[k][0]][queens[k][1]] = 1;
	}
	
	// Print the positions
	for(j=0;j<size_chessboard;j++)
			printf("----");
	for(i=0;i<size_chessboard;i++){
		printf("\n|");
		for(j=0;j<size_chessboard;j++){
			printf(" %d |",chessboard[i][j]);
		}
		printf("\n");	
		for(j=0;j<size_chessboard;j++)
			printf("----");
	}
	printf("\n");
}

int check_queens(int check_i,int check_j,int qno){
	int k;
	// Place queens on chessboard
	//for(k=0;k<no_queens;k++){
		//check_i = queens[k][0];
		//check_j = queens[k][1]; 
		for(k=0;k<no_queens;k++){
			if(chessboard[check_i][check_j] == 1){
				printf("\n\nOccupied pos\n");
				printf("queen =  %d %d \n",check_i,check_j);				
				return 0;
			}	
			if(queens[k][0] == -1)
				continue;
			if(k == qno)
				continue;
			if(queens[k][0] == check_i){
				printf("\n\nUnplausible row\n");
				printf("queen =  %d %d \n",check_i,check_j);				
				return 0;
			}
			if(queens[k][1] == check_j){
				printf("\n\nUnplausible col\n");
				printf("queen =  %d %d \n",check_i,check_j);				
				return 0;
			}
			if((abs(queens[k][0] - check_i) - abs(queens[k][1] - check_j)) == 0){
				printf("\n\nUnplausible digonal\n");	
				printf("queen =  %d %d \n",check_i,check_j);				
				return 0;
			}
		}	
	//}		
	
	return 1;
}

void main(){
	// Variables for the program
	int i,j,k,flg;
	printf("===========================  N Queens Program ==========================");

	printf("\n Enter the number of queens : ");
	scanf("%d",&no_queens);
	printf("\n Enter the size of chessboard : ");
	scanf("%d",&size_chessboard);
			
	// Initialize the arrays
	for(i=0;i<size_chessboard;i++)
		for(j=0;j<size_chessboard;j++)
			chessboard[i][j] = 0;

	// Initialize the arrays
	for(i=0;i<no_queens;i++)
		for(j=0;j<2;j++)
			queens[i][j] = -1;		

	// Algorithm
	for(i=0;i<no_queens;i++){
		// traverse chess
		printf("\nProcessing queen number %d",i);
		flg = 1;
		for(j=0;j<size_chessboard;j++){
			if(flg == 0){
				printf("\n Taking next queen");
				break;
			}
			for(k=0;k<size_chessboard;k++){
				printf("\n %d [%d %d]",i,j,k);
				queens[i][0] = j;
				queens[i][1] = k;			
				if(!check_queens(j,k,i)){
					queens[i][0]= -1;
					queens[i][1]= -1;				
				}
				else{
					printf("\n Queen placed at location - %d %d \n",queens[i][0],queens[i][1]);
					chessboard[queens[i][0]][queens[i][1]]=1;
					print_board();
					flg=0;
					break;
				}
			}
		}	
	}
	/*queens[2][0] = 1;
	queens[2][1] = 3;	
	
	queens[0][0] = 2;
	queens[0][1] = 2;	*/
	
	//place_queens();
	print_board(chessboard,queens);
}

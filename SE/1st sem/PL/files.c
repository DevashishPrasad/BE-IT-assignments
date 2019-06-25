/*
 ============================================================================
 Name        : files.c
 Author      : Devashish
 Version     : 1.0
 Copyright   : GNU Public License
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

int main(int argc, char *argv[]) {
	char ch;
	FILE *fp1,*fp2;

	if(argc > 1)
	{
		if(!strcmp(argv[1],"type") || !strcmp(argv[1],"t"))
		{
			if(argv[2] != NULL)
			{
				fp1 = fopen(argv[2],"r");
				if(fp1 == NULL)
				{
					printf("\nFile specified does not exist");
					return 0;
				}
				else
				{
					ch = getc(fp1);
					while(ch != EOF)
					{
						printf("%c",ch);
						ch = getc(fp1);
					}
				}
				fclose(fp1);
			}
			else
				printf("\nPlease specify filename to read");
		}
		else if(!strcmp(argv[1],"copy") || !strcmp(argv[1],"c"))
		{
			if(argv[2] != NULL && argv[3] != NULL)
			{
				fp1 = fopen(argv[2],"r");
				fp2 = fopen(argv[3],"w");
				if(fp1 == NULL)
				{
					printf("\nFile specified to read does not exist");
					return 0;
				}
				else
				{
					ch = getc(fp1);
					while(ch != EOF)
					{
						putc(ch,fp2);
						ch = getc(fp1);
					}
				}
				printf("\nFile Copied successfully");
				fclose(fp1);
				fclose(fp2);
			}
			else
				printf("\nPlease specify file names to read and write");
		}
		else
			printf("\nInvalid argument");
	}
	else
		printf("\nCommand line arguments missing");

	return EXIT_SUCCESS;
}

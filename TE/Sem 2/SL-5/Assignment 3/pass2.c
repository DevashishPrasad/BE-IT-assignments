#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include<string.h>

// Data Structure for Machine Code 
typedef struct machine_code{
	int LC;
	int Opcode;
	int Reg;
	int Mem;
}mc;

typedef struct table{
	char symbol[20];
	int size;
	int address;
}tab;

// Main function
void main(int argc, char *argv[]){
	time_t t;
    time(&t);
	int verbose;
	
	// Check commandline arguments
	if(argc < 2){
		printf("[ERROR] Please specify input program file \n\n");
		return;
	}
	else if(argc == 2)
		verbose = 0;
	else if(argc == 3)
		verbose = atoi(argv[2]);

	if(verbose){
		printf("=========================== PASS 2 ASSEMBLER ==========================");
		printf("\n %s ",ctime(&t));
	}
	
	// Variables for the program
	mc mc_line;
	tab sym_table[10],lit_table[10];	
	FILE *read_IC, *read_sym, *read_lit, *write_MC;
	char ch,buffer1D[40];
	int i,j,k,count;
				
	// Open the IC file for reading
	read_IC = fopen(argv[1],"r");

	// Creating and opening the file for writing symbol table
	write_MC = fopen("mc.txt","w");    

	// Opening the file for reading symbol table
	read_sym = fopen("symbol.txt","r");
	
	// Initialize arrays
	for(i=0;i<10;i++){
		strcpy(sym_table[i].symbol,"\0");
		sym_table[i].size = -99;
		sym_table[i].address = -99;
		
		strcpy(lit_table[i].symbol,"\0");
		lit_table[i].size = -99;
		lit_table[i].address = -99;
	}		

	// Populate symbol table
	ch = fgetc(read_sym);
	count = 0;
	i = 0;
	j = 0;
	while(ch != EOF){
		if(count == 1 && !sym_table[i].symbol[0]){
			strcpy(sym_table[i].symbol,buffer1D);
			for(k=0;k<40;k++)
				buffer1D[k] = '\0';
		}
		if(ch == '\n' && sym_table[i].size == -99){
			sym_table[i].size = atoi(buffer1D);
			for(k=0;k<40;k++)
				buffer1D[k] = '\0';
		}
		if(count == 2 && sym_table[i].address == -99){
			sym_table[i].address = atoi(buffer1D);
			for(k=0;k<40;k++)
				buffer1D[k] = '\0';
		}		
		if(ch == ','){
			count++;
			j=0;
		}
		else if(ch == '\n'){
			count = 0;
			j=0;
			i++;
			for(k=0;k<20;k++)
				buffer1D[k] = '\0';		
		}
		else{
			buffer1D[j] = ch;
			j++;
		}
		
		ch = fgetc(read_sym);
	}
	
		 
	// Opening the file for reading literal table
	read_lit = fopen("literal.txt","r");

	// Populate literal table
	ch = fgetc(read_lit);
	count = 0;
	i = 0;
	j = 0;
	while(ch != EOF){
		if(count == 1 && !lit_table[i].symbol[0]){
			strcpy(lit_table[i].symbol,buffer1D);
			for(k=0;k<40;k++)
				buffer1D[k] = '\0';
		}
		if(ch == '\n' && lit_table[i].size == -99){
			lit_table[i].size = atoi(buffer1D);
			for(k=0;k<40;k++)
				buffer1D[k] = '\0';
		}
		if(count == 2 && lit_table[i].address == -99){
			lit_table[i].address = atoi(buffer1D);
			for(k=0;k<40;k++)
				buffer1D[k] = '\0';
		}		
		if(ch == ','){
			count++;
			j=0;
		}
		else if(ch == '\n'){
			count = 0;
			j=0;
			if(lit_table[i].address != -99)
				i++;
			for(k=0;k<20;k++)
				buffer1D[k] = '\0';		
		}
		else{
			buffer1D[j] = ch;
			j++;
		}
		
		ch = fgetc(read_lit);
	}
			
	// Initialize the mc_line
	mc_line.LC = -99;
	mc_line.Opcode = -99;
	mc_line.Reg = -99;
	mc_line.Mem = -99;
    
    // Reading the data using fgetc() method
   	ch = fgetc(read_IC);
   	count = 0;
    while(ch != EOF){
    	if(count == 1 && mc_line.LC == -99){
    		 mc_line.LC = atoi(buffer1D);   		    	
    		 for(j=0;j<40;j++)
				buffer1D[j] = '\0';	
			i=0;
    	}
    	else if(count == 2 && mc_line.Opcode == -99){
    		// Skip Assembler directives
    		if(buffer1D[0] == 'A'){
    			while(ch != '\n')
    				ch = fgetc(read_IC);
    		}
    		// Skip Declarations    		
    		else if(buffer1D[0] == 'D'){
    			while(ch != '\n')
    				ch = fgetc(read_IC);
       		}
    		// Skip IS,
    		else if(buffer1D[0] == 'I'){
    			j = 0;
    			while(buffer1D[j] != ',')
    				j++;
    			j++;
				count = j;
    			while(buffer1D[j]){
    				buffer1D[j - count] = buffer1D[j];
    				j++;
    			}
    			buffer1D[j - count] = '\0';		
	    		mc_line.Opcode = atoi(buffer1D);
	    	}
	    	// Empty the buffer
			for(j=0;j<40;j++)
				buffer1D[j] = '\0';
			i=0;
	    	count = 2;
    	}
    	else if(count >= 3){
	    	if(buffer1D[0] == 'S' && mc_line.Mem == -99 && strlen(buffer1D)>2){
				j = 0;
    			while(buffer1D[j] != ',')
    				j++;	
    			j++;				
    			i = j;		
    			while(buffer1D[j]){
    				buffer1D[j - i] = buffer1D[j];
    				j++;
    			}
    			buffer1D[j - i] = '\0';
	    		mc_line.Mem = sym_table[atoi(buffer1D)].address;
	    	}
	    	if(buffer1D[0] == 'L' && mc_line.Mem == -99 && strlen(buffer1D)>2){
				j = 0;
    			while(buffer1D[j] != ',')
    				j++;	
    			j++;				
    			i = j;		
    			while(buffer1D[j]){
    				buffer1D[j - i] = buffer1D[j];
    				j++;
    			}
    			buffer1D[j - i] = '\0';
	    		mc_line.Mem = lit_table[atoi(buffer1D)].address;
	    	}
	    	else if(mc_line.Reg == -99 ){
	    		mc_line.Reg = atoi(buffer1D);	
				// Empty the buffer
				for(j=0;j<40;j++)
					buffer1D[j] = '\0';
				i=0;    	
			}
    	}
		if(ch == '\n'){
			count = 0;

			if(mc_line.Opcode != -99){
				// Write the Machine Code line in the output file
				fprintf(write_MC,"%d ",mc_line.LC);
				fprintf(write_MC," %d ",mc_line.Opcode);
				if(mc_line.Reg == -99)
					fprintf(write_MC," 0 ");
				else
					fprintf(write_MC," %d ",mc_line.Reg);			
				if(mc_line.Mem == -99)
					fprintf(write_MC," 0 ");
				else					
					fprintf(write_MC," %d ",mc_line.Mem);			
				fprintf(write_MC,"\n");	
			}		

			// Empty the buffer
			for(j=0;j<40;j++)
				buffer1D[j] = '\0';
			
			// Initialize the mc_line
			mc_line.LC = -99;
			mc_line.Opcode = -99;
			mc_line.Reg = -99;
			mc_line.Mem = -99;
			
			i=0;
		}
		else if(ch == ' ' || ch == ')'){
			count++;
		}
		else if(ch != '('){
			buffer1D[i] = ch;
			i++;
		}
		// Read character by character
		ch = fgetc(read_IC);
	}	 

	// Cleanup
	fclose(read_IC);
	fclose(read_lit);
	fclose(read_sym);
	fclose(write_MC);
}

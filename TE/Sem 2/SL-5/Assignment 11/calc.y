%{
#include<stdio.h>
%}
%token NUMBER
%left '-' '+'
%left '*' '/'
%left '!'
%nonassoc UMINUS
%%
S	:	exp	{printf("Result is=%d\n",$1); }
exp	:	exp '+' exp {$$ = $1 + $3; }
	|	exp '-' exp {$$ = $1 - $3; }
	|	exp '*' exp {$$ = $1 * $3; }
	|	exp '/' exp {$$ = $1 / $3; }
	|	'-' exp %prec UMINUS {$$ = -$2; }
	|	'(' exp ')' {$$ = $2; }
	|	NUMBER {$$ = $1; }
	| 	exp '!' {$$ = factorial($1);}
%%
int main()
{
printf("\nEnter the Expression:->");
yyparse();
}
int factorial(int num)
{
if(num>1)
	return num*factorial(num-1);
else
	return 1;
}
int yyerror()
{
}
int yywrap()
{
return 1;
}


/*
OUTPUT:
pict@pict-OptiPlex-5060:~/Desktop$ byacc -d calc.y
pict@pict-OptiPlex-5060:~/Desktop$ flex calc.l
pict@pict-OptiPlex-5060:~/Desktop$ gcc lex.yy.c y.tab.c
pict@pict-OptiPlex-5060:~/Desktop$ ./a.out

Enter the Expression:->3+2*5
Result is=13
*/

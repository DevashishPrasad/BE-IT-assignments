/*
Name: Prajakta Rajendra Bhosale.
Roll No:3011
Batch: K-10
Problem Statement:Write a program for imntermediate code generation using LEX and YACC for control flow statement (while loop or switch case).
*/
ALPHA [A-Za-z]
DIGIT [0-9]
%%
while                return WHILE;
{ALPHA}({ALPHA}|{DIGIT})*    return ID;
{DIGIT}+             {yylval=atoi(yytext); return NUM;}
[ \t]                 ;
\n                yyterminate();
.                 return yytext[0];
%%

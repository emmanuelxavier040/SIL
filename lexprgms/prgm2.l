%option noyywrap

%{
	#include <stdlib.h>
	#include <stdio.h>
	char *file1;
%}

number [0-9]+

%%

{number} {printf("Found : %d",atoi(yytext));}

%%

int main()
{
	file1 = "input_1";
	yyin = fopen(file1,"r");
	yylex();	
	return 1;
}
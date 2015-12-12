
%{
	#include <stdio.h>
	int global_variable;	
%}

	number [0-9]+
	op [-|+|*|/|^|=]

%%

	{number} {printf("number");}
	{op} {printf("operator");}

%%

int main()
{
	yylex();
	return 1;
}
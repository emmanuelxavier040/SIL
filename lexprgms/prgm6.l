
%{
	#include <stdlib.h>
	#include <stdio.h>
	int count;
%}

number [0-9]+

%%

{number} {printf("Found : %d",atoi(yytext));}

%%

int yywrap()
{
	
	if(count < 2)
	{
		count++;
		return 0;
	}
	else
	{
		return 1;
	}
}

int main()
{
	count = 1;
	yylex();	
	return 1;
}
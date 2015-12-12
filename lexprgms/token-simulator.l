
%{

	#include <stdlib.h>
	#include <stdio.h>


%}


low [a-z]
upp [A-Z]
number [0-9]


%option noyywrap

%%

({low}|{upp})({low}|{upp})*({number}) 	{return 1;}
(.)* 									{return -1;}

%%


int main()
{
	int token = yylex();
	if(token == 1)
		printf("Accept\n");
	else
		printf("Reject\n");		
	return 1;
}
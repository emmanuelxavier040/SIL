%{

	#include <stdio.h>
	#include <stdlib.h>

	int number_1;
	int number_2;

%}

number [0-9]+

%%

{number}[0|2|4|6|8] {	printf("Even number: ");					
						return atoi(yytext);
					}

{number}[1|3|5|7|9] {	printf("Odd number: ");					
						return atoi(yytext);
					}

%%

int yywrap()
{
	return 1;
}


int main()
{
	number_1 = yylex();
	number_2 = yylex();
	return 1;
}
%{

	#include <stdio.h>
	int int_count = 0;
	int float_count = 0;

%}

%option noyywrap

num [0-9]
point "."
rest [0-9|a-z|A-Z|"\n"|" "]

%%

({num})({num})*							{int_count++;}
({num})({num})*({point})({num})({num})* {float_count++;}
{rest} 									{}

%%

int main()
{
	yylex();
	printf("Number of integers: %d\n",int_count);
	printf("Number of floating point numbers: %d\n",float_count);
	return 1;
}
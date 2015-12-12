%{

	#include <stdio.h>

%}

%option noyywrap

start "A"
rest [a-z|A-Z]
end "\n"
space " "

%%

({start})({rest})({rest})({end}|{space})		{printf("%s\n",yytext);}
({space})|({rest})*								{}

%%

int main()
{
	yylex();
	return 1;
}
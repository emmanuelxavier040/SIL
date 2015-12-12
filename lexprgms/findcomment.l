%{	

	#include <stdio.h>

%}

%option noyywrap


start "//"
start1 "/*"
end1 "*/"
newline "\n"
txt [a-z|A-Z|0-9|" "]

%%

({start})({txt})*						{printf("%s\n",yytext);}
({start1})({txt}|{newline})*({end1})	{printf("%s\n",yytext);}
({txt})*								{}
%%



int main()
{
	yylex();
	return 1;
}
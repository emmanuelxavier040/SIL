%{
	#include <stdio.h>
	#include "y.tab.h"
%}

number [0-9]+

%%

{number}	{yylval = atoi(yytext); return DIGIT;}
"+"			return *yytext;
"-"			return *yytext;
"*"			return *yytext;
"/"			return *yytext;
"("			return *yytext;
")"			return *yytext;
"\n"		return *yytext;

%%

yywrap()
{	
	return 1;
}
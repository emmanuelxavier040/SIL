%{
	#include <stdio.h>
	#include <malloc.h>
	#include <string.h>
	#include "y.tab.h"
	
	#define YYSTYPE char*
%}



%%

[a-z|A-Z|0-9]+	{yylval=(char*)malloc(sizeof(char)); strcpy(yylval,yytext); return DIGIT;}
"+"				return *yytext;
"-"				return *yytext;
"*"				return *yytext;
"/"				return *yytext;
"\n"			return *yytext;
"("				return *yytext;
")"				return *yytext;

%%

yywrap()
{	
	return 1;
}
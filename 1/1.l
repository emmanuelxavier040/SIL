%{
	#include <stdio.h>
	#include <malloc.h>
	#include <stdbool.h>
	#include "y.tab.h"
	#include "var.h"

	#define YYSTYPE char*
	char* ptr;

%}

number 	[0-9]+
id 		[a-zA-Z]

%%

"begin"		return BEGN;
"end"		return END;
"decl"		return DECL;
"enddecl"	return ENDDECL;
"integer"	return INTEGER;
"boolean"	return BOOLEAN;
"if"		return IF;
"then"		return THEN;
"endif"		return ENDIF;	
"else"		return ELSE;
"while"		return WHILE;
"do"		return DO;
"endwhile"	return ENDWHILE;
"read"		return READ;
"write"		return WRITE;
"return"	return RETURN;
"=="		return EQEQ;
"!=" 		return NOTEQ;


{number}	{ptr = (char*)malloc(sizeof(char)); strcpy(ptr,yytext); yylval = ptr; return ID;}
({id})({id}|{number})*  {ptr = (char*)malloc(sizeof(char)); strcpy(ptr,yytext); yylval = ptr; return ID;}




[ \t] 			{}
.				return *yytext;
"\n"			{}

%%

yywrap()
{	
	return 1;
}
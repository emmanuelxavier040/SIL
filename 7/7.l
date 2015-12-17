%{
	#include <stdio.h>
	#include <stdbool.h>
	#include <malloc.h>
	#include "y.tab.h"
	#include "var.h"

	
	struct Tnode* ptr;

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
"<="		return LSEQ;
">="		return GREQ;
">"			return GRTHAN;
"<"			return LSTHAN;
"&&"		return AND;
"||"		return OR;
"!"			return NOT;


"true"					{ptr=(struct Tnode *)malloc(sizeof(struct Tnode));
						 ptr->datavalue.b = (bool*)malloc(sizeof(bool)); 
						 *(ptr->datavalue.b) = true; 
						 strcpy(ptr->type, "boolean"); 
						 ptr->nodetype = BOOL;
						 yylval = ptr; return BOOL;
						}

"false"					{ptr=(struct Tnode *)malloc(sizeof(struct Tnode));
						 ptr->datavalue.b = (bool*)malloc(sizeof(bool)); 
						 *(ptr->datavalue.b) = false; 
						 strcpy(ptr->type, "boolean"); 
						 ptr->nodetype = BOOL;
						 yylval = ptr; return BOOL;
						}

[0-9]+ 					{ptr=(struct Tnode *)malloc(sizeof(struct Tnode)); 
					 	 ptr->datavalue.i = (int*)malloc(sizeof(int)); 
		 			 	 *(ptr->datavalue.i) = atoi(yytext); 
		 			 	 strcpy(ptr->type, "integer"); 
		 			 	 ptr->nodetype = NUM;
		 			 	 yylval = ptr; return NUM;
						}

({id})({id}|{number})*  {ptr=(struct Tnode *)malloc(sizeof(struct Tnode)); 
						 ptr->datavalue.i = (int*)malloc(sizeof(int));
						 strcpy(ptr->name, yytext);
						 ptr->nodetype = ID; 
						 yylval = ptr; return ID;
						}




[ \t] 			{}
.				return *yytext;
"\n"			{}

%%

yywrap()
{	
	return 1;
}
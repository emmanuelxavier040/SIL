%{
	#include <stdio.h>
	#include <stdbool.h>
	#include <malloc.h>
	#include "y.tab.h"
	#include "var.h"

	#define YYSTYPE struct vnode*
	struct vnode* ptr;

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


"true"					{ptr=(struct vnode *)malloc(sizeof(struct vnode));
						 ptr->datavalue.b = (bool*)malloc(sizeof(bool)); 
						 *(ptr->datavalue.b) = true; 
						 strcpy(ptr->type, "boolean"); 
						 yylval = ptr; return BOOL;
						}

"false"					{ptr=(struct vnode *)malloc(sizeof(struct vnode));
						 ptr->datavalue.b = (bool*)malloc(sizeof(bool)); 
						 *(ptr->datavalue.b) = false; 
						 strcpy(ptr->type, "boolean"); 
						 yylval = ptr; return BOOL;
						}

{number}				{ptr=(struct vnode *)malloc(sizeof(struct vnode)); 
						 ptr->datavalue.i = (int*)malloc(sizeof(int)); 
						 *(ptr->datavalue.i) = atoi(yytext); 
						 strcpy(ptr->type, "integer"); 
						 yylval = ptr; return NUM;
						}

({id})({id}|{number})*  {ptr=(struct vnode *)malloc(sizeof(struct vnode)); 
						 ptr->datavalue.i = (int*)malloc(sizeof(int));
						 strcpy(ptr->name, yytext); 
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
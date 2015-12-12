%{
	#include <stdio.h>
	#include <malloc.h>
	#include <string.h>
	#include <stdlib.h>
	#include "y.tab.h"
	#include "exptree.h"
	#define YYSTYPE node *

	node* ptr;

	void yyerror(char*);
%}



%%

[0-9]+		{
				ptr=(node*)malloc(sizeof(node));
				ptr->val = atoi(yytext);
				ptr->flag = 0;
				ptr->left = NULL;
				ptr->right = NULL;				
				yylval = ptr;
				return DIGIT;
			}

[-+*/]		{
				ptr=(node*)malloc(sizeof(node));
				ptr->op = *yytext;
				ptr->flag = 1;
				ptr->left = NULL;
				ptr->right = NULL;				
				yylval = ptr;				
				return *yytext;	
			}

[()]		return *yytext;
"\n"		return *yytext;
"\t"		;
.			yyerror("Invlaid");

%%

yywrap()
{	
	return 1;
}
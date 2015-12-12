%{

	#include <stdio.h>
	#include <stdlib.h>

%}

%token DIGIT
%left ','
%left ' '

%%

start : pair '\n'		{printf("\nComplete");exit(1);}
	;

pair: pair ' ' pair		{}
	;
pair: num ',' num		{printf("pair(%d,%d)",$1,$3);}
	;
num: DIGIT				{$$=$1;}
	;

%%

yyerror()
{
	printf("Error");
}

main()
{
	yyparse();
	return 1;
}
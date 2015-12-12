
%{
	#include <stdlib.h>
	#include <stdio.h>
	char *file1;
%}

number [0-9]+

%%

{number} {printf("Found : %d",atoi(yytext));}

%%

int yywrap()
{
	FILE *newfile_pointer;
	char *file2 = "input_2";
	newfile_pointer = fopen(file2,"r");
	if(strcmp(file1, file2)!=0)
	{
		file1 = file2;
		yyin = newfile_pointer;
		return 0;
	}
	else
	{
		return 1;
	}
}

int main()
{
	file1 = "input_1";
	yyin = fopen(file1,"r");
	yylex();	
	return 1;
}
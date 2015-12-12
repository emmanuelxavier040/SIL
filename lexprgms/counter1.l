%{

	#include <stdio.h>
	#include <stdlib.h>
	
	int line_count;
	int word_count;
	int character_count;	
%}

%option noyywrap

character ([a-z]|[A-Z]|[0-9])
line "\n"
word " "

%%

{character}			{character_count++;}
{line}				{line_count++; word_count++;}
{word}				{word_count++; character_count++;}

%%



int main()
{
	line_count = 0;
	word_count = 0;
	character_count = 0;	

	yylex();
	
	printf("Line_count: %d\n",line_count);
	printf("Word_count: %d\n",word_count);
	printf("Character_count: %d\n",character_count);
	return 1;
}
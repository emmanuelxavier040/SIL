%{
	#include <stdio.h>
	#include <stdlib.h>

	void op_print(char op);

	int pos = 0;
%}


%token DIGIT
%left '+'
%left '*'


%%

start : expr '\n'				{exit(1);}
		;
expr  : expr '+' expr			{op_print('+');}
		| expr '*' expr 		{op_print('*');}
		| '(' expr ')'
		| DIGIT					{printf("NUM%d ",pos);}
		;
%%


void op_print(char op)
{
	if(op == '+')
		printf("PLUS ");
	else 
		printf("MUL ");
}

yyerror()
{
	printf("error");
	return;
}

yylex()
{
	int c;
	c = getchar();
	if(isdigit(c))
	{
		pos++;
		return DIGIT;
	}
	else
		return c;
}

int main()
{
	yyparse();
	return 1;
}
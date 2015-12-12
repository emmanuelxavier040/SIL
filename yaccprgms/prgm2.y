%{
	#include <stdio.h>
	#include <stdlib.h>

	void op_print(char op);

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
		| DIGIT					{printf("%d ",yylval);}
		;
%%


void op_print(char op)
{
	printf("%c",op);
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
		yylval = c - '0';
		return DIGIT;

	}
	return c;
}

int main()
{
	yyparse();
	return 1;
}
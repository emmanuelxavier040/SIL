%{

    #include <stdio.h>
    #include <stdlib.h>

%}

%token DIGIT
%left '+' '-'
%left '*' '/'
   
	 
%%

start : expr '\n'           {printf("\n%d\nComplete",$1);exit(1);}
    ;

expr:  expr '+' expr        {printf("+ "); $$ = $1 + $3;}
    | expr '-' expr         {printf("- "); $$ = $1 - $3;}
    | expr '*' expr         {printf("* "); $$ = $1 * $3;}
    | expr '/' expr         {printf("/ "); $$ = $1 / $3;}
    | '(' expr ')'          {$$ = $2;}
    | DIGIT                 {$$ = $1; printf("%d ",$1);}
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
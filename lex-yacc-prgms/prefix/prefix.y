%{

    #include <stdio.h>
    #include <stdlib.h>   
    #include <string.h>   
    char st[100];
    char s1[100];
    char s2[100];
    #define YYSTYPE char*

%}

%token DIGIT
%left '+' '-'
%left '*' '/'
   
	 
%%

start : expr '\n'           { printf("%s\n",$1); exit(1);}
    ;

expr: expr '+' expr         { strcpy(st,"+"); strcpy(s1,$1); strcpy(s2,$3); strcat(s1,s2); strcat(st,s1); strcpy($$,st); }
    | expr '-' expr         { strcpy(st,"-"); strcpy(s1,$1); strcpy(s2,$3); strcat(s1,s2); strcat(st,s1); strcpy($$,st); }
    | expr '*' expr         { strcpy(st,"*"); strcpy(s1,$1); strcpy(s2,$3); strcat(s1,s2); strcat(st,s1); strcpy($$,st); }
    | expr '/' expr         { strcpy(st,"/"); strcpy(s1,$1); strcpy(s2,$3); strcat(s1,s2); strcat(st,s1); strcpy($$,st); }
    | '(' expr ')'          { $$ = $2;}
    | DIGIT                 {}
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
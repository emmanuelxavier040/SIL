%{

    #include <stdio.h>
    #include <stdlib.h>
    #include "exptree.h" 
    #define YYSTYPE node * 

    void yyerror(char*);   

%}

%token DIGIT
%left '+' '-'
%left '*' '/'
   
	 
%%

start : expr '\n'           {   
                                $$ = $1;
                                int n = evaltree($$);
                                printf("%d\n",n);
                                exit(1);
                            }
    ;

expr: expr '+' expr         {   $2->left = $1;
                                $2->right = $3;
                                $$ = $2;
                            }
    | expr '-' expr         {   $2->left = $1;
                                $2->right = $3;
                                $$ = $2;
                            }
    | expr '*' expr         {   $2->left = $1;
                                $2->right = $3;
                                $$ = $2;
                            }
    | expr '/' expr         {   $2->left = $1;
                                $2->right = $3;
                                $$ = $2;
                            }
    | '(' expr ')'          {   
                                $$ = $2;
                            }
    | DIGIT                 {   
                                $$ = $1;
                            }
    ;

%%

void yyerror(char er[])
{
    printf("%s\n",er);
    exit(1);
}

int evaltree(node *nd)
{
    if(nd->flag==0)
    {
        return nd->val;
    }
    else
    {
        if(nd->op == '+')
            return (evaltree(nd->left)) + (evaltree(nd->right));
        else if(nd->op == '-')
            return (evaltree(nd->left)) - (evaltree(nd->right));
        else if(nd->op == '*')
            return (evaltree(nd->left)) * (evaltree(nd->right));
        else if(nd->op == '/')
            return (evaltree(nd->left)) / (evaltree(nd->right));
        else
            yyerror("Invalid");
    }
}

main()
{
    yyparse();
    return 1;
}
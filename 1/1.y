%{

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <stdbool.h>
    #include "var.h"

    #define YYSTYPE char*

    int ind = 0;
    struct vnode symboltable[100];
%}

%token ID
%token BEGN
%token END
%token DECL
%token ENDDECL
%token INTEGER
%token BOOLEAN
%token IF
%token THEN
%token ENDIF
%token ELSE
%token WHILE
%token DO
%token ENDWHILE
%token READ
%token WRITE
%token RETURN

%token EQ
%token NOTEQ
%token EQEQ

%left '+' '-'
%left '*' '/'
%left EQEQ NOTEQ
	 
%%

program : programdecl body          {
                                        int j=0;
                                        for(j=0;j<ind;j++)
                                          printf("%s %s\n",symboltable[j].name, symboltable[j].type); 

                                        printf("hi\n");exit(1);
                                    }
        ;

programdecl : DECL dlist ENDDECL    { }
            ;

dlist : dstatement dlist                
      | dstatement                   { };                 
      ;

dstatement : INTEGER ID ';'   {   
                                        strcpy(symboltable[ind].name,$2);
                                        strcpy(symboltable[ind].type,"integer");
                                        symboltable[ind].datavalue.i = 0; 
                                        ind++;                                       
                                }
           | BOOLEAN ID ';'   { 
                                        strcpy(symboltable[ind].name,$2);
                                        strcpy(symboltable[ind].type,"integer");
                                        symboltable[ind].datavalue.i = false;                                        
                                        ind++;
                                }
           ;

body : BEGN statementlist END  { }
     ;

statementlist : statement statementlist
              | statement     {}
              ;  

statement : assignment          { }
          | condition
          | loop
          ;

assignment : ID '=' expr ';'     { }
           ;



expr : expr '+' expr             {}
     | expr '-' expr             {}
     | expr '*' expr             {}
     | expr '/' expr             {}
     | expr EQEQ expr            {}
     | expr NOTEQ expr           {}
     | '(' expr ')'              {}
     | ID                        {}
     ;

condition : IF expr THEN statementlist ENDIF ';'
          | IF expr THEN statementlist ELSE statementlist ENDIF ';'
          ;

loop : WHILE expr DO statementlist ENDWHILE ';'
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
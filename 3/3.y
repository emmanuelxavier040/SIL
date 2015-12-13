%{

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <stdbool.h>
    #include "var.h"

    #define YYSTYPE struct vnode*

    int ind = 0;
    struct vnode* symboltable[100];
    struct vnode* ptr;

    struct vnode* operate_int(struct vnode*, struct vnode*, char*);
    struct vnode* operate_int_bool(struct vnode*, struct vnode*, char*);

%}

%token ID
%token NUM
%token BOOL
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

%token AND
%token OR
%token NOT
%token LSEQ
%token GREQ
%token LSTHAN
%token GRTHAN

%left '+' '-'
%left '*' '/'
%left EQEQ NOTEQ
%left GREQ LSEQ
%left GRTHAN LSTHAN
%left AND
%left OR
%left NOT
	 
%%

program : programdecl body          {
                                      int j=0;
                                        for(j=0;j<ind;j++){
                                          printf("%s %s %d\n",symboltable[j]->name, symboltable[j]->type,symboltable[j]->size);
                                          printf("Values\n");

                                          int i=0;
                                          for(i=0;i<symboltable[j]->size;i++)
                                            if(strcmp(symboltable[j]->type,"integer")==0)
                                              printf("%d ",(symboltable[j]->datavalue.i)[i]);
                                            else
                                              printf("%d ",(symboltable[j]->datavalue.b)[i]);

                                          printf("\n");

                                        }
    
                                        printf("\nComplete\n");
                                        exit(1);
                                    }
        ;

programdecl : DECL dlist ENDDECL     { }
            ;

dlist : dstatement dlist                
      | dstatement                   { }                
      ;

dstatement : INTEGER ID ';'   {   
                                        symboltable[ind] = $2;                                        
                                        strcpy(symboltable[ind]->type,"integer");                                        
                                        symboltable[ind]->size = 1;
                                        *(symboltable[ind]->datavalue.i) = 0; 
                                        ind++;                                       
                              }
           | BOOLEAN ID ';'   { 
                                        symboltable[ind] = $2;
                                        strcpy(symboltable[ind]->type,"boolean");
                                        symboltable[ind]->size = 1;
                                        *(symboltable[ind]->datavalue.b) = false;                                        
                                        ind++;
                              }
           | INTEGER ID '[' expr ']' ';'     {                                                                    

                                              symboltable[ind] = $2;                                        
                                              strcpy(symboltable[ind]->type,"integer");                                        
                                              symboltable[ind]->size = *($4->datavalue.i);
                                              

                                              free(symboltable[ind]->datavalue.i);
                                              symboltable[ind]->datavalue.i = (int*)malloc(symboltable[ind]->size * sizeof(int));
                                              memset(symboltable[ind]->datavalue.i,0,symboltable[ind]->size);                                            
                                              ind++;

                                             }
           | BOOLEAN ID '[' expr ']' ';'     {

                                              symboltable[ind] = $2;                                        
                                              strcpy(symboltable[ind]->type,"boolean");                                        
                                              symboltable[ind]->size = *($4->datavalue.i);
                                              
                                              free(symboltable[ind]->datavalue.b);
                                              symboltable[ind]->datavalue.b = (bool*)malloc(symboltable[ind]->size * sizeof(bool));
                                              memset(symboltable[ind]->datavalue.b,false,symboltable[ind]->size);                                            
                                              ind++;

                                             }
           ;

body : BEGN statementlist END       { }
     ;

statementlist : statementlist statement
              | statement           { }
              ;  

statement : assignment              { }
          | condition
          | loop
          ;

assignment : ID '=' expr ';'        {                                      
                                      int i = checkpresent($1);
                                      if(strcmp(symboltable[i]->type,$3->type)!=0){
                                        printf("TYPE ERROR %s %s\n",symboltable[i]->type,$3->type);
                                        exit(1);
                                      }                             

                                      if(symboltable[i]->size > 1){
                                        printf("ILLEGAL ACCESS\n");
                                        exit(1);
                                      }


                                      if(strcmp(symboltable[i]->type,"integer")==0){                                        
                                        *(symboltable[i]->datavalue.i) = *($3->datavalue.i);
                                      }
                                      else
                                        *(symboltable[i]->datavalue.b) = *($3->datavalue.b);

                                                                        
                                      if(strcmp($1->type,"integer")==0){                                        
                                        if($1->datavalue.i != NULL) free($1->datavalue.i);
                                      }
                                      else{
                                        if($1->datavalue.b != NULL) free($1->datavalue.b);
                                      }
                                      if(strcmp($3->type,"integer")==0){                                        
                                        if($3->datavalue.i != NULL) free($3->datavalue.i);
                                      }
                                      else{
                                        if($3->datavalue.b != NULL) free($3->datavalue.b);
                                      }                                     
                                      free($1);
                                      free($3);

                                    }

           | ID '[' expr ']' '=' expr ';'        {
                                                  int i = checkpresent($1);
                                                  if(strcmp(symboltable[i]->type,$6->type)!=0){
                                                    printf("TYPE ERROR %s %s\n",symboltable[i]->type,$6->type);
                                                    exit(1);
                                                  }

                                                  if(symboltable[i]->size == 1){
                                                    printf("ILLEGAL ACCESS\n");
                                                    exit(1);
                                                  }

                                                  if(strcmp(symboltable[i]->type,"integer")==0){                                        
                                                    *(symboltable[i]->datavalue.i + *($3->datavalue.i)) = *($6->datavalue.i);
                                                  }
                                                  else{
                                                    *(symboltable[i]->datavalue.b + *($3->datavalue.i)) = *($6->datavalue.b);
                                                  }

                                                  if(strcmp($1->type,"integer")==0){                                        
                                                    if($1->datavalue.i != NULL) free($1->datavalue.i);
                                                  }
                                                  else{
                                                    if($1->datavalue.b != NULL) free($1->datavalue.b);
                                                  }
                                                  if(strcmp($3->type,"integer")==0){                                        
                                                    if($3->datavalue.i != NULL) free($3->datavalue.i);
                                                  }
                                                  else{
                                                    if($3->datavalue.b != NULL) free($3->datavalue.b);
                                                  }                                               
                                                  if(strcmp($6->type,"integer")==0){                                        
                                                    if($6->datavalue.i != NULL) free($6->datavalue.i);
                                                  }
                                                  else{
                                                    if($6->datavalue.b != NULL) free($6->datavalue.b);
                                                  }

                                                  free($1);
                                                  free($3);
                                                  free($6);
                                                }
           ;



expr : expr '+' expr             {  $$ = operate_int($1,$3,"+"); }
     | expr '-' expr             {  $$ = operate_int($1,$3,"-"); }
     | expr '*' expr             {  $$ = operate_int($1,$3,"*"); }
     | expr '/' expr             {  $$ = operate_int($1,$3,"/"); }
     | expr LSEQ expr            {  $$ = operate_int($1,$3,"<=");}
     | expr GREQ expr            {  $$ = operate_int($1,$3,">=");}
     | expr LSTHAN expr          {  $$ = operate_int($1,$3,"<");}
     | expr GRTHAN expr          {  $$ = operate_int($1,$3,">");}

     | expr EQEQ expr            {  $$ = operate_int_bool($1,$3,"==");}
     | expr NOTEQ expr           {  $$ = operate_int_bool($1,$3,"!=");}
     | expr AND expr             {  $$ = operate_int_bool($1,$3,"&&");}
     | expr OR expr              {  $$ = operate_int_bool($1,$3,"||");}
     | NOT expr                  {  $$ = operate_int_bool($2,$2,"!");}
 
     | '(' expr ')'              { $$ = $2;}
     | ID                        {                                   
                                    int i = checkpresent($1);                                  
                                    strcpy($1->type,symboltable[i]->type);
                                    if(strcmp($1->type,"integer")==0)
                                      *($1->datavalue.i) = *(symboltable[i]->datavalue.i);
                                    else
                                      *($1->datavalue.b) = *(symboltable[i]->datavalue.b);

                                    $$=$1;
                                  }

     | ID '[' expr ']'            {
                                
                                    int i = checkpresent($1);                                  
                                    strcpy($1->type,symboltable[i]->type);

                                     if(strcmp(symboltable[i]->type,"integer")==0){                                        
                                       *($1->datavalue.i) = *(symboltable[i]->datavalue.i + *($3->datavalue.i));
                                     }
                                     else
                                       *($1->datavalue.b) = *(symboltable[i]->datavalue.b + *($3->datavalue.i));

                                    $$=$1;                                  
                                    
                                    if(strcmp($3->type,"integer")==0){                                        
                                      if($3->datavalue.i != NULL) free($3->datavalue.i);
                                    }
                                    else{
                                      if($3->datavalue.b != NULL) free($3->datavalue.b);
                                    }
                                    free($3);
                                  }

     | NUM                        {
                                    $$ = $1;
                                  }
     | BOOL                       {
                                    $$ = $1;
                                  }
     ;

condition : IF expr THEN statementlist ENDIF ';'                       {if(*($2->datavalue.b) == false){printf("condition false\n");}}
          | IF expr THEN statementlist ELSE statementlist ENDIF ';'
          ;

loop : WHILE expr DO statementlist ENDWHILE ';'
     ;

%%





//---------------------------OPERATIONS  INTEGERS TO INTEGER/BOOLEAN-------------------------------

struct vnode* operate_int(struct vnode* one, struct vnode* three, char op[])
{
    if((strcmp(one->type, three->type) != 0) || ((strcmp(one->type, "integer") != 0) || (strcmp(three->type, "integer") != 0))){
      printf("TYPE ERROR in '+'\n");
      exit(1);
    }

    struct vnode* node;
    node = (struct vnode *)malloc(sizeof(struct vnode));
    node->datavalue.i = (int*)malloc(sizeof(int));
    node->datavalue.b = (bool*)malloc(sizeof(bool));

    strcpy(node->type,one->type);  

    if(strcmp(op,"+")==0)                                 
      *(node->datavalue.i) = *(one->datavalue.i) + *(three->datavalue.i);
    else if(strcmp(op,"-")==0)
      *(node->datavalue.i) = *(one->datavalue.i) - *(three->datavalue.i);   
    else if(strcmp(op,"*")==0)
      *(node->datavalue.i) = *(one->datavalue.i) * *(three->datavalue.i);   
    else if(strcmp(op,"/")==0){
        if(*(three->datavalue.i) == 0){
        printf("DIVIDE BY ZERO\n");
        exit(1);
        }
      *(node->datavalue.i) = *(one->datavalue.i) / *(three->datavalue.i);
    }
    else{
          strcpy(node->type,"boolean");

                if(strcmp(op,"<=")==0){
                    if(*(one->datavalue.i) <= *(three->datavalue.i))
                      *(node->datavalue.b) = true;
                    else
                      *(node->datavalue.b) = false;
                }
                else if(strcmp(op,">=")==0){
                    if(*(one->datavalue.i) >= *(three->datavalue.i))
                      *(node->datavalue.b) = true;
                    else
                      *(node->datavalue.b) = false;
                }
                else if(strcmp(op,"<")==0){
                    if(*(one->datavalue.i) < *(three->datavalue.i))
                      *(node->datavalue.b) = true;
                    else
                      *(node->datavalue.b) = false;
                }
                else{
                    if(*(one->datavalue.i) > *(three->datavalue.i))
                      *(node->datavalue.b) = true;
                    else
                      *(node->datavalue.b) = false;
                }

    }

    //printf("%d\n",*(node->datavalue.i));
    

    if(strcmp(one->type,"integer")==0){                                        
      if(one->datavalue.i != NULL) free(one->datavalue.i);
    }
    else{
      if(one->datavalue.b != NULL) free(one->datavalue.b);
    }
    if(strcmp(three->type,"integer")==0){                                        
      if(three->datavalue.i != NULL) free(three->datavalue.i);
    }
    else{
      if(three->datavalue.b != NULL) free(three->datavalue.b);
    }  
    free(one);
    free(three);

    return node;
}



//-----------------------OPERATIONS BOOLEAN/INTEGER TO BOOLEAN------------------

struct vnode* operate_int_bool(struct vnode* one, struct vnode* three, char op[])
{
        if(strcmp(one->type, three->type) != 0){
            printf("TYPE ERROR in '+'\n");
            exit(1);
         }
            
          struct vnode* node;
          node = (struct vnode *)malloc(sizeof(struct vnode));
          strcpy(node->type,"boolean");

          if((strcmp(one->type,"integer") == 0)&&(strcmp(three->type,"integer") == 0)){

                      if(strcmp(op,"==") == 0){                
                          if(*(one->datavalue.i) == *(three->datavalue.i))
                            *(node->datavalue.b) = true;
                          else
                            *(node->datavalue.b) = false;
                      }
                      else if(strcmp(op,"!=") == 0){                
                          if(*(one->datavalue.i) != *(three->datavalue.i))
                            *(node->datavalue.b) = true;
                          else
                            *(node->datavalue.b) = false;
                      }                         
                      else if(strcmp(op,"!") == 0){                
                          if(*(one->datavalue.i) == 0)
                            *(node->datavalue.b) = true;
                          else
                            *(node->datavalue.b) = false;
                      }
                      else{
                          printf("TYPE MISMATCH\n");
                          exit(1);
                      }                    
          }
          else if((strcmp(one->type,"boolean") == 0)&&(strcmp(three->type,"boolean") == 0)){

                      if(strcmp(op,"==") == 0){                
                          if(*(one->datavalue.b) == *(three->datavalue.b))
                            *(node->datavalue.b) = true;
                          else
                            *(node->datavalue.b) = false;
                      }
                      else if(strcmp(op,"!=") == 0){                
                          if(*(one->datavalue.b) != *(three->datavalue.b))
                            *(node->datavalue.b) = true;
                          else
                            *(node->datavalue.b) = false;
                      }
                      else if(strcmp(op,"&&") == 0){                
                          if(*(one->datavalue.b) && *(three->datavalue.b))
                            *(node->datavalue.b) = true;
                          else
                            *(node->datavalue.b) = false;
                      }
                      else if(strcmp(op,"||") == 0){                
                          if(*(one->datavalue.b) || *(three->datavalue.b))
                            *(node->datavalue.b) = true;
                          else
                            *(node->datavalue.b) = false;
                      }
                      else{                
                          if(*(one->datavalue.b) == 0)
                            *(node->datavalue.b) = true;
                          else
                            *(node->datavalue.b) = false;
                      }                      
          }
          else{
            printf("TYPE MISMATCH\n");
            exit(1);
          }


          return node;
}




//-----------------------
int checkpresent(struct vnode* A)
{
    int i;                                    
    for(i=0;i<ind;i++)
      if(strcmp(symboltable[i]->name,A->name)==0)
        break;
    
    if(i>=ind){
      printf("%s UNDECLARED\n",A->name);
      exit(1);
    }

    return i;
}
//-----------------------------



yyerror()
{
    printf("Error");
    exit(1);
}


main()
{    
    yyparse();
    return 1;
}
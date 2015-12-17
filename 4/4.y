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
    void free_node(struct vnode*);

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

                                          int i=0,length;
                                          if(symboltable[j]->size == 0)
                                            length=1;
                                          else
                                            length = symboltable[j]->size;
                                          for(i=0;i<length;i++)
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

dlist : dstatement dlist             { }  
      | dstatement                   { }                
      ;

dstatement : INTEGER ID ';'   {         
                                        int i = checkpresent($2);
                                        if(i<ind){
                                          printf("%s ALREADY DECLARED\n",$2->name);
                                          exit(1);
                                        }

                                        symboltable[ind] = $2;                                        
                                        strcpy(symboltable[ind]->type,"integer");                                        
                                        symboltable[ind]->size = 0;
                                        *(symboltable[ind]->datavalue.i) = 0; 
                                        ind++;


                              }
           | BOOLEAN ID ';'   {         int i = checkpresent($2);
                                        if(i<ind){
                                          printf("%s ALREADY DECLARED\n",$2->name);
                                          exit(1);
                                        }

                                        symboltable[ind] = $2;
                                        strcpy(symboltable[ind]->type,"boolean");
                                        symboltable[ind]->size = 0;
                                        *(symboltable[ind]->datavalue.b) = false;                                        
                                        ind++;
                              }
           | INTEGER ID '[' expr ']' ';'     {                                                                    
                                              int i = checkpresent($2);
                                              if(i<ind){
                                                printf("%s ALREADY DECLARED\n",$2->name);
                                                exit(1);
                                              }

                                              if((strcmp($4->type,"integer") != 0)||(*($4->datavalue.i) <= 0)){
                                                printf("SIZE MUST BE A POSITIVE INTEGER\n");
                                                exit(1); 
                                              }

                                              symboltable[ind] = $2;                                        
                                              strcpy(symboltable[ind]->type,"integer");                                        
                                              symboltable[ind]->size = *($4->datavalue.i);
                                              
                                              free(symboltable[ind]->datavalue.i);
                                              symboltable[ind]->datavalue.i = NULL;

                                              symboltable[ind]->datavalue.i = (int*)malloc(symboltable[ind]->size * sizeof(int));
                                              memset(symboltable[ind]->datavalue.i,0,symboltable[ind]->size);                                            
                                              ind++;

                                             }
           | BOOLEAN ID '[' expr ']' ';'     {
                                              int i = checkpresent($2);
                                              if(i<ind){
                                                printf("%s ALREADY DECLARED\n",$2->name);
                                                exit(1);
                                              }

                                              if((strcmp($4->type,"integer") != 0)||(*($4->datavalue.i) <= 0)){
                                                printf("SIZE MUST BE A POSITIVE INTEGER\n");
                                                exit(1); 
                                              }

                                              symboltable[ind] = $2;                                        
                                              strcpy(symboltable[ind]->type,"boolean");                                        
                                              symboltable[ind]->size = *($4->datavalue.i);
                                              
                                              free(symboltable[ind]->datavalue.b);
                                              symboltable[ind]->datavalue.b = NULL;

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
                                      if(i>=ind){
                                        printf("%s UNDECLARED\n",$1->name);
                                        exit(1);
                                      }


                                      if(strcmp(symboltable[i]->type,$3->type)!=0){
                                        printf("TYPE ERROR %s %s\n",symboltable[i]->type,$3->type);
                                        exit(1);
                                      }                             

                                      if(symboltable[i]->size != 0){
                                        printf("%s IS AN ARRAY\n",symboltable[i]->name);
                                        exit(1);
                                      }


                                      if(strcmp(symboltable[i]->type,"integer")==0){                                        
                                        *(symboltable[i]->datavalue.i) = *($3->datavalue.i);
                                      }
                                      else
                                        *(symboltable[i]->datavalue.b) = *($3->datavalue.b);

                                                                                                                                                  
                                      free_node($1);
                                      free_node($3);

                                    }

           | ID '[' expr ']' '=' expr ';'        {
                                                  int i = checkpresent($1);
                                                  if(i>=ind){
                                                    printf("%s UNDECLARED\n",$1->name);
                                                    exit(1);
                                                  }
                                                  
                                                  if((symboltable[i]->size == 0)||(*($3->datavalue.i) < 0)||(symboltable[i]->size <= *($3->datavalue.i))){
                                                    printf("ILLEGAL ACCESS\n");
                                                    exit(1);
                                                  }

                                                  if((strcmp($3->type,"integer") != 0)||(*($3->datavalue.i) < 0)){
                                                    printf("SIZE MUST BE A POSITIVE INTEGER\n");
                                                    exit(1); 
                                                  }

                                                  if(strcmp(symboltable[i]->type,$6->type)!=0){
                                                    printf("TYPE ERROR %s %s\n",symboltable[i]->type,$6->type);
                                                    exit(1);
                                                  }                                                  

                                                  if(strcmp(symboltable[i]->type,"integer")==0){                                        
                                                    *(symboltable[i]->datavalue.i + *($3->datavalue.i)) = *($6->datavalue.i);
                                                  }
                                                  else{
                                                    *(symboltable[i]->datavalue.b + *($3->datavalue.i)) = *($6->datavalue.b);
                                                  }

                                                  
                                                  free_node($1);
                                                  free_node($3);
                                                  free_node($6);
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
                                    if(i>=ind){
                                      printf("%s UNDECLARED\n",$1->name);
                                      exit(1);
                                    }
                                    
                                    if(symboltable[i]->size != 0){
                                      printf("%s IS AN ARRAY\n",$1->name);
                                      exit(1);
                                    }
                                    
                                    strcpy($1->type,symboltable[i]->type); 
                                                                       
                                    if(strcmp($1->type,"integer")==0)
                                      *($1->datavalue.i) = *(symboltable[i]->datavalue.i);
                                    else
                                      *($1->datavalue.b) = *(symboltable[i]->datavalue.b);

                                    $$=$1;
                                  }

     | ID '[' expr ']'            {
                                
                                    int i = checkpresent($1);
                                    if(i>=ind){
                                      printf("%s UNDECLARED\n",$1->name);
                                      exit(1);
                                    }             

                                    if((symboltable[i]->size == 0)||(*($3->datavalue.i) < 0)||(*($3->datavalue.i) >= symboltable[i]->size)){
                                      printf("ILLEGAL ACCESS\n");
                                      exit(1);
                                    }
                                    
                                    if(strcmp($3->type,"integer") != 0){
                                      printf("TYPE ERROR\n");
                                      exit(1); 
                                    }

                                    strcpy($1->type,symboltable[i]->type);

                                    if(strcmp(symboltable[i]->type,"integer")==0)                                       
                                      *($1->datavalue.i) = *(symboltable[i]->datavalue.i + *($3->datavalue.i));                                     
                                    else
                                      *($1->datavalue.b) = *(symboltable[i]->datavalue.b + *($3->datavalue.i));

                                    $$=$1;                                  
                                    free_node($3);
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

    free_node(one);
    free_node(three);

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



//----------FREEING A NODE------------------

void free_node(struct vnode* node)
{
  if(node != NULL)
  {
      if(strcmp(node->type,"integer")==0)
      {
            if(node->datavalue.i != NULL) 
              free(node->datavalue.i);
            node->datavalue.i = NULL;
      }
      else
      {
            if(node->datavalue.b != NULL) 
              free(node->datavalue.b);
            node->datavalue.b = NULL;
      }

   free(node);
   node = NULL; 
  }
    
}


//-----------------------
int checkpresent(struct vnode* A)
{
    int i;                                    
    for(i=0;i<ind;i++)
      if(strcmp(symboltable[i]->name,A->name)==0)
        break;

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
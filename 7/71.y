%{

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <stdbool.h>
    #include "var.h"

    #define YYSTYPE struct Tnode*

    int ind = 0;
    struct vnode* symboltable[100];
    struct vnode* ptr;
    struct Tnode* treenode;

    struct Tnode* operate_int(struct Tnode*, struct Tnode*, char*);
    struct Tnode* operate_int_bool(struct Tnode*, struct Tnode*, char*);    
    void free_node(struct Tnode*);
    int astree(struct Tnode* nd);
    void show_symboltable();
    void install_symbol(struct Tnode*, char [], int);
    void checktype(char [], char []);





    FILE *fp;

    int regcount = 0;
    int getreg();    
    void freereg();
    
    int lablecount = -1;
    int getlable();

    int memno = 0;
    int getmem(int);

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


%token STATEMENTLIST
%token EQUALTO
%token PLUS
%token MINUS
%token MUL
%token DIV
%token MOD


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
%left '%'
%left '*' '/'
%left EQEQ NOTEQ
%left GREQ LSEQ
%left GRTHAN LSTHAN
%left AND
%left OR
%left NOT
	 
%%

program : programdecl body          {
                                      $$ = $2;          
                                      fp = fopen("sample.sim","w");                             
                                      int l = astree($$);
                                      fclose(fp);
                                      show_symboltable();
                                      printf("\nComplete\n");
                                      exit(1);
                                    }
        ;

programdecl : DECL dlist ENDDECL     {  }
            ;

dlist : dstatement dlist             {  }  
      | dstatement                   {  }                
      ;

dstatement : INTEGER ID ';'                         { 
                                                      install_symbol($2,"integer",0);     
                                                      free_node($2);  
                                                    }

           | BOOLEAN ID ';'                         {  
                                                      install_symbol($2,"boolean",0);     
                                                      free_node($2);  
                                                    }

           | INTEGER ID '[' NUM ']' ';'             { 
                                                      install_symbol($2,"integer",*($4->datavalue.i));                                                 
                                                      free_node($2);
                                                      free_node($4);
                                                    }
           | BOOLEAN ID '[' NUM']' ';'              {                                                     
                                                      install_symbol($2,"boolean",*($4->datavalue.i));
                                                      free_node($2);
                                                      free_node($4);                                              
                                                    }
           ;

body : BEGN statementlist END       { $$ = $2;}
     ;

statementlist : statement statementlist { treenode = (struct Tnode*)malloc(sizeof(struct Tnode));
                                          $$ = treenode;
                                          $$->nodetype = STATEMENTLIST;
                                          $$->Ptr1 = $1;
                                          $$->Ptr2 = $2;
                                        }
              | statement               { treenode = (struct Tnode*)malloc(sizeof(struct Tnode));
                                          $$ = treenode;
                                          $$->nodetype = STATEMENTLIST;
                                          $$->Ptr1 = $1;
                                        }
              ;  

statement : assignment                          { $$ = $1;}
          | condition                           { $$ = $1;}
          | loop                                { $$ = $1;}
          | read                                { $$ = $1;} 
          | write                               { $$ = $1;}         
          ;

read     : READ '(' ID ')' ';'                  {   int i = checkpresent($3);
                                                    if(i>=ind){
                                                      printf("%s UNDECLARED\n",$3->name);
                                                      exit(1);
                                                    }
                                                    
                                                    if(symboltable[i]->size != 0){
                                                      printf("%s IS AN ARRAY\n",$3->name);
                                                      exit(1);
                                                    }
                                                    
                                                    strcpy($3->type,symboltable[i]->type);
                                                    $3->symtabindex = i; 

                                                    treenode = (struct Tnode*)malloc(sizeof(struct Tnode));
                                                    $$ = treenode;
                                                    $$->nodetype = READ;
                                                    $$->Ptr1 = $3; 
                                                }
         | READ '(' ID '[' expr ']' ')' ';'     { 
                                                  int i = checkpresent($3);
                                                  if(i>=ind){
                                                    printf("%s UNDECLARED\n",$3->name);
                                                    exit(1);
                                                  }             

                                                  checktype($5->type,"integer");

                                                  if((symboltable[i]->size == 0)||(*($5->datavalue.i) < 0)||(*($5->datavalue.i) >= symboltable[i]->size)){
                                                    printf("ILLEGAL ACCESS\n");
                                                    exit(1);
                                                  }
                                                  
                                                  
                                                  strcpy($3->type,symboltable[i]->type);
                                                                                                    
                                                  $3->symtabindex = i;
                                                  strcpy($3->type,symboltable[i]->type);
                                                  $3->Ptr1 = $5;
                                                
                                                  treenode = (struct Tnode*)malloc(sizeof(struct Tnode));
                                                  $$ = treenode;
                                                  $$->nodetype = READ;
                                                  $$->Ptr1 = $3;
                                                }
         ;

write    : WRITE '(' expr ')' ';'               { 
                                                  treenode = (struct Tnode*)malloc(sizeof(struct Tnode));
                                                  $$ = treenode;
                                                  $$->nodetype = WRITE;
                                                  $$->Ptr1 = $3; 
                                                }
         ;

assignment : ID '=' expr ';'        {                                      
                                      int i = checkpresent($1);
                                      if(i>=ind){
                                        printf("%s UNDECLARED\n",$1->name);
                                        exit(1);
                                      }

                                      checktype(symboltable[i]->type,$3->type);


                                      if(symboltable[i]->size != 0){
                                        printf("%s IS AN ARRAY\n",symboltable[i]->name);
                                        exit(1);  
                                      }

                                      strcpy($1->type,symboltable[i]->type);

                                      treenode = (struct Tnode*)malloc(sizeof(struct Tnode));
                                      $2 = treenode;
                                      $2->nodetype = EQUALTO;
                                      $2->Ptr1 = $1;
                                        $1->symtabindex = i;                                    
                                      $2->Ptr2 = $3;                                      
                                      $$ = $2;

                                    }

           | ID '[' expr ']' '=' expr ';'        {
                                                  int i = checkpresent($1);
                                                  if(i>=ind){
                                                    printf("%s UNDECLARED\n",$1->name);
                                                    exit(1);
                                                  }
                                                                                                    
                                                  checktype($3->type,"integer");

                                                  if((symboltable[i]->size == 0)||(*($3->datavalue.i) < 0)||(symboltable[i]->size <= *($3->datavalue.i))){
                                                    printf("ILLEGAL ACCESS\n");
                                                    exit(1);
                                                  }

                                                  if(strcmp(symboltable[i]->type,$6->type)!=0){
                                                    printf("TYPE ERROR %s %s\n",symboltable[i]->type,$6->type);
                                                    exit(1);
                                                  }


                                                  treenode = (struct Tnode*)malloc(sizeof(struct Tnode));
                                                  $5 = treenode;
                                                  $5->nodetype = EQUALTO;
                                                  $5->Ptr1 = $1;
                                                    $1->Ptr1 = $3;
                                                    $1->symtabindex = i;
                                                    strcpy($1->type,symboltable[i]->type);
                                                  $5->Ptr2 = $6;                                      
                                                  $$ = $5;

                                                }
           ;



expr : expr '+' expr             {  $$ = operate_int($1,$3,"+");    $$->Ptr1 = $1;    $$->Ptr2 = $3;    $$->nodetype = PLUS;}
     | expr '-' expr             {  $$ = operate_int($1,$3,"-");    $$->Ptr1 = $1;    $$->Ptr2 = $3;    $$->nodetype = MINUS;}
     | expr '*' expr             {  $$ = operate_int($1,$3,"*");    $$->Ptr1 = $1;    $$->Ptr2 = $3;    $$->nodetype = MUL;}
     | expr '/' expr             {  $$ = operate_int($1,$3,"/");    $$->Ptr1 = $1;    $$->Ptr2 = $3;    $$->nodetype = DIV;}
     | expr '%' expr             {  $$ = operate_int($1,$3,"%");    $$->Ptr1 = $1;    $$->Ptr2 = $3;    $$->nodetype = MOD;}
     | expr LSEQ expr            {  $$ = operate_int($1,$3,"<=");   $$->Ptr1 = $1;    $$->Ptr2 = $3;    $$->nodetype = LSEQ;}
     | expr GREQ expr            {  $$ = operate_int($1,$3,">=");   $$->Ptr1 = $1;    $$->Ptr2 = $3;    $$->nodetype = GREQ;}
     | expr LSTHAN expr          {  $$ = operate_int($1,$3,"<");    $$->Ptr1 = $1;    $$->Ptr2 = $3;    $$->nodetype = LSTHAN;}
     | expr GRTHAN expr          {  $$ = operate_int($1,$3,">");    $$->Ptr1 = $1;    $$->Ptr2 = $3;    $$->nodetype = GRTHAN;}

     | expr EQEQ expr            {  $$ = operate_int_bool($1,$3,"==");   $$->Ptr1 = $1;    $$->Ptr2 = $3;   $$->nodetype = EQEQ;}
     | expr NOTEQ expr           {  $$ = operate_int_bool($1,$3,"!=");   $$->Ptr1 = $1;    $$->Ptr2 = $3;   $$->nodetype = NOTEQ;}

     | expr AND expr             {  $$ = operate_int_bool($1,$3,"&&");   $$->Ptr1 = $1;    $$->Ptr2 = $3;   $$->nodetype = AND;}
     | expr OR expr              {  $$ = operate_int_bool($1,$3,"||");   $$->Ptr1 = $1;    $$->Ptr2 = $3;   $$->nodetype = OR;}
     | NOT expr                  {  $$ = operate_int_bool($2,$2,"!");    $$->Ptr1 = $2;    $$->nodetype = NOT;}
 
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
                                    $1->symtabindex = i;                                    
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
                                    checktype($3->type,"integer");

                                    strcpy($1->type,symboltable[i]->type);

                                    $1->Ptr1 = $3;
                                    $1->symtabindex = i;
                                    strcpy($1->type,symboltable[i]->type);

                                    $$=$1;
                                      

                                                                 

                                  }

     | NUM                        { 
                                    $$ = $1;                                                                                                        
                                  }
     | BOOL                       {
                                    $$ = $1;                                    
                                  }
     ;

condition : IF expr THEN statementlist ENDIF ';'                      {
                                                                          checktype($2->type,"boolean");
                                                                          treenode = (struct Tnode*)malloc(sizeof(struct Tnode));
                                                                          $1 = treenode;
                                                                          $1->nodetype = IF;
                                                                          $1->Ptr1 = $2;                                    
                                                                          $1->Ptr2 = $4;                                      
                                                                          $$ = $1; 
                                                                      }
          | IF expr THEN statementlist ELSE statementlist ENDIF ';'   {   
                                                                          checktype($2->type,"boolean");
                                                                          treenode = (struct Tnode*)malloc(sizeof(struct Tnode));
                                                                          $1 = treenode;
                                                                          $1->nodetype = IF;
                                                                          $1->Ptr1 = $2;                                    
                                                                          $1->Ptr2 = $4;
                                                                          $1->Ptr3 = $6;
                                                                          $$ = $1;
                                                                      }
          ;

loop : WHILE expr DO statementlist ENDWHILE ';' { 
                                                  checktype($2->type,"boolean");
                                                  treenode = (struct Tnode*)malloc(sizeof(struct Tnode));
                                                  $1 = treenode;
                                                  $1->nodetype = WHILE;
                                                  $1->Ptr1 = $2;                                    
                                                  $1->Ptr2 = $4;                                      
                                                  $$ = $1;
                                                }
     ;

%%

int getmem(int len)
{  
  int temp = memno;
  memno = memno + len;
  return temp;
}

int getlable()
{
  lablecount++;
  return lablecount;
}

int getreg()
{
  regcount++;
  return (regcount-1);
}

void freereg()
{
  regcount--;
}



//----------INSTALL SYMBOLTABLE-----------------------

void install_symbol(struct Tnode* identifier, char type[], int size)
{
    int i = checkpresent(identifier);
    if(i < ind){    
          printf("%s ALREADY DECLARED\n",identifier->name);   
          exit(1);
    }


    ptr=(struct vnode *)malloc(sizeof(struct vnode));

    symboltable[ind] = ptr; 

    symboltable[ind]->size = size;  

    strcpy(symboltable[ind]->name,identifier->name);

    if(strcmp(type,"integer")==0){

        strcpy(symboltable[ind]->type,"integer");

        if(size == 0){

            ptr->datavalue.i = (int*)malloc(sizeof(int));   *(ptr->datavalue.i) = 0;

            ptr->store = getmem(1);
        }
        else{

            ptr->datavalue.i = (int*)malloc(size * sizeof(int));    memset(ptr->datavalue.i,0,size); 

            ptr->store = getmem(size); 
        }
    }
    else{

        strcpy(symboltable[ind]->type,"boolean");

        if(size == 0){

            ptr->datavalue.b = (bool*)malloc(sizeof(bool));  *(ptr->datavalue.i) = false;

            ptr->store = getmem(1);
        }
        else{

            ptr->datavalue.b = (bool*)malloc(size * sizeof(bool));    memset(ptr->datavalue.i,0,size);

            ptr->store = getmem(size);
        }
    }
        
    
    ind++;

}






//---------------------------OPERATIONS  INTEGERS TO INTEGER/BOOLEAN-------------------------------

struct Tnode* operate_int(struct Tnode* one, struct Tnode* three, char op[])
{
    if((strcmp(one->type, three->type) != 0) || ((strcmp(one->type, "integer") != 0) || (strcmp(three->type, "integer") != 0))){
      printf("TYPE ERROR in '+'\n");
      exit(1);
    }

    struct Tnode* node;
    node = (struct Tnode *)malloc(sizeof(struct Tnode));
    node->datavalue.i = (int*)malloc(sizeof(int));
    node->datavalue.b = (bool*)malloc(sizeof(bool));

    if((strcmp(op,"+")==0) || (strcmp(op,"-")==0) || (strcmp(op,"*")==0) || (strcmp(op,"/")==0) || (strcmp(op,"%")==0))
        
        strcpy(node->type,"integer");  
    else
        strcpy(node->type,"boolean");

    return node;
}



//-----------------------OPERATIONS BOOLEAN/INTEGER TO BOOLEAN------------------

struct Tnode* operate_int_bool(struct Tnode* one, struct Tnode* three, char op[])
{
        if(strcmp(one->type, three->type) != 0){
            printf("TYPE ERROR in '+'\n");
            exit(1);
         }
            
          struct Tnode* node;
          node = (struct Tnode *)malloc(sizeof(struct Tnode));
          node->datavalue.b = (bool*)malloc(sizeof(bool));
          strcpy(node->type,"boolean");

          return node;
}



//----------FREEING A NODE------------------

void free_node(struct Tnode* node)
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

int checkpresent(struct Tnode* A)
{
    int i;                                    
    for(i=0;i<ind;i++)
      if(strcmp(symboltable[i]->name,A->name)==0)
        break;

    return i;
}

void checktype(char type1[], char type2[])
{
  if(strcmp(type1,type2) != 0){
    printf("TYPE MISMATCH\n");
    exit(1); 
  }
}

//-----------------------------


//============================================================================================
//======================= ABSTRACT SYNTAC TREE EVALUATION ====================================

int astree(struct Tnode* nd)
{
              int r1,r2,r3;

              bool b;
              
              char array[100];
                                          
              if(nd == NULL){   return 0; }
            

        //---------        
                        if(nd->nodetype == STATEMENTLIST){  r1 = astree(nd->Ptr1);  r2 = astree(nd->Ptr2);  return 0; }
        //---------
                        if(nd->nodetype == EQUALTO){                                                                                                                                                                                    
                            if(nd->Ptr1->Ptr1 == NULL){

                                    r2 = astree(nd->Ptr2);

                                    fprintf(fp,"MOV [%d], R%d\n",symboltable[nd->Ptr1->symtabindex]->store,r2);

                                    freereg();

                                    if(strcmp(symboltable[nd->Ptr1->symtabindex]->type,"integer")==0)

                                       *(symboltable[nd->Ptr1->symtabindex]->datavalue.i) = r2; 
                                    else
                                       *(symboltable[nd->Ptr1->symtabindex]->datavalue.b) = r2;   
                            }
                            else{
                                    
                                    int index = astree(nd->Ptr1->Ptr1);

                                    r2 = getreg();

                                    fprintf(fp,"MOV R%d, %d\n", r2, symboltable[nd->Ptr1->symtabindex]->store);

                                    fprintf(fp,"ADD R%d, R%d\n", r2, index);
                                                                    
                                    fprintf(fp,"MOV [R%d], R%d\n", r2, astree(nd->Ptr2));

                                    freereg();   
                                    freereg();


                                    if(strcmp(symboltable[nd->Ptr1->symtabindex]->type,"integer")==0)

                                        *(symboltable[nd->Ptr1->symtabindex]->datavalue.i + index) = astree(nd->Ptr2);   
                                    else
                                        *(symboltable[nd->Ptr1->symtabindex]->datavalue.b + index) = astree(nd->Ptr2);
                            }                                                  

                            return 1;
                        }

        //---------
                        if(nd->nodetype == ID){   
                            
                            if(nd->Ptr1 == NULL){

                                  if(strcmp(nd->type,"integer")==0)

                                      return *(symboltable[nd->symtabindex]->datavalue.i);
                                  else
                                      return *(symboltable[nd->symtabindex]->datavalue.b);
                            }                                                    
                            else{

                                if(strcmp(nd->type,"integer")==0)
                            
                                    return *(symboltable[nd->symtabindex]->datavalue.i + astree(nd->Ptr1));
                                else
                                    return *(symboltable[nd->symtabindex]->datavalue.b + astree(nd->Ptr1));
                            }
                                                        
                        }


        //--------
                        if(nd->nodetype == NUM){  printf("jiji\n");return *(nd->datavalue.i); }

                        if(nd->nodetype == BOOL){ return *(nd->datavalue.b); }                      

                        if(nd->nodetype == PLUS){ r1 = astree(nd->Ptr1);  r2 = astree(nd->Ptr2);  return r1 + r2; }

                        if(nd->nodetype == MINUS){  r1 = astree(nd->Ptr1);  r2 = astree(nd->Ptr2);  return r1 - r2; }

                        if(nd->nodetype == MUL){  r1 = astree(nd->Ptr1);  r2 = astree(nd->Ptr2);  return r1 * r2; }

                        if(nd->nodetype == DIV){  r1 = astree(nd->Ptr1);  r2 = astree(nd->Ptr2);  return r1 / r2; }

                        if(nd->nodetype == MOD){  r1 = astree(nd->Ptr1);  r2 = astree(nd->Ptr2);  return r1 % r2; } 

                        if(nd->nodetype == LSEQ){  r1 = astree(nd->Ptr1);  r2 = astree(nd->Ptr2);  return r1 <= r2; } 

                        if(nd->nodetype == GREQ){  r1 = astree(nd->Ptr1);  r2 = astree(nd->Ptr2);  return r1 >= r2; } 

                        if(nd->nodetype == LSTHAN){  r1 = astree(nd->Ptr1);  r2 = astree(nd->Ptr2);  return r1 < r2; } 

                        if(nd->nodetype == GRTHAN){  r1 = astree(nd->Ptr1);  r2 = astree(nd->Ptr2);  return r1 > r2; } 

                        if(nd->nodetype == EQEQ){ r1 = astree(nd->Ptr1);  r2 = astree(nd->Ptr2);  return r1 == r2; }

                        if(nd->nodetype == NOTEQ){ r1 = astree(nd->Ptr1);  r2 = astree(nd->Ptr2);  return r1 != r2; }

                        if(nd->nodetype == AND){ r1 = astree(nd->Ptr1);  r2 = astree(nd->Ptr2);  return r1 && r2; }

                        if(nd->nodetype == OR){ r1 = astree(nd->Ptr1);  r2 = astree(nd->Ptr2);  return r1 || r2; }

                        if(nd->nodetype == NOT){ r1 = astree(nd->Ptr1); return !r1; }

        //---------
                        if(nd->nodetype == IF){

                            if(nd->Ptr3 == NULL){   b = astree(nd->Ptr1);   if(b == true) astree(nd->Ptr2);   }                          

                            else{   b = astree(nd->Ptr1);
                                
                                if(b == true){  r1 = astree(nd->Ptr2); }
                                
                                else{   r1= astree(nd->Ptr3); }
                            }

                            return 0;
                        }

          //---------
                        if(nd->nodetype == WHILE){  b = astree(nd->Ptr1);

                          while(b == true){   r1 = astree(nd->Ptr2);  b = astree(nd->Ptr1);   }

                          return 0;
                        }

          //---------
                        if(nd->nodetype == READ){

                            if(nd->Ptr1->Ptr1 == NULL){
                                    
                                    if(strcmp(symboltable[nd->Ptr1->symtabindex]->type,"integer")==0)

                                       scanf("%d",symboltable[nd->Ptr1->symtabindex]->datavalue.i);

                                    else{ scanf("%s",array);                                                                          

                                      if(strcmp(array,"true")==0)

                                        *(symboltable[nd->Ptr1->symtabindex]->datavalue.b) = true;
                                      else
                                        *(symboltable[nd->Ptr1->symtabindex]->datavalue.b) = false;
                                    }
                            }
                            else{
                                    
                                    int index = astree(nd->Ptr1->Ptr1);

                                    if(strcmp(symboltable[nd->Ptr1->symtabindex]->type,"integer")==0)

                                        scanf("%d",symboltable[nd->Ptr1->symtabindex]->datavalue.i + index);

                                    else{  scanf("%s",array);                                                                            
                                      
                                      if(strcmp(array,"true")==0)

                                        *(symboltable[nd->Ptr1->symtabindex]->datavalue.b + index) = true;                                        
                                      else
                                        *(symboltable[nd->Ptr1->symtabindex]->datavalue.b + index) = false;
                                    }                                        
                            }

                            return 0;
                        }
          //---------
                        if(nd->nodetype == WRITE){  r1 = astree(nd->Ptr1);  printf("%d\n",r1);  return 0; }


return 0;
}
//============================================================================================



//---------------SHOW SYMBOLTABLE--------------

void show_symboltable()
{
    int j=0;

    for(j=0;j<ind;j++)
    {
          printf("%s %s %d\n",symboltable[j]->name, symboltable[j]->type,symboltable[j]->size);

          int i=0,length;
          
          if(symboltable[j]->size == 0){  length=1; }

          else{ length = symboltable[j]->size; }
          
          for(i=0;i<length;i++)
          {
            if(strcmp(symboltable[j]->type,"integer")==0){  printf("%d ",(symboltable[j]->datavalue.i)[i]); }
            
            else{   printf("%d ",(symboltable[j]->datavalue.b)[i]); }

          }
          
          printf("\n");
      }
}

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
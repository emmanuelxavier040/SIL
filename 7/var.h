union store{
	int* i;
	bool* b;
};

struct vnode{
		char name[30];
		char type[30];
		int size;
		int store;
        union store datavalue;        	
};


struct Tnode {
		char name[30];
		char type[30];
		int nodetype;	//
		int size;
		union store datavalue; 
		struct Tnode *Ptr1, *Ptr2, *Ptr3;
		int symtabindex;		
};

#define YYSTYPE struct Tnode*

struct Tnode *TreeCreate(char name[], char type[], int nodetype, int VALUE, struct Tnode* Ptr1, struct Tnode* Ptr2, struct Tnode* Ptr3);

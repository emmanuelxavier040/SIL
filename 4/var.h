union store{
	int* i;
	bool* b;
};

struct vnode{
		char name[30];
		char type[30];
		int size;
        union store datavalue;        	
};


#define YYSTYPE struct vnode*




struct Tnode {
		char name[30];
		char type[30];
		int nodetype;		
		union store datavalue; 
		struct Tnode *Ptr1, *Ptr2, *Ptr3;
		struct vnode *Gentry; 		
};

struct Tnode *TreeCreate(char name[], char type[], int nodetype, int VALUE, struct Tnode* Ptr1, struct Tnode* Ptr2, struct Tnode* Ptr3);

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
		int TYPE;
		int NODETYPE;
		char* NAME; 
		int VALUE; 
		Tnode *ArgList;
		Tnode *Ptr1, *Ptr2, *Ptr3;
		Gsymbol *Gentry; 
		Lsymbol *Lentry; 
};
struct Tnode *TreeCreate(TYPE,NODETYPE,VALUE,NAME,ArgList,Ptr1, Ptr2, Ptr3);

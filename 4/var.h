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


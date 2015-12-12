#include <stdio.h>
#include <string.h>

int main()
{
	char st[100];
    char s1[100];
    char s2[100];
    char $$[100];
    strcpy(st,"+ "); strcpy(s1,"hi "); strcpy(s2,"hello ");strcat(s1,s2); strcat(st,s1); strcpy($$,st);
    printf("%s\n",$$);
    return 0;
}
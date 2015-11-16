#include<stdio.h>
#include<string.h>

char * fun()
{
	char  s[10] ;
	strcpy(s,"helolo");
	return s ;
}

int main()
{
	char * s = fun() ;
	//dangling ptr
	printf("%s",s);
}

#include<iostream>
#include<stdio.h>
using namespace std ;


void reverse(char *s)
{
	if(*s=='\0')
		return ;
	reverse(s+1) ;
	printf("%c",*s);
}

int main()
{
	char s[100];
	scanf("%s",s);
	reverse(s);
}


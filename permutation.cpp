#include<stdio.h>
#include<iostream>

using namespace std ;



void swap(char *x,char *y)
{
	char t = *x;
	*x = *y ;
	*y = t;
}

void permute(char *str,int s,int e)
{
	if(s==e)
		printf("%s\n",str);
	else{
		for(int j=s ; j<=e ; j++)
		{
			swap((str+s),(str+j)) ;
			permute(str,s+1,e);
			swap((str+s),(str+j)) ;
					
		}
	}
}

int main()
{
	char s[100] ;
	scanf("%s",&s);
	permute(s,0,strlen(s)-1 );
}

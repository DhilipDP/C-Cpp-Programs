#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std ;

int main(){
	char str[] = "hello\nworld";
	int n = strlen(str);
	int set_array[n];
	memset(set_array,1,sizeof(set_array));
	char *p1,*p2 ;
	p1 = &str[3] ;
	p2 = str+5;

	int val = printf("%c",++*str- --*p1+*p2+2);
	set_array[val] = 0;
	cout<<str<<endl;
	for(int i=0 ; i<n ; i++)
		cout<<set_array[i]<<" ";
		
	return 1 ;
}

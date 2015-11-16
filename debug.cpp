#include<iostream>
#include<stdlib.h>
using namespace std ;
int main(){
	int a = 5,c=9,b,*g ;
	g = &c ; 
	b= (a=a+4) * ((*g)++);
	int *p=NULL ;
	realloc(p,0);
	cout<<p;
	cout<<b;
}

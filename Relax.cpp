#include<iostream>
#include<stdio.h>
using namespace std;

int main(){
	while(1){

	int a,b;
	scanf("%d%d",&a,&b);
	if(a==-1)
		break;
	if(a==1 || b==1){
		printf("%d+%d=%d\n",a,b,a+b);
	}
	else
		printf("%d+%d!=%d\n",a,b,a+b);		
}
}

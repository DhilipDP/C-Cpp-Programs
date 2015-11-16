#include<iostream>
#include<stdio.h>
using namespace std;


int sum(int a,int b){
	return printf("%*c%*c",a,'\r',b,'\r');
}
int main(){
//	int c = 10;

	int a,b;
	cin>>a>>b;
	cout<<"Sum is :" <<sum(a,b);
//	printf("%c",'\r');
//	printf("hello");
}

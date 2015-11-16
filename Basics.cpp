#include<iostream>
#include"extern_test.h"
using namespace std;

extern int val;

int f(int a,int b){
	a+=1;
	b+=2;
	return (a,b);
}


int main(){
	cout<<val<<" ";
	int a = 5;
	int test = 1;
	cout<< (test==1) ? "ac" : 0;
}

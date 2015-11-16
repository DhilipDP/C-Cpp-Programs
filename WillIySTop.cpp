#include<iostream>
#include<stdio.h>
using namespace std;

int main(){
	long long int n;
	scanf("%lld",&n);
	if((n%3==0 && n%5==0) || ((n & (n-1)) == 0))
		printf("TAK");
	else
		printf("NIE");	
}

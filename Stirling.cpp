#include<iostream>
#include<stdio.h>
using namespace std;

int main(){
	int tests;
	scanf("%d",&tests);
	while(tests--){
	long int n,k;
	scanf("%ld%ld",&n,&k);
	if( (n-k) & ((k-1)/2) )
		printf("0\n");
	else
		printf("1\n");
	}
}

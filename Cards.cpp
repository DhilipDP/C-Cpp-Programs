#include<stdio.h>
#include<iostream>
#define mod 1000007
using namespace std;

int sum(long long int n){
	long long int val1,val2;
	if(n%2){
		val1=n+1;
		val2=n;
	}
	else{
		val1=n;
		val2=n+1;
	}
	return ((val1/2)%mod * (val2))%mod;
}

int main(){
	int tests;
	scanf("%d",&tests);
	while(tests--){
		
		long long int n;
	    int val;
		scanf("%d",&n);
		val=(sum(n-1) + (2*sum(n))%mod)%mod;
		printf("%d\n",val);
	}
	return 0;
}

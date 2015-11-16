#include<stdio.h>
#include<math.h>
#include<iostream>
#include<stdlib.h>
using namespace std;

int arr[100000]={0};

bool check(long long int n){
	long long int j=0;
	for(long long int i=sqrt(n) ; j*j <=n ; ){
		if(i*i + j*j == n)
			return true;
		if(i*i + j*j < n)
			j++;
		else
			i--;
	}
	return false;
}

int main(){
	
	int tests;
	scanf("%d",&tests);
	while(tests--){
		long long int n;
		scanf("%lld",&n);
		if(check(n))
			printf("Yes\n");
		else
			printf("No\n");
		}
}

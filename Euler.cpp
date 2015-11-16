#include<stdio.h>
#include<iostream>

using namespace std;


int euler(int n){
	int result = n;
	for(int i=2 ; i*i <= n ; i++){
		if(n%i==0)
			result -= result/i;
		while(n%i==0)
			n /= i;
	}
	if(n>1)
		result -= result/n;
	return  result;
}
int main(){
	int tests;
	scanf("%d",&tests);
	while(tests--){
		int n;
		scanf("%d",&n);
		printf("%d\n",euler(n));
	}
}

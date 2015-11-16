#include<iostream>
#include<stdio.h>

int  main(){

	long long int n;
	scanf("%lld",&n);
	long long int even_sum=0;
	long long int odd_sum = 0;
	even_sum = (n/2) * ((n/2)+1);
	if(n%2){
		odd_sum = ((n+1)/2)*((n+1)/2);
	}
	else
		odd_sum = (n/2)*(n/2);
	printf("%lld",even_sum-odd_sum);
	return 0;
}

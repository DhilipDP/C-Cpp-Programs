#include<iostream>
#include<stdio.h>
using namespace std;



bool isPrime(long long int num)
{
	if(num==2 || num==3)
		return true;
	if(num==1 || num % 2 ==0)
		return false;
	if(num%3==0)
		return false;
	long long	int i=5 ,w=2;
	while(i*i <= num){
		if(num % i==0)
			return false;
		i += w;
		w = 6 - w;
	}
	return true;
}
int main(){
	int tests;
	scanf("%d",&tests);
	while(tests--){
		long long int n;
		scanf("%lld",&n);
		if(isPrime(n))
			printf("YES\n");
		else
			printf("NO\n");
	}
}

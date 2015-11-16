#include<stdio.h>
#include<iostream>
using namespace std;


long int findGcd(long int a,long int b){
	if(a<b)
		return findGcd(b,a);
	if(b==0)
		return a;
	return findGcd(b,a%b);
}
long int findLcm(long int a,long int b){
	return (a*b)/findGcd(a,b);
}
int main(){
	//cout<<findGcd(2,5);
	long int t;
	scanf("%d",&t);
	while(t--){
		long int n;
		scanf("%d",&n);
		long int sum = 0;
		for(long int i=1 ; i<=n ; i++)
		{
			sum += findLcm(i,n);
		}
		printf("%d\n",sum);
	}
}

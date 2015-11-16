#include<iostream>
#include<stdio.h>
using namespace std;

long long int gcd(long long int a,long long int b){
	if(a<b)
		return gcd(b,a);
	if(b==0)
		return a;
	return gcd(b,a%b);
}

int main(){
	int tests;
	scanf("%d",&tests);
	while(tests--){
		long long int a,b;
		scanf("%lld%lld",&a,&b);
		if(a==0 || b==0)
			cout<<"0";
		else
//		cout<<findModulus(a,b)<<endl;
		printf("%d\n",(a*b)/gcd(a,b));
	}
}

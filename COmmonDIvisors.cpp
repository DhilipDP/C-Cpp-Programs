#include<stdio.h>
#include<iostream>
#include<math.h>
using namespace std;

long long int findGcd(long long int a,long long int b)
{
//	cout<<"A: "<<a<<" "<<"B: "<<b;
	if(a<b)
		findGcd(b,a);
	else if(b==0)
		return a;
	return findGcd(b,a%b);
}
int main()
{
//	cout<<747794 % 238336;
	long long int tests;
	scanf("%lld",&tests);
	while(tests--){
		long long int a,b;
		scanf("%lld%lld",&a,&b);
		long long int gcd = findGcd(a,b);
	//	cout<<gcd;
		if(gcd==1)
			printf("1\n");
		else{
		long long int val = sqrt(gcd);
		long long int count = 0;
		for(int i =1  ; i<= val ; i++){
			if(gcd % i==0 ){
				if(i!=1 && i == gcd/i)
					count++;
				else 
					count+=2;
			}
			
		}
		printf("%lld\n",(count));
	}}
	
}


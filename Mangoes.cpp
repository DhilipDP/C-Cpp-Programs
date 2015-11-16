#include<stdio.h>

int main(){
	;
	int tests;
	scanf("%d",&tests);
	while(tests--){
		long long int n,num;
		scanf("%lld",&n);
		long long int val ;
		num = (n-2)/2;
		if(n%2)
			val = ((n/2)*(n/2))%n;
		else
			val = (num*num)%n;
		printf("%d\n",val);
	}
}

#include<stdio.h>

int main(){
	int tests;
	scanf("%d",&tests);
	while(tests--){
		long long int k;
		scanf("%lld",&k);
		printf("%lld\n",((k-1)*250 + 192));
	}
}

#include<stdio.h>

int main(){
	int tests;
	scanf("%d",&tests);
	while(tests--){
		long long int n,ans;
		scanf("%lld",&n);
		if(n%2)
			ans = (n*(n+2)*(2*n+1)-1)/8;
		else
			ans = (n*(n+2)*(2*n+1))/8;
		printf("%lld\n",ans);
	}
}

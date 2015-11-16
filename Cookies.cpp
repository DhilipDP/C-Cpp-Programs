#include<stdio.h>

int main(){
	int tests;
	scanf("%d",&tests);
	while(tests--){
		int n,a,d;
		scanf("%d%d%d",&n,&a,&d);
		float val = (float)n/2.0;
		int mul = 2*a + (n-1)*d;
		float ans = val * mul;
		printf("%d\n",(int)ans);
	}
}

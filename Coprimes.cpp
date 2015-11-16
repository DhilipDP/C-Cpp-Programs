#include<stdio.h>
#include<math.h>


unsigned long long int gcd(unsigned long long int a,unsigned long long int b){
	if(a < b)
		return gcd(b,a);
	if(b==0)
		return a;
	return gcd(b,a%b);
}
int main(){
	int tests;
	scanf("%d",&tests);
	while(tests--){
		unsigned long long int n,max = 1;
		scanf("%llu",&n);
		if(n==1)
			printf("0\n");
		else{
		unsigned long long int val = n/2;
		for(unsigned long long int i=val ; i>=2 ; i--)
		{
			unsigned long long int p = gcd(i,n);
		//	printf("%llu",p);
			if(p==1 ){
				max = i;
				break;
			}
		}
		printf("%llu\n",max);
	}}
	
	return 0;
}

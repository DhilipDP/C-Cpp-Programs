#include<stdio.h>

int factorial(int val){
		int fact=1;
		if(val==0)
			return 1;
		for(int i=1 ; i<=val ; i++)
			fact=fact*i;
		return fact;	
	}

	int combination(int n,int k){
		return ((factorial(n))/(factorial(k) * factorial(n-k)));
	}
	
	int main(){
		int tests;
		scanf("%d",&tests);
		while(tests--){
			int n;
			scanf("%d",&n);
			for(int i=0 ; i<=n ; i++)
			{
				for(int j=0 ; j<=i ; j++ )
					printf("%d ",combination(i,j));
				printf("\n");
			}
			printf("\n");
		}
	}

#include<stdio.h>
#include<math.h>
int main()
{
	int tests;
	scanf("%d",&tests);
	while(tests--){
		int i=0;
		long long third,thirdlast,sum;
		scanf("%lld%lld%lld",&third,&thirdlast,&sum);
		long double val =( sum/(third+thirdlast) ) ;
		long long n = (val) * 2;
		printf("%d",n);
		long long d = (thirdlast - third ) / ((n-3) - 2);
		long long a = (third - (2*d));
		printf("%lld\n",n);
		for(long long i=0 ; i<n ; i++)
			printf("%lld ",a+(i*d));
		if(tests!=0)
		printf("\n"); 
	}
}


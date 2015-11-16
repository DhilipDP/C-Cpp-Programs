#include<stdio.h>
#include<iostream>
using namespace std;

int main()
{
	int tests;
	scanf("%d",&tests);
	for(int i=1 ; i<=tests ; i++){
		long int a,b,n;
		scanf("%ld%ld%ld",&a,&b,&n);
		printf("Case %d: ",i);
		int val = a+b;
		if(n<a && n<b || ((a==0) && (b==0)))
			printf("Not Possible\n");
		else if(n==a || n==b)
			printf("1\n");
		else if(n==val)
		{
			if(a!=0 && n%a==0){
				printf("%d\n",(n/a));
			}
			else if(b!=0 && n%b==0)
				printf("%d\n",(n/b));
			else
				printf("Not Possible\n");
		}
		else{
		int gt,les;
		if(a > b){
			gt = a;
			les = b;
		}
		else{
			gt = b;
			les = a;
		}
		if(n % gt == 0 )
			printf("%d\n",n/gt);
		else if(n%val==0)
			printf("%d\n",(n/val)*2);
		else if(n%val==a || n%val==b){
				printf("%d\n", (n/val)*2 + 1);
			}
		else if(n % les ==0 )
			printf("%d\n",n/les);
		else
			printf("Not Possible\n");
		}
		
	}
}

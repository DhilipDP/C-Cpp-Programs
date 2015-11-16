#include<iostream>
#include<stdio.h>
using namespace std ;

int main()
{
	unsigned long long int a,b;
	while(scanf("%lld%lld",&a,&b)==2)
	{
		if(a>0 && a<1000000 && b>0 && b<1000000){
			printf("%lld %lld ",a,b);
		if(a>b){
		unsigned long long 	int temp = a;
			a=b;
			b=temp;
		}
		int maxi = 0;
		for(int i=a ; i<=b ; i++)
		{
			int count = 1;
		unsigned long long	int n=i;
			while(n>1){
			if(n%2){
				n = (n*3+1);
			
				count ++;
			}
			else{
				n/=2;
				count++;
			}
		
			}
		//	cout<<count<<endl;
		 if(count > maxi)
		 	maxi = count;
			
		}
		printf("%d\n",maxi);
	}
	}
}

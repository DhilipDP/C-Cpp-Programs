#include <iostream>
#include<stdio.h>
using namespace std;
 
 
long long int min(long long int a, long long int b)
{
	return a < b ? a : b ;
}
int main()
{
	int t ; cin>>t ;
	while(t--)
	{
		long long int l,b,h ;
		scanf("%lld%lld%lld",&l,&b,&h);
		double val = min(min(l,b),h);
		float p = 2.0;
		printf("%.1f\n",val/p);
	}
    return 0;
}

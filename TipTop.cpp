#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;

int main(){
	int tests;
	scanf("%d",&tests);
	for(int i=1 ; i<=tests ; i++){
		long long int n;
		scanf("%lld",&n);
		long long int val = sqrt(n);
	//	cout<<val;
		if(val*val==n)
			printf("Case %d: Yes\n",i);
		else
			printf("Case %d: No\n",i);
	}
}

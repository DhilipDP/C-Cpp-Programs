#include <iostream>
#include<vector>
#include<stdio.h>
#include<stack>
#include<vector>
#include<queue>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<limits.h>
#include<map>
#include<algorithm>
#include<utility>


#define ll long long
#define p(a) printf("%d\n",a)
#define s(a) scanf("%d",&a)
#define sll(a) scanf("%lld",&a)
#define sl(a) scanf("%ld",&a)
#define FOR(a,b,it) for( it=a ; it<=b ; ++it)
#define pi pair<int,int> 

using namespace std ;

int main() {
	int t;
	s(t);
	while(t--)
	{
		ll int n,k,l;
		sll(n);
		sll(k);
		sll(l);
		ll int arr[n];
		int i;
		arr[0] = l%k==0 ? k : l%k;
		FOR(1,n-1,i){
			ll int ans = l%(int)pow(k,i+1);
			cout<<pow(k,i+1);
			arr[i] = (ans==0) ? k :  ceil((float)ans/(float)pow(k,i));
		//	cout<<arr[i]<<" ";
		}
		for(i=n-1 ; i>=0 ; i--)
			printf("%lld ",arr[i]);
		printf("\n");
	}
	return 0 ;
}

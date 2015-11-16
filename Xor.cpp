#include<iostream>
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
	int n;
	s(n);
	int arr[n];
	int i;
	FOR(0,n-1,i)
		s(arr[i]);
	int q;
	s(q);
	int pre[n] ;
	int x = 0;
	pre[0] = arr[0];
	FOR(1,n-1,i)
		pre[i] = (pre[i-1] ^ arr[i]);
	while(q--){
		int l,r;
		s(l);
		s(r);
		int ans = 0;
		for(int i=l-1 ; i<=r-1 ; i++)
			ans ^= arr[i];
		p(ans);
	}
	return 0 ;
}

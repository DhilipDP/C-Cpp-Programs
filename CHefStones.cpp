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
#define FOR(a,b) for(int i=a ; i<=b ; ++i)
#define pi pair<int,int> 

using namespace std ;

int main() {
	int t ;
	s(t);
	while(t--){
		ll	int n,k ;
		sll(n);
		sll(k);
		ll int maxi = INT_MIN ;
		ll int a[n],b[n];
		FOR(0,n-1)
			sll(a[i]);
		FOR(0,n-1)
			sll(b[i]);
		FOR(0,n-1){
			maxi =  max(maxi,(k/a[i]) * b[i]); 
		}
		cout<<maxi<<endl;
			
	}
	return 0 ;
}

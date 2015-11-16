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
#define mod 1000000007
using namespace std ;

int main() {
	int n,m;
	s(n);
	s(m);
	int i,j;
	ll int A[n+1],B[m],C[m] ;
	FOR(1,n,i)
		sll(A[i]);
	FOR(0,m-1,i)
		sll(B[i]);
	FOR(0,m-1,i)
		sll(C[i]);
	FOR(0,m-1,i){
		int k;
		for(k = 1 ; (k*i)<=n ;k++ ){
			A[k*i] = (A[k*i]*C[i])%mod;
		}
	}
	FOR(1,n,i)
		cout<<A[i]<<" ";
	return 0 ;
}

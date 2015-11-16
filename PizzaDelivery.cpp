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


#define ll long long
#define p(a) printf("%d\n",a)
#define s(a) scanf("%d",&a)
#define sll(a) scanf("%lld",&a)
#define sl(a) scanf("%ld",&a)
#define FOR(a,b) for(int i=a ; i<=b ; ++i)

using namespace std ;

struct val{
	int x;
	int y;
	int v;
};


int maximum(int a,int b){
	return a>b ? a : b;
}
int main() {
	int n,x,y;
	s(n);
	s(x);
	s(y);
	int A[n];
	int B[n];
	FOR(0,n-1)
		s(A[i]);
	FOR(0,n-1)
		s(B[i]);
	int sum = 0;
	val ar1[n];
	val dp[n];
	int maxi =  max(A[0],B[0]);
	if((maxi==A[0] && x!=0) || y==0){
			dp[0].v = A[0] ;
			dp[0].x = x-1;
			dp[0].y = y;
	}
	else if ((maxi==B[0] && y!=0) || x==0) {
			dp[0].v = B[0] ;
			dp[0].x = x;
			dp[0].y = y-1;
		
	}
//	cout<<dp[0].v<<endl;
	FOR(1,n-1){
		maxi = max(A[i],B[i]);
		if((maxi==A[i] && dp[i-1].x!=0) || dp[i-1].y==0){
			dp[i].v = dp[i-1].v + A[i] ;
			dp[i].x = dp[i-1].x-1;
			dp[i].y = dp[i-1].y;
		}
	else if ((maxi==B[i] && dp[i-1].y!=0) || dp[i-1].x==0){
			dp[i].v = dp[i-1].v + B[i] ;
			dp[i].x = dp[i-1].x;
			dp[i].y = dp[i-1].y-1;
		
		}
	//	cout<<dp[i].v<<endl;
	}
	p(dp[n-1].v);
	
	return 0 ;
}

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

int calc(int weight[],int prices[] ,int n,int cap){
	int dp[2][cap+1];
	FOR(0,1)
		for(int j=0 ; j<=cap ; j++)
			dp[i][j] = 0;
	FOR(0,n){
		int ii = i&1;
		for(int j=1 ; j<=cap ; j++){
			if(weight[i-1] > j)
				dp[ii][j] = dp[1-ii][j];
			else
				dp[ii][j] = max(dp[1-ii][j], prices[i-1] + dp[ii][j-weight[i-1]]);
		}
	}
	return (n & 1) ? dp[1][cap] : dp[0][cap];
}

int main() {
	int t;
	s(t);
	while(t--){
		int cap ;
		s(cap);
		int n;
		s(n);
		int weight[n] ;
		int prices[n];
		FOR(0,n-1)
			s(weight[i]);
		FOR(0,n-1)
			s(prices[i]);
		p(calc(weight,prices,n,cap));
	}
	return 0 ;
}

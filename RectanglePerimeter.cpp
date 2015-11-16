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
#define sl(a) scanf("%lld",&a)
#define sll(a) scanf("%ld",&a)
#define FOR(a,b) for(int i=a ; i<=b ; ++i)

using namespace std ;

int main() {
	int n ;
	s(n);
	long long int val = 0;
	int temp = 0;
	int width[n] ;
	int height[n] ;
	FOR(0,n-1){
		s(width[i]);
		s(height[i]);
	}
	int dp[2][n] ;
	dp[0][0] = width[0] ;
	dp[1][0] = height[0] ;
	FOR(1,n-1){
		dp[0][i] = max(dp[0][i-1] + width[i] + abs(height[i]-height[i-1]) , dp[1][i-1] + width[i] + abs(height[i]-width[i-1])) ;	
		dp[1][i] = max(dp[0][i-1] + height[i] + abs(width[i]-height[i-1]) , dp[1][i-1] + height[i] + abs(width[i]-width[i-1])) ;
		//cout<<dp[0][i]<<" "<<dp[1][i]<<endl;
	}
	printf("%d",max(dp[0][n-1],dp[1][n-1]));
	return 0 ;
}


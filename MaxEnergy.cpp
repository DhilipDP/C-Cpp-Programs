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

int main() {
	int t;
	s(t) ;
	while(t--)
	{
		int m,n ;
		s(m);
		s(n);
		int mat[m][n] ;
		for(int i=0 ; i<m ; i++)
			for(int j=0 ; j<n ; j++)
				s(mat[i][j]);
	
		int dp[m][n];
		dp[0][0] = mat[0][0] ;
	//	cout<<dp[0][0]<<endl;
		FOR(1,n-1)
			dp[0][i] = dp[0][i-1] - mat[0][i] ;
		FOR(1,m-1)
			dp[i][0] = dp[i-1][0] - mat[i][0] ;
		FOR(1,m-1){
			for(int j=1 ; j<n ; j++){
				dp[i][j] = max(dp[i-1][j]-mat[i][j],dp[i][j-1]-mat[i][j]);
			}
		}
	/*	for(int i=0 ; i<m ; i++)
		{
				for(int j=0 ; j<n ; j++)
					cout<<dp[i][j]<<" ";
				cout<<endl;
		} */
		if(dp[m-1][n-1] < 0)
			p(-1);
		else
			p(dp[m-1][n-1]);
	}
	return 0 ;
}


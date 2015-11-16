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
#define mod 1000000007

using namespace std ;



int dp(ll  int n,ll int k){

	 int C[n+1][k+1];
	int i,j;
	for(i=0 ; i<=n ; i++){
		for(j=0 ; j<=k ; j++)
		{
			if(j==0 || j==i)
				C[i][j] =  1;
			else
			C[i][j] = (C[i-1][j-1] + C[i-1][j])%3;
		}
	
	}
	return C[n][k]%3;
}
int main() {
	int t ;
	s(t);
	while(t--){
		ll int n ;
		sll(n);
		ll int sum = 0;
		FOR(0,n)
			sum = (sum%mod + dp(n,i)%mod)%mod;
		cout<<sum<<endl;		
	}

	return 0 ;
}

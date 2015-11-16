#include<bits/stdc++.h>

#define ll long long
#define p(a) printf("%d\n",a)
#define pll(a) printf("%lld\n",a)
#define s(a) scanf("%d",&a)
#define sll(a) scanf("%lld",&a)
#define sl(a) scanf("%ld",&a)
#define rep(a,b,c) for(int c=a ; c<=b ; ++c)
#define pii pair<int , int>
#define vi vector<int>
#define vs vector<string>
#define vi_it vector<int> :: iterator
#define vs_it vector<string> :: iterator
#define mp(a,b) make_pair(a,b)
#define MOD 1000000007


using namespace std ;

ll int dp[1000005] ;

void init()
{
	dp[1] = 1 , dp[2] = 2 ;
	rep(3,1000005,i)
		dp[i] = (dp[i-1] + ((i-1)*dp[i-2])%MOD ) % MOD ;
}

int main() {
	ios :: sync_with_stdio(false);
	int t ;
	s(t) ;
	init();
	while(t--)
	{
		int n  ; s(n);
		p(dp[n]);
	}
	return 0;
}

#include<bits/stdc++.h>

#define ll long long
#define p(a) printf("%d\n",a)
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
#define pll(a) printf("%lld\n",a)

using namespace std ;


ll int modular_exponentiation(ll int a , ll int b)
{
		ll  int ans = 1 ;
		while(  b != 0 )
		{
			if( b & 1)
			{
				ans = (ans * a) % MOD ;
			}
			a = (a*a) % MOD ;
			b >>= 1;
		}	
		return ans ;
}

int main() {
	ios :: sync_with_stdio(false);
	
	
	pll(modular_exponentiation(2,10));
	return 0;
}

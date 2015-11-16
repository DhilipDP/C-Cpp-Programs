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


 int hcf( int a , int b)
{
	if(b==0)
		return a ;
	return hcf( b , a%b) ;
}

ll int gcd( int arr[] , int n)
{
	if(n==1)
		return arr[0] ;
	ll int _gcd = hcf(arr[0] , arr[1]) ;
	
	int i=2 ;
	
	while( i < n)
		_gcd = hcf(_gcd,arr[i++]);
	
		
	return _gcd ;
	
}

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


ll int prod(int arr[] , int n)
{
	ll int ans =  1 ;
	rep(0,n-1,i)
		ans = (ans * arr[i]) % MOD  ;
	return ans ;
}

int main() {
	ios :: sync_with_stdio(false);
	
	 int n ; s(n)  ;
	int arr[n] ;
	rep(0,n-1,i)
		s(arr[i]) ;
	
	ll int g = gcd(arr ,  n)  ;
	
	ll int f = prod(arr ,  n) ;
	
	cout<<f<<" "<<g<<endl;
	pll(modular_exponentiation(f,g)) ;
		
	
	
	return 0;
}

#include<bits/stdc++.h>

#define ll long long
#define p(a) printf("%d",a)
#define pll(a) printf("%lld",a)
#define pn printf("\n")
#define pb(a) push_back(a)

#define s(a) scanf("%d",&a)
#define sll(a) scanf("%lld",&a)
#define sl(a) scanf("%ld",&a)
#define rep(a,b,c) for(int c=a ; c<=b ; ++c)
#define pii pair<int , int>
#define vi vector<int>
#define vpii vector< pii >
#define vs vector<string>
#define vi_it vector<int> :: iterator
#define vs_it vector<string> :: iterator
#define mp(a,b) make_pair(a,b)


using namespace std ;

vi a(10001) ;
vi b(10001) ;


ll int sq(ll int x)
{
	return x*x;
}
int main() {
	ios :: sync_with_stdio(false);
	int t ; s(t) ;
	
	a[1] = 1 , b[1] = 1 ;

	rep(2,10000,i){
		a[i] = a[i-1] + b[i-1] ;
		b[i] = a[i-1];
	}
	
	while(t--)
	{
		ll int n ; sll(n) ; 
		
		pll(sq(a[n] + b[n]));
		pn;
	}
	return 0;
}

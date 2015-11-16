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


void mul(ll int F[2][2] , ll int M[2][2] , int mod)
{
	ll int x =  (F[0][0]*M[0][0] + F[0][1]*M[1][0] ) % mod,
	y =(F[0][0] * M[0][1] + F[0][1] * M[1][1] ) % mod,
	z =( F[1][0] * M[0][0] + F[1][1] + M[1][0] ) % mod,
	a =( F[1][0] * M[0][1] + F[1][1] + M[1][1] ) % mod;
	
	
	F[0][0] = x , F[0][1] = y , F[1][0] = z , F[1][1] = a;	
}

void power(ll int F[2][2] , ll int n , int mod)
{
	ll int M[2][2] = {{1,1} ,{1,0} } ;
	if(n==0 || n==1)
		return ;
	power(F,n/2,mod) ;
	mul(F,F,mod) ;
	if(n % 2 != 0)
		mul(F,M,mod);


}

ll int fib(ll int n , int mod)
{
	ll int F[2][2] = {{1,1} , {1,0}}	 ;
	if(n==0 ||  n==1)
		return 1 ;
	power(F,n-1,mod) ;
	return F[0][0];
}


int main() {
	ios :: sync_with_stdio(false);
	int t ; s(t) ;
	while(t--)
	{
		ll int a , b ; sll(a) ; sll(b) ;
	
		pll((fib(a+2,b)-1) % b) ;
       // pn;
	}
	
	return 0;
}

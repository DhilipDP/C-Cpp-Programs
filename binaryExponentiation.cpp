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
#define MOD 1000000007

using namespace std ;
	ll modular_pow(ll base, ll exponent, int modulus)
{
    ll result = 1;
    while (exponent > 0)
    {
        if (exponent % 2 == 1)
            result = (result * base) % modulus;
        exponent = exponent >> 1;
        base = (base * base) % modulus;
    }
    return result;
}
int main() {
	int t ;
	s(t);
	while(t--){
		ll int n , m ;
		sll(n);
		sll(m) ;
		if(n==1)
			cout<<m<<endl;
		else if(n==2)
			cout<<m*(m-1)<<endl;
		else{
			ll int val =  (m*(m-1))%MOD;
			cout<<(val * modular_pow(m-2,n-2,MOD))%MOD<<endl;
		}
	}
	return 0 ;
}

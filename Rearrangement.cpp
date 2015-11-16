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
#define mod 100007
using namespace std ;

	int power(int base, int exponent)
{
    int result = 1;
    while (exponent > 0)
    {
        if (exponent % 2 == 1)
            result = (result * base) % mod;
        exponent = exponent >> 1;
        base = (base * base) % mod;
    }
    return result;
}
int main() {
	int n;
	s(n);
	int sum = 0;
	FOR(0,n-1){
		int val;
		s(val);
		sum = (sum +val);
	}
	int q = (sum/n);
	int r = (sum%n);
	int ans = (power(q+1,r) * power(q,n-r))%mod;
	
	p(ans);	
	return 0 ;
}

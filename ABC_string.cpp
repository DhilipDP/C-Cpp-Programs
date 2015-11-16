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

using namespace std ;




	ll int power( ll int base, ll int exponent)
{
    ll int result = 1;
    while (exponent > 0)
    {
        if (exponent % 2 == 1)
            result = (result * base) % MOD;
        exponent = exponent >> 1;
        base = (base * base) % MOD;
    }
    //cout<<result<<endl;
    return result;
}

ll int mul(ll int  n)
{

	int k = 2 ,temp=n;
	while(k--)
		n = (temp+n)%MOD ;
	return n ;
}
int main() {
	ios :: sync_with_stdio(false);

	int t ;
	s(t) ;
	while(t--)
	{
		ll int n ; sll(n) ;
		if(n<3)
		{
			cout<<"0"<<endl;
			continue;
		}
		printf("%lld\n",(mul((power(3,n-1) - power(2,n) )+ 1)%MOD)%MOD);
	}
	return 0;
}

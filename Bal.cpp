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

int main() {
	ios :: sync_with_stdio(false);

	int n,q; s(n) ;
	int temp = n ;
	
		vector< ll int > v(n) ;
		rep(0,n-1,i) sll(v[i]);
		sort(v.begin() , v.end());
		
		
			rep(1,n-1,i)
				v[i] += v[i-1];
		s(q);
	while(q--)
	{
		int k ; s(k) ;
		if(k==0)
		{
			pll(v[n-1]); pn ;
			continue ;
		}
		k++;
		ll int p = (n-1) / k ;
		pll(v[p]) ; pn;
	}
	return 0;
}

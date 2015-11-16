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

	int n ; s(n) ;
	vi pre_sum(n+1,0);
	rep(1,n,i)
	{
		s(pre_sum[i]);
		pre_sum[i] += pre_sum[i-1];
		p(pre_sum[i]);
	}
	int q ; s(q) ;
	while(q--){
		int l,r ; s(l) ; s(r) ;
		printf("%.6f\n",((float)(pre_sum[r]-pre_sum[l-1])/(float)(r-l+1)));
	}
	return 0;
}

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

int N ;
struct comp{
	bool operator()(pii & a,pii &b)
	{
		return a.first > b.first ;
	}
};


priority_queue<pii , vector< pii > , comp> m_heap ;
int main() {
	ios :: sync_with_stdio(false);

	
	return 0;
}

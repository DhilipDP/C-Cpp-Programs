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
	int t ; s(t) ;
	while(t--)
	{
		int n ; s(n) ;
		int ones = 0 , zeroes = 0;
		rep(1,n,i)
		{
			int val ; s(val) ;
			if(val==0) zeroes++;
			else	 ones++;
		}
		if(n & 1==0)
		{
			cout<<"0"<<endl;
			continue;
		}
		if(ones & 1)
			p(ones);
		else
			p(zeroes);
		pn;
	}
	return 0;
}

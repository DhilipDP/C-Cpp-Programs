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


using namespace std ;

int main() {
	ios :: sync_with_stdio(false);

	int t ;
	s(t) ;
	while(t--)
	{
		int c=0;
		int n ; s(n) ;
		int k ; s(k) ;
		rep(0,n-1,i)
		{
			int val ;s(val) ;
			if((val+k) % 7==0)
				c++;
		}
		p(c);
	//	pn;
	}
	return 0;
}

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
#define ch(a) a-97

using namespace std ;


string A,B ;
int m,n ;
int a,b,c;
int h[26];

void init()
{
	memset(h,0,sizeof(h));
}
int minTrans()
{
	cout<<"hi";
	int ans = 0;
	int  repl =0;
	if( m < n)
		ans += a ;
	cout<<ans<<endl;
	if( m > n)
		ans += b ;
	cout<<ans<<endl;
	rep(0,m-1,i)
		h[ch(A[i])]++;
	rep(0,n-1,i)
		h[ch(B[i])]--;
	rep(0,25,i)
		repl += abs(h[i]) ;

	repl /= 2;
//	cout<<repl<<endl;
	ans += min(repl*c , repl*a + repl*b);
	return ans;
	
}

int main() {
	//ios :: sync_with_stdio(false);
	int t ; s(t) ;
	while(t--)
	{
		init();
		cin>>A>>B ;
		m = A.length()  , n = B.length() ;
		s(a) ; s(b) ; s(c) ;
	
		p(minTrans());
	}
	return 0;
}

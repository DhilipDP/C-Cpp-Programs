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


ll int convert(string s)
{
	cout<<s<<endl;
	ll int ans = 0;
	for(int i=0 ; i<=7 ;i++)
		if(s[i]=='1')
			ans += pow(2,i);
	return ans;
}

int main() {
	ios :: sync_with_stdio(false);
	
	int t ; s(t) ;
	while(t--)
	{
		string ans="" ;
		int a ; int b ;
		s(a) ; s(b);
		
		
		
		rep(0,31,i){
			int n;
			for(n=a ; n<=b ; n++)
			{
				cout<<(n & (1<<i))<<endl;
				if((n & (1<<i)) == 0){
					ans += "0";
					break;
				}
			}
			if(n==b+1)
				ans += "1";
		}
		p(convert(ans));
	}

	return 0;
}

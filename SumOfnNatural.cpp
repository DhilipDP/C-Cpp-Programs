#include<bits/stdc++.h>

#define ll long long
#define p(a) printf("%d\n",a)
#define s(a) scanf("%d",&a)
#define sl(a) scanf("%ld",&a)
#define rep(a,b,c) for(int c=a ; c<=b ; ++c)
#define pii pair<int , int>
#define vi vector<int>
#define vs vector<string>
#define vi_it vector<int> :: iterator
#define vs_it vector<string> :: iterator
#define mp(a,b) make_pair(a,b)


using namespace std;
int main()
{
		int t ; s(t) ;
		while(t--)
		{
			ll int n ; cin>>n ;
			ll int ts = (n * (n+1))/2;
			ll int v = floor(log(n)/log(2));
			
	//		cout<<v<<endl;
			ll int sp = pow(2,v+1) - 1;
			
			cout<<(ts - 2*sp)<<endl;
		}
		return 0;
}

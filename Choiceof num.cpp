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


int bits(int n)
{
	int c=0;
	while(n)
		n = n & (n-1) , c++;
	return c;
}
int main() {
	ios :: sync_with_stdio(false);
	int t ; s(t) ;
	
	while(t--)
	{
		ll int count = 0;
		int n , k , j=n-1; s(n) ; s(k) ;
		vi v(n);
		rep(0,n-1,i)
		{
			int temp ; s(temp);
			v[i] = bits(temp);
	
		} 
		sort(v.begin() , v.end());
		
		while(k--)
			count += v[j--] , p(count);
		printf("%lld\n",count);
	}
	return 0;
}

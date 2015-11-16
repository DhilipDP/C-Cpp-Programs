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

#define ll long long

 int S =  1e7 + 4;

bool prime[S] ;

void sieve()
{
	prime[0] = prime[1] = true ;
	for(ll int i=2 ; i<=1000  ; i++)
	{
	//	cout<<i<<endl;
		if(!prime[i])
		{
			for(ll int j = i*i ; j<=S ; j+=i)
				prime[j] = true ;
		}
	}
}
 

int main()
{
	
	ios :: sync_with_stdio(false);
	
	sieve() ;

	cout<<"done" ;
	int n ; s(n)  ;
	while( n-- )
	{
		int x ; s(x) ;
		
		int i=2,c=2 ;
		while( i <= sqrt(x))
		{
			if(x % i == 0)
			{
				c+=2;
				if(  i * i == x)
					c-- ;
				
			}
			if(c >=  4)
			{
				cout<<"YES"<<endl;
				break;
			
			}
			i++;
		}
		if( i > sqrt(x))
		{
			cout<<"NO"<<endl ;
			
		}
	}	
	
	return 0;
	
}

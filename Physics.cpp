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

map<string , int >  m;
vi in[12]  ;
vi out[12] ;

void clear()
{
	m.clear();
	for(int i=0 ; i<13 ; i++)
	{
		for(int j=0 ; j<13 ; j++)
		{
			in[i].push_back(0);
			out[i].push_back(0);
		}
	}
}
int main() {
	ios :: sync_with_stdio(false);
	
	while(true)
	{
		clear();
	/*in.clear();
		out.clear();
		m.clear();*/
		int n ; s(n) ;
		if(n==0)
			break;
		rep(0,n-1,i)
		{
			string s ; cin>>s;
			m[s] = i;
		}
		rep(1,n-1,i)
		{
			string a,b,c ;
			int val ;
			cin>>a;
			cin>>b;
			cin>>val>>c;
			
			int v1 = m[a] ;
			int v2 = m[c] ;
		
			
			out[v1][v2] = val; 
			in[v2][v1] = val;
			
		}
		
		int large ;
		for(large = 0 ; large < n ; large++)
		{
			int i;
			for(i=0 ; i<n ; i++){
				if(in[large][i] != 0)
					break;
			}
			if(i==n)
			{
				break;
			}
		}
		cout<<large<<endl;
	}
	return 0;
}

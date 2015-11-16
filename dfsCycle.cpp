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

vector<pii> adj[10005] ;
vi dis(10005) ;
bool visited[10005] ;
int n , m;
bool first = false;

void init()
{
	for(int i=0 ; i<10005 ; i++)
		adj[i].clear() ,dis[i] = INT_MAX,visited[i]=false;
}


bool dfs(int v,int cost)
{
	visited[v] = true ;
	if(!first && v==1 && cost > 0)
		return true ;
	bool op = false;
	for(vector< pii> :: iterator it = adj[v].begin() ; it!=adj[v].end() ;  it++)
	{
		
		if(it->first==1 || !visited[it->first])
			if( dfs(it->first,cost + it->second) )
				return true;
	}
	return false;
}

int main() {
	ios :: sync_with_stdio(false);

	int t ; s(t) ;
	while(t--)
	{
		init() ;
		s(n) ; s(m) ; 
		
		while(m--)
		{
			int i,j,c ;
			s(i) ; s(j) ; s(c) ;
			adj[i].push_back(mp(j,c));
		}			
		if(dfs(1,0))
			cout<<"Yes";
		else
			cout<<"No";
		cout<<endl;
	} 


	return 0;
}

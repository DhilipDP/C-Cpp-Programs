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

vi adj[10005] ;
vi dis(10005) ;
bool visited[10005] ;
int n , m;

void init()
{
	for(int i=0 ; i<10005 ; i++)
		adj[i].clear() ,dis[i] = INT_MAX,visited[i]=false;
}


int bfs()
{
	int res= INT_MAX ;
	queue<int> q ;
	q.push(1) ;
	visited[1]	= true ;
	dis[1] = 0;
	while(!q.empty())
	{
		
		int v = q.front() ;
		//cout<<v<<endl;
		if(v==n)
			return dis[v];
		q.pop();
		for(vi_it it = adj[v].begin() ;  it!=adj[v].end() ; it++)
		{
			if(!visited[*it])
			{
				visited[*it] = true ;
				dis[*it] = dis[v] + 1;
				q.push(*it);
			}
		}
	}
	return 0;
}
int main() {
	ios :: sync_with_stdio(false);
	
	int t ;
	s(t) ;
	
	while(t--)
	{
		init() ;
		s(n) ; s(m) ;
		while(m--)
		{
			int x,y ;s(x) ; s(y);
			adj[x].push_back(y);
			adj[y].push_back(x)  ;
		} 
		p(bfs());
	} 
	

	return 0;
}

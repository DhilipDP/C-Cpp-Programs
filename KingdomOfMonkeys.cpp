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

bool visited[100006] ;

void dfs(vi adj[] , vector<ll int> &ban , int v , ll int &cost)
{
//	cout<<v<<endl;
	visited[v] = true ;
	cost += ban[v] ;
	for(vi_it it = adj[v].begin()  ; it!=adj[v].end() ; it++)
	{
		if(visited[*it]==false)
		{
			dfs(adj,ban,*it,cost);
		}
	}	
}
int main() {
	ios :: sync_with_stdio(false);

	int  t ; s(t) ;
	while( t-- ){
	
		ll int ans = 0;
		int  N , M ; s(N) ; s(M) ;

		vi adj[N+1] ;
		vector<ll int>  ban(N+1);
	   	rep( 1 , M , i)
	   		{
	   			int x,y ;
	   			s(x) ; s(y) ;
	   			adj[x].push_back(y) ;
	   			adj[y].push_back(x) ;
	   		}	
	   	rep(1 , N ,i)
	   		sll(ban[i]);
	   	ll int cost = 0 ;
	   	memset(visited,false,sizeof(visited));
	   	
	   	rep(1,N,i){
	   	if(!visited[i]){
	   		cost = 0;
			dfs(adj,ban,i,cost) ;
			p(cost);
			if(cost > ans)
				ans = cost;
		}	
		
		}
		pll(ans) ;
		
	}
	return 0;
}

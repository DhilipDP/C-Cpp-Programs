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


bool visited[1004] ;
vi adj[1004];


void dfs(int v,int &c)
{
	c++;
	visited[v] = true ;
	for(vi_it  it = adj[v].begin() ; it!=adj[v].end() ; it++)
		if(!visited[*it])
			dfs(*it , c );
}
int main() {
	ios :: sync_with_stdio(false);

	int n ; s(n) ;
	int d ;  s(d) ;


	rep(1,d,i)
	{
		int x,y; s(x) ; s(y) ;
		adj[x].push_back(y) ;
		adj[y].push_back(x) ;
	}
	
	int res = INT_MAX;


	rep(1,n,i)
	{
		if(!visited[i]){
			int ans = 0;
		
			dfs(i,ans) ;
			res = min(res,ans) ;
		}
	}	
	p(res) ;
	return 0;
}

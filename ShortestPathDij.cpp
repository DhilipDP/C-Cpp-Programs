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


struct node {
	int i ; int d ;
	node(int x, int y) : i(x) , d(y) {}
	
};

vector< node * > dis ;
vector< pii > adj[10005] ;
bool visited[10005] ;
int n , m;

void init()
{
	for(int i=0 ; i<10005 ; i++)
		adj[i].clear() , dis.push_back ( new node(i , INT_MAX) ) ,visited[i]=false;
}

	struct comp{
	bool operator()(node * &a, node * &b)
	{
		return a->d > b->d ;
	}
};

void dijikstra()
{
	dis[1]->d = 0;
	priority_queue<node* , vector<node*> ,  comp> heap;
	
	for(int i=0 ; i<n ; i++)
		heap.push(dis[i]) ;
		
	while( !heap.empty())
	{
		node * top = heap.top() ;
		heap.pop();
		int v = top->i ;
		visited[v] = true;
		for(vector<pii>  ::iterator   it = adj[v].begin() ;  it!=adj[v].end() ; it++)
		{
			int ver =  it->first , cost = it->second ;
				if(!visited[ver] && dis[v]->d != INT_MAX && dis[ver]->d > dis[v]->d + cost ){
			
			//	node[val].key = node[cur].key + it->dist ;
				dis[ver]->d = dis[v]->d + cost ;
//			
			}
		}
	}
	
	
}

int main() {
	ios :: sync_with_stdio(false);

	int t ; s(t) ;	
	while( t-- )
	{
		s(n) ; s(m) ;
		while(m--)
		{
			int x,y,c ;
			s(x) ; s(y) ; s(c) ;
			adj[x].push_back(mp(y,c)) ;
		}
		dijikstra();
		int q ; s(q) ;
		while (q--)
		{
			int a , k;
			s(a) ; s(k) ; 
			int ans = k-(2*dis[a]->d);
			if(ans <=0 )
				cout<<"0"<<endl;
			else
				p(ans);
		}
	}
	return 0;
}

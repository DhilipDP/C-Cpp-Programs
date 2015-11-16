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

struct node{
	int vertex ;
	vi ed ;
};
struct comp {
    bool operator() (const pii &a, const pii &b) {
        return a.second > b.second;
    }
};

vector<node>  adj[505];
int n ,m,k;
int D[505] ;
bool F[505];

void dij(int _time)
{

priority_queue< pii, vector< pii >, comp > Q;
	
	  int i, u, v, w ,sz;
 	
    // initialize distance vector
    for(i=1; i<=504; i++) D[i] = INT_MAX , F[i]= false;
    D[1] = 0;
    Q.push(pii(1, 0));
 
 //	cout<<Q.size();
    while(!Q.empty()) {
    	
    //	cout<<"hi";
        u = Q.top().first;
        Q.pop();
        if(F[u]) continue;
        sz = adj[u].size();
        cout<<sz<<endl;
        for(i=0; i<sz; i++) {
        	node nn = adj[u][i];
            v = nn.vertex;
            w = nn.ed[_time];
            if(!F[v] && D[u]!= INT_MAX && D[u]+w < D[v]) {
                D[v] = D[u] + w;
                cout<<"D["<<v<<"] = "<<D[u]+w<<endl;
                Q.push(pii(v, D[v]));
            }
        }
        F[u] = 1; // done with u
    }
 
    // result
 //   for(i=1; i<=505; i++) printf("Node %d, min weight = %d\n", i, D[i]);
    return ;

}

int main() {
//	ios :: sync_with_stdio(false);

	int t ; s(t) ;
	p(t);
	while(t--)
	{
		 s(n) ;
		 s(m) ; s(k) ;
		 
		 while(m--)
		 {
		 	int x,y ; s(x) ; s(y) ;
		 	node n1, n2;
		 	n1.vertex = x ; n2.vertex = y;
		 	rep(0,23,i)
			{
				int tp ; s(tp) ;
				n1.ed.push_back(tp);
				n2.ed.push_back(tp);
				adj[x].push_back(n2) ;
				adj[y].push_back(n1) ;
			} 
		 }
		 while(k--)
		 {
		 	int d , tim ;
		 	s(d) ; s(tim) ;
		 	
		 	dij(tim);
		 	p(D[d]);
		 	
		 	//path(1,d,tim) ;
		 }
		 
	}
	return 0;
}

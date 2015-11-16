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

int n ;
vi adj[105] ;
bool visited[105] ;
vector< pii > degrees(105);


bool comp(const pii &a , const pii &b)
{
	return a.second > b.second ;
}

void construct_graph()
{
	
	sort(degrees.begin()+1 , degrees.begin() + n+1, comp) ;
	
	for(int i=1 ; i<=n ; i++)
		cout<<degrees[i].first<<" "<<degrees[i].second<<endl;
	rep(1,n,i)
	{
		
		int deg = degrees[i].second ;	
	//	cout<<i<<" "<<deg<<endl;
			if(deg<=0)
			break;
		int j=i+1;
		while(deg--)
		{
			cout<<"connecting"<<degrees[i].first <<" "<<degrees[j].first<<endl;
 			adj[degrees[i].first].push_back(degrees[j].first);
			adj[degrees[j].first].push_back(degrees[i].first) ;
			degrees[j].second--;
			j++;
		}
		sort(degrees.begin()+i+1,degrees.begin()+n+1,comp);
	}	
}


bool dfs(int v, int parent)
{
	visited[v] = true ;
	for( vi_it it = adj[v].begin() ; it!=adj[v].end() ; it++)
	{
		if(visited[*it]==false){
		
			if( dfs(*it , v) ) return true ;
		}
		else if(*it != parent){
			cout<<*it<<" "<<parent<<endl;
			return true;
		}
	}
	return false;
	
}
int main() {
	ios :: sync_with_stdio(false);
	
	 s(n) ;

	rep(1,n,i){
		int temp ; s(temp) ;
		degrees[i] = mp(i,temp);
	}
	
	construct_graph() ;
	
	if(dfs(1,0))
	{
		cout<<"No"<<endl;
		return 0;
	}
	rep(1,n,i)
		if(!visited[i])
		{
			cout<<"No"<<endl;
			return 0;
		}	
	cout<<"Yes"<<endl;
	
	return 0;
}

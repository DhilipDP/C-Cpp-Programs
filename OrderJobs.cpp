#include<iostream>
#include<utility>
#include<stack>
#include<vector>

using namespace std ;


stack<int> ft ;
struct graph{
	vector<int>  adj ;
};


void topologicalOrder(graph nodes[] , int v ,int n, bool visited[])
{
	
	cout<<v<<endl;
	visited[v] = true ;
	
	for(int i=0 ; i<nodes[v].adj.size() ; i++)
		if(!visited[nodes[v].adj[i]] )
			topologicalOrder(nodes,nodes[v].adj[i],n,visited) ;
	
	// finisshing time
	cout<<"pushing" <<" "<<v<<endl;
	ft.push(v) ;
}

vector<int>  schedule(vector<pair<int,int> >p,int jobs)
{
		int n = p.size() ;	
		graph nodes[jobs+1] ;
		for(int i=0 ; i<n ; i++)
		{
			int v = p[i].first ;
			int u = p[i].second ;
			cout<<u<<" -- "<<v<<endl;
			nodes[u].adj.push_back(v) ;
		}
		
		bool visited[jobs] ;
		memset(visited,false,sizeof(visited)) ;
		
		for(int i=1 ; i<=jobs ; i++)
			if(!visited[i])
				topologicalOrder(nodes,i,jobs,visited) ;
		
		vector<int> v ;
		while( !ft.empty())
		{
			v.push_back(ft.top()) ;
			ft.pop() ;
		}
		return v ;
}

int main()
{
	vector<pair<int ,int>  > p ;
	
	// (pair : depending , depending) 
	
		p.push_back(make_pair(1,2)) ;
		p.push_back( make_pair(2,3) ) ;
		
	vector<int> order = schedule(p,3) ;
	for(int i=0 ; i<order.size() ; i++)
		cout<<order[i]<<" ";
	cout<<endl;
}

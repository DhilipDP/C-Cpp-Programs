#include<iostream>
#include<vector>
#include<algorithm>
#include<limits.h>

using namespace std ;

struct vertex{
	int no;
	int dist;
};


struct heap_node{
	int num ; 
	int key ;
};

bool compare(struct heap_node a,struct heap_node b){
	if(a.key > b.key)
		return true ;
	return false;
}

void prim(vector<vertex> *adj,int n ,int src){
	int i;
	struct heap_node node[n];	
	for(i=0 ; i<n ; i++){
		node[i].num=i+1;
		node[i].key= INT_MAX;
	}
	bool visited[n+1];
	memset(visited,false,sizeof(visited));
	node[src-1].key=0;
	make_heap(node,node+n,compare);
	for(i=0 ; i<n-1 ; i++){
		pop_heap(node,node+n-i,compare);
		int cur = n-i-1;
		int val;
		int u = node[cur].num ;
		visited[u]=true ;
		vector<vertex> :: iterator it ;
		for(it = adj[u].begin() ; it!=adj[u].end() ; it++){
			for(int j=0 ; j<n ; j++){
				if(node[j].num == it->no){
					val = j;
					break;
				}
			}
			if(!visited[it->no] && it->dist < node[val].key ){
			
				node[val].key = it->dist;
			//	cout<<node[val].key<<" : "<<node[cur].key + it->dist<<endl;;
			}
		}
		make_heap(node,node+n-i-1,compare);
	}
	cout<<"The cost is \n" ;
	long int cost = 0 ;
	for(int i= 0 ; i<n ; i++){
		cost += node[i].key ;
	}
	cout<<cost<<endl;
}

int main(){
	int no_of_vertices,edges ;
//	cout<<"\nNumber of vertices: \n";
	cin>>no_of_vertices ;
	vector<struct vertex> *adj = new vector<struct vertex>[no_of_vertices+1];
//	cout<<"Enter number of edges: ";
	cin>>edges;
//	cout<<"Enter weighted edges & length (labelling vertices from 0 to n-1 ):  \n";
	for(int i=0 ; i<edges ; i++){
		int from,to ,dis;
		cin>>from>>to>>dis;
		struct vertex node;
		struct vertex n ;
	n.no = from ;
	n.dist = dis ;
		adj[to].push_back(n);
		node.no = to;
		node.dist = dis;
		adj[from].push_back(node);	
	}
	int src ;
	cout<<"Source:\n";
	cin>>src ;
	for(int i=1 ; i<=no_of_vertices ; i++)
		prim(adj,no_of_vertices,src),cout<<endl;
}

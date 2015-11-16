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

void shortestPath(vector<vertex> *adj,int n ,int src){
	int i;
	struct heap_node node[n];	
	for(i=0 ; i<n ; i++){
		node[i].num=i;
		node[i].key= INT_MAX;
	}
	bool visited[n];
	memset(visited,false,sizeof(visited));
	node[src].key=0;
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
			if(!visited[it->no] && node[cur].key != INT_MAX && node[val].key > node[cur].key +it->dist ){
			
				node[val].key = node[cur].key + it->dist ;
//				cout<<node[val].key<<" : "<<node[cur].key + it->dist<<endl;;
			}
		}
		make_heap(node,node+n-i-1,compare);
	}
	cout<<"The Shortest distance from :"<<src<<" : \n";
	for(int i= 0 ; i<n ; i++){
		if(node[i].num==no_of_vertices-1)
			//cout<<"Node "<<node[i].num<<" : "<<node[i].key<<endl;
			return node[i].key ;
	}
}

int main(){
	int no_of_vertices,edges ;
//	cout<<"\nNumber of vertices: \n";
	cin>>no_of_vertices ;
	vector<struct vertex> *adj = new vector<struct vertex>[no_of_vertices];
//	cout<<"Enter number of edges: ";
	cin>>edges;
//	cout<<"Enter weighted edges & length (labelling vertices from 0 to n-1 ):  \n";
//	for
	for(int i=0 ; i<edges ; i++){
		int from,to ,dis;
		cin>>from>>to>>dis;
		struct vertex node;
		struct vertex n;
		n.no = from ;
		n.dist = dis ;
		node.no = to;
		node.dist = dis;
		adj[from].push_back(node);		
		adj[to].push_back(n);
	}
/*	int src ;
	cout<<"Source:\n";
	cin>>src ; */
	int dis = shortestPath(adj,no_of_vertices,0);
	count
}

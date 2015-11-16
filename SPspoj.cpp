#include<iostream>
#include<vector>
#include<algorithm>
#include<limits.h>
#include<stdio.h>
#define CHAR_TO_INDEX(c) (int)c - (int)'a'+1

using namespace std ;

struct vertex{
	int no;
	int dist;
};


struct heap_node{
	int num ; 
	int key ;
};

int find(char a[]){
	string s(a);
	int sum =0 ;
	for(int i=0 ; a[i]  ; i++){
		sum += CHAR_TO_INDEX(a[i]);
	}
	return sum;
}

bool compare(struct heap_node a,struct heap_node b){
	if(a.key > b.key)
		return true ;
	return false;
}

void shortestPath(vector<vertex> *adj,int n ,int src,int des){
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
//		cout<<u<<" : "<<node[cur].key<<endl;
	 if(u==des)
		{
			printf("%d\n",node[cur].key);
			return ;
		} 
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
	//			cout<<node[val].key<<" : "<<node[cur].key + it->dist<<endl;;
			}
		}
		make_heap(node,node+n-i-1,compare);
	}
//	cout<<"The Shortest distance from :"<<src<<" : \n";
	for(int i= 0 ; i<n ; i++){
		if(node[i].num==des)
			cout<<node[i].key<<endl;
	}
}


int main(){
	int t ;
	scanf("%d",&t);
	while(t--){
			int arr[300];
			int no_of_vertices,edges ;
			scanf("%d",&no_of_vertices);
			vector<struct vertex> *adj = new vector<struct vertex>[no_of_vertices+1];
			int i;
			int from,to,dis ;
			for(i=1 ; i<=no_of_vertices ; i++){
				from = i ;
				char a[20] ;
				scanf("%s",a);
				int val = find(a);
				arr[val]=i;
				int nei ;
				scanf("%d",&nei);
				while(nei--){
					scanf("%d%d",&to,&dis);
					struct vertex node;
					struct vertex n;
					n.no = from ;
					n.dist = dis ;
					node.no = to;
					node.dist = dis;
				//	cout<<"pushing";
					adj[from].push_back(node);	
				//	cout<<"pushing";	
				//	adj[to].push_back(n);
				}	
			}
	
//			cout<<"End of for: "<<endl;
			int paths ;
			scanf("%d",&paths);
			while(paths--){
				char a1[20],a2[20];
				scanf("%s%s",a1,a2);
				int src = arr[find(a1)];
				int des = arr[find(a2)];
//				cout<<src<<" "<<des<<endl;
				shortestPath(adj,no_of_vertices,src,des);
			}
	}
}


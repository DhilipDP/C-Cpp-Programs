#include<iostream>
#include<vector>
#include<algorithm>
#include<limits.h>
#include<stdio.h>

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
	for(i=1 ; i<=n ; i++){
		node[i].num=i;
		node[i].key= INT_MAX;
	}
	bool visited[n+1];
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
				cout<<node[val].key<<" : "<<node[cur].key + it->dist<<endl;;
			}
		}
		make_heap(node,node+n-i-1,compare);
	}
	cout<<"The Shortest distance from :"<<src<<" : \n";
	for(int i= 0 ; i<n ; i++){
		if(node[i].num==7 || node[i].num==37 || node[i].num==59|| node[i].num==82||node[i].num==99||node[i].num==115||node[i].num==133||node[i].num==165||node[i].num==188||node[i].num==197)
		cout<<"Node "<<node[i].num<<" : "<<node[i].key<<endl;
	}
}

int main(){
	int no_of_vertices,edges ;
	cout<<"\nNumber of vertices: \n";
	cin>>no_of_vertices ;
	vector<struct vertex> *adj = new vector<struct vertex>[no_of_vertices+1];
//	cout<<"hi";
//	cout<<"Enter number of edges: ";
//	cin>>edges;

//	cout<<"Enter weighted edges & length (labelling vertices from 0 to n-1 ):  \n";
	FILE *fp;
	fp = fopen("file.txt","r");
	char a[100];
	string f;
	int from ,l=0;
	while(fscanf(fp,"%s",a)!=EOF){
	//	cout<<"hi";
//	l++;
cout<<"hi";
		string s(a);
		//cout<<s<<endl;
		string t="",d="" ;
		bool second = false;
		for(int i = 0 ; s[i] ; i++){
			if(s[i]==',')
				second = true;
		}	
		if(!second){
			f = s;
			from = atoi(f.c_str());
		//	cout<<from<<endl;
		}
		else{
			bool  flag = false ;
			int i;
			for(i=0 ; s[i] ; i++){
				if(flag)
					d+=s[i];
				else if(s[i]==',')
					flag = true ;
				else
					t += s[i];
			}
		}
		int to,dis;
		//from = atoi(f.c_str());
		to = atoi(t.c_str());
		dis = atoi(d.c_str());
		//cout<<from<<" "<<to<<" "<<dis;
		if(f!="" && t!="" && d!=""){
			cout<<"Pushing edge: "<<dis<<" bw "<<from<<" "<<to<<endl;
			struct vertex node;
			struct vertex n;
			n.no = from ;
			n.dist = dis ;
			node.no = to;
			node.dist = dis;
			adj[from].push_back(node);		
			adj[to].push_back(n);
	}
	cout<<"\ndon\n";
	}
	int src ;
	cout<<"Source:\n";
	cin>>src ;
	shortestPath(adj,no_of_vertices,src);
}

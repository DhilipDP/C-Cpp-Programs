#include<iostream>
#include<stack>
#include<vector>
using namespace std;

//Topological Sorting of a directed Acyclic Graph

stack<int> st;


void DFS(vector<int> *adj,int s,bool visited[]){
	visited[s]=true ;
	
	vector<int> :: iterator it ;
	for(it = adj[s].begin() ; it!=adj[s].end() ; it++){
		if(!visited[*it])
			DFS(adj,*it,visited);
	}	
	
	st.push(s);
}

void topologicalOrder(vector<int> *adj,int n){
		bool visited[n];
		memset(visited,false,sizeof(visited));	
		int i ;
		for(i=0 ; i<n ; i++){
			if(!visited[i])
				DFS(adj,i,visited);
		}
}

void print(){
	while(!st.empty()){
		cout<<st.top()<<" ";
		st.pop();
	}
}
int main(){
	int no_of_vertices,edges ;
	cout<<"\nNumber of vertices: \n";
	cin>>no_of_vertices ;
	vector<int> *adj = new vector<int>[no_of_vertices];
	cout<<"Enter number of edges: ";
	cin>>edges;
	cout<<"Enter directed edges one by one labelling vertices from 0 to n-1: \n";
	for(int i=0 ; i<edges ; i++){
		int from,to ;
		cin>>from>>to;
		adj[from].push_back(to);		
	}	
	vector<int> :: iterator it ;
	for(int i=0 ; i<no_of_vertices ; i++){
		for(it = adj[i].begin() ; it!=adj[i].end() ; it++)
			cout<<i<<" "<<*it<<endl;
	}
	topologicalOrder(adj,no_of_vertices);
	cout<<"The topological ordering is:\n";
	print();
}

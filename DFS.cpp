#include<iostream>
#include<vector>
using namespace std;


void DFS_util(vector<int> *adj,int st,bool visited[]){

	visited[st]=true;
	cout<<st<<endl;
	for(vector<int> :: iterator it = adj[st].begin() ; it != adj[st].end() ; it++){
		if(!visited[*it])
			DFS_util(adj,*it,visited);
	}	
}

void DFS(vector<int> *adj,int num,int st){
	bool visited[num];
	memset(visited,false,sizeof(visited));
	DFS_util(adj,st,visited);	
}
int main(){
	int num;
	cout<<"Enter number of vertices: ";
	cin>>num;
	vector<int> *adj = new vector<int>[num];
	int i,edges;
	cout<<"Enter number of edges: ";
	cin>>edges;
	cout<<endl<<"<---Note : Name your nodes from 0 to n-1 and enter all egdes one by one: --->\n";
	for(i=0 ; i<edges ; i++){
		int j,k;
		cin>>j>>k;
		//cout<<"Enter the adjacent vertices of node : "<<i+1<<": ";
		adj[j].push_back(k);
	}
	cout<<"\nStarting vertex? : ";
	cin>>i;
	DFS(adj,num,i);
} 

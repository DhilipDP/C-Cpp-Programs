#include<iostream>
#include<vector>
using namespace std;


bool DFS_util(vector<int> *adj,int st,int ed,bool visited[]){

	int f=0;
	visited[st]=true;
//	cout<<st<<endl;
	if(st==ed)
	{
		f=1;
	}
	for(vector<int> :: iterator it = adj[st].begin() ; it != adj[st].end() ; it++){
		if(!visited[*it]){
			f =DFS_util(adj,*it,ed,visited);
		}
	}	
	return f ;
}

void DFS(vector<int> *adj,int num,int st,int ed){
	bool visited[num];
	memset(visited,false,sizeof(visited));
	cout<<DFS_util(adj,st,ed,visited);	
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
	int j;
	cout<<"\nStart vertex? : ";
		cin>>i;
	cout<<"\nEnd vertex? \n";
	cin>>j;
	//cin>>j;
	DFS(adj,num,i,j);
} 

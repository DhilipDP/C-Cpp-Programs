#include<iostream>
#include<limits.h>
#include<queue>
#define n 6
using namespace std;



int graph[n][n];
//ShortestPath using BFS


void print(int dist[]){
	for(int i=0 ; i<n ; i++){
		cout<<i<<" : "<<dist[i]<<endl;
	}
}
void BFS(int dist[],int s){
	bool visited[n];
	memset(visited,false,sizeof(visited));
	queue<int> q;
	q.push(s);
			visited[s]=true ;
	dist[s] = 0;
	while(!q.empty()){
		int front  = q.front();
		cout<<front<<endl;
		q.pop();

		int i,j;
		for(i=0 ; i<n ; i++){
			if(graph[front][i] && !visited[i]){
				visited[i] = true ;
				q.push(i);
				dist[i] = dist[front]+1;
				cout<<"dist["<<i<<"] "<<" : "<<dist[i]<<" parent: "<<front<<endl;
			}
			
		}
	}
	cout<<"The Shortest distance from :"<<s<<" : \n";
	print(dist);
	
}
void shortestPath(){
	int dist[n];
	int s ;
	cout<<"\nSource :\n";
	cin>>s;
	memset(dist,INT_MAX,sizeof(dist));
	BFS(dist,s);
}

int main(){

	cout<<"\nAdjacency matrix:\n";
	int i,j;
	for(i=0 ; i<n ; i++)
		for(j=0  ; j<n ; j++)
			cin>>graph[i][j];
	shortestPath();
}


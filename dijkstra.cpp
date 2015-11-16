#include <stdio.h>
#include <limits.h>
#include<iostream>
#include<vector>

using namespace std ;
 

struct vertex{
	int no;
	int dist;
};

int minDistance(int dist[], bool sptSet[],int n)
{
   int min = INT_MAX, min_index;
 
   for (int v = 0; v < n; v++)
     if (sptSet[v] == false && dist[v] <= min)
         min = dist[v], min_index = v;
 
   return min_index;
}
 
// A utility function to print the constructed distance array
int printSolution(int dist[], int n)
{
   printf("Vertex   Distance from Source\n");
   for (int i = 0; i < n; i++)
      printf("%d \t\t %d\n", i, dist[i]);
}
 
// Funtion that implements Dijkstra's single source shortest path algorithm
// for a graph represented using adjacency matrix representation
void dijkstra(vector<vertex> *adj,int n, int src)
{
     int dist[n];    
     bool sptSet[n];   
   for (int i = 0; i < n; i++)
        dist[i] = INT_MAX, sptSet[i] = false;
     dist[src] = 0;

     for (int count = 0; count < n-1; count++)
     {
       int u = minDistance(dist, sptSet,n);
       sptSet[u] = true;
       
       vector<vertex> :: iterator it ;
       for (it = adj[u].begin() ; it!=adj[u].end() ; it++) {
         // Update dist[v] only if is not in sptSet, there is an edge from 
         // u to v, and total weight of path from src to  v through u is 
         // smaller than current value of dist[v]
         if (!sptSet[it->no] && dist[u] != INT_MAX && dist[u]+it->dist < dist[it->no])
            dist[it->no] = it->dist + dist[u];
     }
 	}
 
     // print the constructed distance array
     printSolution(dist, n);
}



int main(){
	int no_of_vertices,edges ;
	cout<<"\nNumber of vertices: \n";
	cin>>no_of_vertices ;
	vector<struct vertex> *adj = new vector<struct vertex>[no_of_vertices];
	cout<<"Enter number of edges: ";
	cin>>edges;
	cout<<"Enter weighted edges & length (labelling vertices from 0 to n-1 ):  \n";
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
	int src ;
	cout<<"Source:\n";
	cin>>src ;
	dijkstra(adj,no_of_vertices,src);
}

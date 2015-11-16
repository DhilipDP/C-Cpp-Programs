
#include <stdio.h>
#include <limits.h>
#include<iostream>
#define V 9
using namespace std;
 

int minDistance(int dist[], bool sptSet[])
{

   int min = INT_MAX, min_index;
 
   for (int v = 0; v < V; v++)
     if (sptSet[v] == false && dist[v] <= min)
         min = dist[v], min_index = v;
 
   return min_index;
}


void printPath(int des,int *prev,int src,string &path){
	//static string path="";
	if(prev[des]==-1){
	
		return ;
	}
	printPath(prev[des],prev,src,path);

	path += (prev[des]+'0');
	
	
}

int printSolution(int dist[], int n)
{
   printf("Vertex   Distance from Source    \n");
   for (int i = 0; i < V; i++)
      printf("%d \t %d\n", i, dist[i]);//cout<<path[i]<<endl;
}
 
void dijkstra(int graph[V][V], int src)
{
		int prev[V];
     int dist[V];    
 
     bool sptSet[V]; 
   
     for (int i = 0; i < V; i++)
        dist[i] = INT_MAX, sptSet[i] = false,prev[i] = -1;

     dist[src] = 0;
     
 
     for (int count = 0; count < V-1; count++)
     {
       int u = minDistance(dist, sptSet);
 
       sptSet[u] = true;
 
     //	cout<<"min: "<<u<<endl;
       for (int v = 0; v < V; v++)
		{
         if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX 
                                       && dist[u]+graph[u][v] < dist[v]){
    //		cout<<"Appending "<<u<<" to "<<v<<endl;
            dist[v] = dist[u] + graph[u][v];
            prev[v] = u;
       
        	
		}
	}	
     }
 //    for(int i=1 ; i<V ; i++)
//		path[i]+= (i+48);

     printSolution(dist, V);
     string path ="" ; 
	  printPath(4,prev,src,path);
     cout<<path<<endl;
}
 
int main()
{
   int graph[V][V] = {{0,4,0,0,0,0,0,8,0},
   					  {4,0,8,0,0,0,0,11,0},
   					  {0,8,0,7,0,4,0,0,2},
   					  {0,0,7,0,9,14,0,0,0},
   					  {0,0,0,9,0,10,0,0,0},
   					  {0,0,4,0,10,0,2,0,0},
   					  {0,0,0,14,0,2,0,1,6},
   					  {8,11,0,0,0,0,1,0,7},
   					 {0,0,2,0,0,0,6,7,0},
   					
                     };
 
 
 	//int graph[V][V] ={{0,1,4},{0,0,2},{0,0,0}};
    dijkstra(graph, 0);
 
    return 0;
}

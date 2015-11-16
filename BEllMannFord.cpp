#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#define V 4
// A utility function used to print the solution
void printArr(int dist[], int n)
{
    printf("Vertex   Distance from Source\n");
    for (int i = 0; i < n; ++i)
        printf("%d \t\t %d\n", i, dist[i]);
}
void BellmanFord(int  graph[V][V], int src)
{
    int dist[V];
 

    for (int i = 0; i < V; i++)
        dist[i]   = INT_MAX;
    dist[src] = 0;
 
    
	for(int i=0 ; i<V ; i++){
		for(int j=0 ; j<9 ; j++){
			if(graph[i][j]!=0){
				int u = i ;
				int v = j;
				int weight = graph[i][j];
				if(dist[u] + weight < dist[v])
					dist[v] = dist[u] +weight ; 
			}
		}
	}
	
	 for (int i = 0; i < V; i++)
    {
    	for(int j=0 ; j<V ; j++){
    		if(graph[i][j]!=0){
    			int u = i;
    			int v  = j ;
    			int weight = graph[i][j];
    			if(dist[u] + weight < dist[v])
    				printf("Graph contains negative weight cycle\n");
    		}
    	}
    }
 
    printArr(dist, V);
 
    return;
}
 
// Driver program to test above functions
int main()
{
	int graph[V][V] = {{0,2,7,0},
					   {0,0,3,5},
					   {0,0,0,2},
					   {0,0,0,0}};
					
	/*int graph[V][V] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
                      {4, 0, 8, 0, 0, 0, 0, 11, 0},
                      {0, 8, 0, 7, 0, 4, 0, 0, 2},
                      {0, 0, 7, 0, 9, 14, 0, 0, 0},
                      {0, 0, 0, 9, 0, 10, 0, 0, 0},
                      {0, 0, 4, 0, 10, 0, 2, 0, 0},
                      {0, 0, 0, 14, 0, 2, 0, 1, 6},
                      {8, 11, 0, 0, 0, 0, 1, 0, 7},
                      {0, 0, 2, 0, 0, 0, 6, 7, 0}
                     };
 */
    /* Let us create the graph given in above example */
/*    int V = 5;  // Number of vertices in graph
    int E = 8;  // Number of edges in graph
    struct Graph* graph = createGraph(V, E);
    
    
 
    // add edge 0-1 (or A-B in above figure)
    graph->edge[0].src = 0;
    graph->edge[0].dest = 1;
    graph->edge[0].weight = -1;
 
    // add edge 0-2 (or A-C in above figure)
    graph->edge[1].src = 0;
    graph->edge[1].dest = 2;
    graph->edge[1].weight = 4;
 
    // add edge 1-2 (or B-C in above figure)
    graph->edge[2].src = 1;
    graph->edge[2].dest = 2;
    graph->edge[2].weight = 3;
 
    // add edge 1-3 (or B-D in above figure)
    graph->edge[3].src = 1;
    graph->edge[3].dest = 3;
    graph->edge[3].weight = 2;
 
    // add edge 1-4 (or A-E in above figure)
    graph->edge[4].src = 1;
    graph->edge[4].dest = 4;
    graph->edge[4].weight = 2;
 
    // add edge 3-2 (or D-C in above figure)
    graph->edge[5].src = 3;
    graph->edge[5].dest = 2;
    graph->edge[5].weight = 5;
 
    // add edge 3-1 (or D-B in above figure)
    graph->edge[6].src = 3;
    graph->edge[6].dest = 1;
    graph->edge[6].weight = 1;
 
    // add edge 4-3 (or E-D in above figure)
    graph->edge[7].src = 4;
    graph->edge[7].dest = 3;
    graph->edge[7].weight = -3; */
 
    BellmanFord(graph, 0);
 
    return 0;
}

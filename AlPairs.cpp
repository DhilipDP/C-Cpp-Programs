// A C Program to demonstrate adjacency list representation of graphs
 
#include<iostream>
#include<vector>
#include<stdio.h>
#include<stack>
#include<vector>
#include<queue>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<limits.h>
#include<map>
#include<algorithm>


#define ll long long
#define p(a) printf("%d\n",a)
#define s(a) scanf("%d",&a)
#define sll(a) scanf("%lld",&a)
#define sl(a) scanf("%ld",&a)
#define FOR(a,b) for(int i=a ; i<=b ; ++i)

using namespace std ;

// A structure to represent an adjacency list node
struct AdjListNode
{
    int dep;
    int dest ;
    int val;
    struct AdjListNode* next;
};
 
// A structure to represent an adjacency liat
struct AdjList
{
	int dep;
    struct AdjListNode *head;  // pointer to head node of list
};
 
// A structure to represent a graph. A graph is an array of adjacency lists.
// Size of array will be V (number of vertices in graph)
struct Graph
{
    int V;
    
	struct AdjList* array;
};
 
// A utility function to create a new adjacency list node
struct AdjListNode* newAdjListNode(int dest,int v)
{
    struct AdjListNode* newNode =
            (struct AdjListNode*) malloc(sizeof(struct AdjListNode));
    if(newNode){
    	cout<<"hi";
    newNode->dest = dest;
    newNode->val = v;
    newNode->next = NULL;
    }
    return newNode;
}
 
// A utility function that creates a graph of V vertices
struct Graph* createGraph(int V)
{
    struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));
    graph->V = V;
 
    // Create an array of adjacency lists.  Size of array will be V
    graph->array = (struct AdjList*) malloc(V * sizeof(struct AdjList));
 
     // Initialize each adjacency list as empty by making head as NULL
    int i;
    for (i = 0; i < V; ++i)
        graph->array[i].dep=0,graph->array[i].head = NULL;
 
    return graph;
}
 
// Adds an edge to an undirected graph
void addEdge(struct Graph* graph, int src, int dest,int v)
{
    // Add an edge from src to dest.  A new node is added to the adjacency
    // list of src.  The node is added at the begining
    struct AdjListNode* newNode = newAdjListNode(dest,v);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;
 	graph->array[src].dep+=v;
 	graph->array[dest].dep+=v;
 	
    // Since graph is undirected, add an edge from dest to src also
    newNode = newAdjListNode(src,v);
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
	
 	
}


void printGraph(struct Graph* graph)
{
    int v;
    for (v = 1; v <= graph->V; ++v)
    {
        struct AdjListNode* pCrawl = graph->array[v].head;
        printf("\n Adjacency list of vertex %d\n head with %d ", v,graph->array[v].dep);
        while (pCrawl)
        {
            printf("-> %d %d", pCrawl->dest,pCrawl->val);
            pCrawl = pCrawl->next;
        }
        printf("\n");
    }
}

int main() {
	int  t ;
	s(t);
	while(t--){
		pair<int ,int> pr;
		map<pair<int,int> ,int> m;
		int n;
		s(n);
		struct Graph * graph = createGraph(n);
		int k;
		s(k);
		FOR(1,n-1)
		{
			int x,y,a,b;
			s(x);
			s(y);
			s(a);
			s(b);
			addEdge(graph,x,y,a);
			pr = make_pair(x,y);
			m[pr] = b ;
		}
		printGraph(graph);
	}
}

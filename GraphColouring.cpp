#include<iostream>
#define V 4
using namespace std ;

bool safe(bool graph[V][V] ,int c, int *color ,int v)
{
	for(int i=0 ; i<V ; i++)
		if(graph[v][i] && color[i]== c)
			return false;
	return true;
}

bool graphColour(bool graph[V][V] , int v , int c[],int m)
{
	if( v == V)
		return true ;
	for(int i=0  ;i<m ; i++)
	{
		if(safe(graph,i,c,v)){
			
			c[v] = i;
			if(graphColour(graph,v+1,c,m))
				return true ;
			c[v] = -1 ;
		}
	}
	return false ;
}


bool graphColouring(bool graph[V][V] ,int m)
{
	int colour[m] ;
	memset(colour,-1,sizeof(colour) ) ;
	graphColour(graph,0,colour,m) ;
		
}
int main()

{
	/*create graph
	 (3)---(2)
       |   / |
       |  /  |
       | /   |
      (0)---(1)
    */
    bool graph[V][V] = {{0, 1, 1, 1},
        {1, 0, 1, 0},
        {1, 1, 0, 1},
        {1, 0, 1, 0},
    };
    
    int m = 4;
    cout<<graphColouring(graph,m) ;
}

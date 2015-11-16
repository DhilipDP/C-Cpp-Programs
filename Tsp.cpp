#include<iostream>
#define V 4
#include<limits.h>
using namespace std ;


int  minCostTsp(int graph[V][V])
{
	int S=V+1 ;
	int C[S][V] ;
	for(int i=0 ;i<=S ; i++)
		for(int j=0 ; j<V  ; j++)
			C[i][j] = INT_MAX;
	for(int i=1 ; i<V ; i++)
		C[2][i] = graph[0][i] ;

	for(int s=3 ; s<=S ; s++)
	{
		cout<<"s: "<<s<<endl;
		for(int i=1 ; i<V ; i++){
		cout<<"i : "<<i<<endl;
		for(int j=1; j<V ; j++)
		{
			
			if(j == i)
				continue ;
			cout<<"j :" <<j<<endl;
			C[s][i] = min ((C[s-i][j] == INT_MAX ? 0 : C[s-i][j]) + graph[j][i] , C[s][i] ) ;
			cout<<s<<" "<<i<<" "<<C[s][i]<<endl;
		}
		}
	}
	
	for(int i=0 ;i<=S ; i++){
	
		for(int j=0 ; j<V  ; j++)
			cout<<C[i][j]<<" ";
		cout<<endl;
	}
		return C[S][0] ;
}

int main()
{
	int graph[V][V] = {{0,10,15,20} ,
					 {10,0,35,25} , 
					 {15,35,0,30} , 
					 {20,25,30,0} };
					 
	cout<<minCostTsp(graph) ;
}


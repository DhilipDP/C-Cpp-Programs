#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<limits.h>


using namespace std;

struct cities{
	string name;
	int no;
};

//int n;
int mini(int dist[],bool splset[],int n){
	int min=INT_MAX;
	int min_index;
	for(int i=0 ; i<n ; i++){
		if(splset[i]==false && dist[i] <= min){
				min = dist[i] ;
				min_index = i;
		}
		
	}
	return min_index;
}

int main(){
	char arr[10000][10000];
	int tests;
	scanf("%d",&tests);
	while(tests--){
		 int i,j;
		int n;
		scanf("%d",&n);
		 int  graph[n][n];
		for(i=0 ; i<n ; i++)
			for(j=0 ; j<n ; j++)
				graph[i][j]=0 + '0';
	//	memset(graph,0,sizeof(graph));
/*		for(i=0 ; i<n ; i++){
			for(int j=0 ; j<n ; j++)
				printf("%d ",graph[i][j]);
			printf("\n");
		}*/
		printf("hello");
		cities arr[n];
		printf("hi");
		for(i=0 ; i<n ; i++){
			cin>>arr[i].name;
			arr[i].no = i;
			int neighbours;
			scanf("%d",&neighbours);
			while(neighbours--){
				int nr,cost;
				scanf("%d%d",&nr,&cost);
				graph[i][nr-1]=cost;
			}
		}
			/*	for(i=0 ; i<n ; i++){
			for(int j=0 ; j<n ; j++)
				printf("%d ",graph[i][j]);
			printf("\n");
		}*/
		int r;
					scanf("%d",&r);
			while(r--){
				string str1,str2;
				cin>>str1>>str2;
			 	int source,destination;
			 	for(int j=0 ; j<n ; j++){
			 		if(arr[j].name == str1){
			 			source = arr[j].no;
			 			break;
			 			}
			 	}
			 	for(int j=0 ; j<n ; j++){
			 		if(arr[j].name == str2){
			 			destination = arr[j].no;
			 			break;
			 			}
			 	}
			 //	cout<<source<<destination;
			 		bool sptset[n];
					int dist[n];
					int k;
					for(k=0 ; k<n ; k++){
						dist[k]=INT_MAX;
						sptset[k]=false;
					}
					dist[source]=0;
					for(int j=0 ; j<n-1 ; j++){
							int u = mini(dist,sptset,n);
							sptset[u]=true;
						for(int v=0 ; v<n ; v++){
									if(!sptset[v] && graph[u][v] &&  dist[u]!=INT_MAX && (dist[u] + graph[u][v] < dist[v]))
									dist[v] = dist[u] + graph[u][v]; 
						}
					}
					printf("%d\n",dist[destination]);
				
			}
		}
		
	}


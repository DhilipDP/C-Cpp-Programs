#include<limits.h>
#include<iostream>
#define V 5
using namespace std ;

int visited[V][V] ;
int count  ;


// for all directions : 
//int x[] = {-1,-1,-1,0,0,1,1,1} ;
//int y[] = {-1,0,1,-1,1,-1,0,1} ;
//int N = 8

// for down and right
int x[] ={1,0} ;
int y[]= {0, 1} ;
int N= 2;


bool isValid(int mat[V][V] ,int i,int j)
{

	if(i>=0 && i<V && j>=0 && j<V && visited[i][j]==0 && mat[i][j]==1)
		return true ;
	return false;
}

void dfs(int mat[V][V] , int i,int j )
{

	visited[i][j] = 1;
	count++;
	for(int k=0 ; k<N ; k++){
		if(isValid(mat,i+x[k],j+y[k]))
				dfs(mat,i+x[k],j+y[k]);
	}
}

int maxDistance(int mat[V][V])
{
		int maxi = INT_MIN ;
	
		memset(visited,0,sizeof(visited)) ;
		
		for(int i=0 ; i<V ; i++){
			for(int j = 0 ;j<V ; j++)
			{
				if(!visited[i][j] &&  mat[i][j] == 1){
					count = 0;
					dfs(mat,i,j) ;
					maxi = max(maxi,count) ;
				} 
			}
		}
		return maxi ;
}


int maxDp(int mat[V][V])
{
	int dp[V][V] ;
	dp[0][0] = (mat[0][0]==1) ;
	for(int i=1 ; i<V ; i++)
		dp[0][i] =  mat[0][i]==1 ?  dp[0][i-1] + 1 : 0;
	for(int i=1 ; i<V ; i++)
		dp[i][0] =  mat[i][0]==1 ? dp[i-1][0] + 1 : 0;
	for(int i=1 ; i<V ; i++)
	{
		for(int j=1 ; j<V ; j++)
		{
			if(mat[i][j]==0){
				dp[i][j] = 0;
				continue ;
			}
			dp[i][j] = max(dp[i][j-1] , dp[i-1][j] ) + 1;
		}
	}
	
	int res = 0;
	for(int i=0 ; i<V ; i++)

		for(int j=0 ; j<V ; j++)
			res = max(res, dp[i][j]) ;

	return res ;		
	
} 
int main()
{
	
	 int mat[V][V]= {  {1, 1, 0, 0, 0},
        {0, 1, 1, 0, 0},
        {0, 0, 1, 0, 1},
        {1, 0, 0, 0, 1},
        {0, 1, 0, 1, 1}
    };
    cout<<maxDistance(mat) ;
    cout<<endl<<maxDp(mat) ;

}

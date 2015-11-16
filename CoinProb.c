#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int findWays(int arr[] , int n , int cost)
{
	if(cost==0)
		return 1;
	if(n == 0)
		return 0;
	if(arr[n-1] > cost)
		return findWays(arr,n-1,cost); 
	return findWays(arr,n-1,cost) + findWays(arr,n-1,cost-arr[n-1])  ;
}

int findWaysDp(int arr[] , int n,int cost)
{
	int **dp = (int **)malloc((cost+1) * sizeof(int *));
	int i,j ; 
	for(i= 0 ; i<=cost ; i++){
		dp[i] = (int *)malloc((n+1) * sizeof(int)) ;
		dp[i][0] = 0;
	}
	for(i=0 ; i<=n ; i++)
		dp[0][i] =  1;
	for(i=1 ; i<=cost ; i++ )
	{
		for(j=1 ; j<=n ; j++)
		{
			if(i - arr[j-1] < 0)
				dp[i][j] = dp[i][j-1] ;
			else
			
				dp[i][j] = dp[i][j-1] + dp[i-arr[j-1]][j-1] ;
		}
	}
	return dp[cost][n] ;
}

int main()
{
	int i,n , arr[10000] , cost ;
	scanf("%d",&n) ;
	for(i=0 ; i<n ; i++)
		scanf("%d",&arr[i]) ;
	scanf("%d",&cost) ;
	printf("%d\n",findWaysDp(arr,n,cost)) ;
}


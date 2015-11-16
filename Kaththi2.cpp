#include<stdio.h>
#include <iostream>
#include<limits.h>

using namespace std ; 
int min(int x, int y);
char cost[1000][1000];
int R,C;
int minCost(int m, int n)
{
     int i, j,a,b;
 	 int tc[R][C];  
 
     tc[0][0] = 0;
 
     /* Initialize first column of total cost(tc) array */
     for (i = 1; i <= m; i++)
        tc[i][0] = tc[i-1][0] + (cost[i][0] == cost[i-1][0]);
 
     /* Initialize first row of tc array */
     for (j = 1; j <= n; j++)
        tc[0][j] = tc[0][j-1] + (cost[0][j] == cost[0][j-1]);
 
     /* Construct rest of the tc array */
     for (i = 1; i <= m; i++)
        for (j = 1; j <= n; j++)
        	a = tc[i-1][j]+(cost[i][j] == cost[i-1][j]);
        	b = tc[i][j-1]+(cost[i][j] == cost[i][j-1]);
            tc[i][j] = min(a,b);
 
     return tc[m][n];
}
 
/* A utility function that returns minimum of 3 integers */
int min(int x, int y)
{
   if (x < y)
      return x;
   else
      return y;
}
 
/* Driver program to test above functions */
int main()
{
   int t,i,j,r,c;
   cin>>t;
   while(t--)
   {
   		cin>>r>>c;
   		for(i=0;i<r;i++)
   		{
   			for(j=0;j<c;j++)
   			{
   				cin>>cost[i][j];
   			}
   		}
   		printf("%d ", minCost(r,c));		
   	}
 
   return 0;
}

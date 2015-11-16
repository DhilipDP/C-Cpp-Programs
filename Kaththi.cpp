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
#include<utility>


#define ll long long
#define p(a) printf("%d\n",a)
#define s(a) scanf("%d",&a)
#define sll(a) scanf("%lld",&a)
#define sl(a) scanf("%ld",&a)
#define FOR(a,b,it) for( it=a ; it<=b ; ++it)
#define pi pair<int,int> 

using namespace std ;

int dp[1000][1000] ;
int mem[1000][1000] ;

int main() {
	int t ;
	s(t);
	while(t--){
		int r,c ;
		s(r);
		s(c);
		char arr[r][c] ;
		int i,j;
		FOR(0,r-1,i)
			cin>>arr[i] ;
		memset(dp,0,sizeof(dp));
		dp[0][0] = 0;
		FOR(1,c-1,i){
			dp[0][i] = dp[0][i-1] ;
			if(arr[0][i-1] != arr[0][i])	
				dp[0][i] ++;
		}
		FOR(1,r-1,i){
			dp[i][0] = dp[i-1][0] ;
			if(arr[i-1][0] != arr[i][0])	
				dp[i][0] ++;
		}
		FOR(1,r-1,i)
		{
			FOR(1,c-1,j){
				//left
		
				int min1 = INT_MAX,min2 = INT_MAX;
				if(arr[i][j-1] == arr[i][j] )
					min1  = dp[i][j-1];
				else
					min1 = dp[i][j-1] + 1;
				
			
			
				if(arr[i-1][j]==arr[i][j])
					min2 = dp[i-1][j];
				else
					min2 = dp[i-1][j] + 1;
				dp[i][j] = min(min1,min2);
				
			}
		}
		mem[r-1][c-1] = 0;
		for( i=c-2  ; i>=0 ; i--){
			mem[r-1][i] = mem[r-1][i+1] ;
			if(arr[r-1][i+1] != arr[r-1][i])	
				mem[r-1][i] ++;
		}
		for(i=r-2 ; i>=0 ; i--){
			mem[i][c-1] = mem[i+1][c-1] ;
			if(arr[i+1][c-1] != arr[i][c-1])	
				mem[i][c-1] ++;
		}
		for(i=r-2 ; i>=0 ; i--)
		{
			for(j=c-2 ; j>=0 ; j--){
			
				int min1 = INT_MAX,min2 = INT_MAX;
				if(arr[i][j+1] == arr[i][j] )
					min1  = mem[i][j+1];
				else
					min1 = mem[i][j+1] + 1;
				
			
			
				if(arr[i+1][j]==arr[i][j])
					min2 = mem[i+1][j];
				else
					min2 = mem[i+1][j] + 1;
				dp[i][j] = min(min1,min2);
				
			}
		}
		
	
		FOR(0,r-1,i)
		{
			FOR(0,c-1,j)
				cout<<mem[i][j] <<" ";
			cout<<endl;
		}
			
		cout<<min(dp[r-1][c-1],mem[r-1][c-1])<<endl;
	}
	return 0 ;
}

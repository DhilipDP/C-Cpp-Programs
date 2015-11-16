#include<iostream>


#include<vector>
using namespace std ;


  int minPathSum(vector<vector<int> > &grid) {
        int i,j ;
        int m = grid.size() ;
        if(m==0)
        	return 0;
        int n = grid[0].size() ;
        int dp[m][n] ;
        dp[0][0] = grid[0][0] ;
        for(i=1 ; i<n ; i++)
        	dp[0][i] = dp[0][i-1] + grid[0][i] ;
        for(i=1 ; i<m ; i++)
        	dp[i][0] = dp[i-1][0] + grid[i][0] ;
        for(i=1 ; i<m ; i++)
        {
        	for(j=1 ; j<n ; j++){
        		dp[i][j] = min(dp[i-1][j],dp[i][j-1]) + grid[i][j] ;
			}
        }
        return dp[m-1][n-1];
    }

int main(){
	vector<vector<int> > grid ;
	vector<int> temp ;
	temp.push_back(1);
	temp.push_back(2) ;
	temp.push_back(3) ;
	grid.push_back(temp);
	temp.clear() ;
	temp.push_back(4);
	temp.push_back(5) ;
	temp.push_back(6) ;
	grid.push_back(temp);
	temp.clear();
	temp.push_back(7);
	temp.push_back(8) ;
	temp.push_back(9) ;
	grid.push_back(temp);
	cout<<minPathSum(grid);
}

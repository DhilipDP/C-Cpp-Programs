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
#define sl(a) scanf("%lld",&a)
#define sll(a) scanf("%ld",&a)
#define FOR(a,b) for(int i=a ; i<=b ; ++i)

using namespace std ;



int uniquePaths(int m,int n){

	if(m==0 || n==0)
		return 0;
	int tab[m][n];
	int i,j ;
	for(i=0 ; i<m ; i++){
		for(j=0 ; j<n ; j++){
			if(i==0 || j==0)
				tab[i][j]  = 1;
			else 
				tab[i][j] = tab[i-1][j] + tab[i][j-1] ;
		}
	}
	return tab[m-1][n-1];
}


  int uniquePathsWithObstacles(vector<vector<int> > &grid) {
        int m = grid.size() ;
        if(m==0)
        	return 0;
        int n = grid[0].size() ;
        int tab[m][n] ;
       	tab[0][0] = !(grid[0][0]);
        int i,j ;
        for(i=1 ; i<n ; i++)
        	tab[0][i] = grid[0][i]==0 ? tab[0][i-1] : 0 ;
        for(i=1 ; i<m ; i++)
        	tab[i][0] = grid[i][0]==0 ? tab[i-1][0] : 0;
        for(i=1 ; i<m ; i++){
        	for(j=1 ; j<n ; j++){
        		if(grid[i][j]==1)
        			tab[i][j] = 0;
        		else if(i==0 || j==0)
        			tab[i][j] = 1 ;
        		else
        			tab[i][j] = tab[i-1][j] + tab[i][j-1] ;
			}
        }
        return tab[m-1][n-1] ;
    }

int main() {
	cout<<uniquePaths(3,3);
	vector<vector<int> > grid ;
	vector<int> row ;
	row.push_back(0) ;
	row.push_back(0) ;
	row.push_back(0) ;
	grid.push_back(row)  ;
	row.clear() ;

		row.push_back(0) ;
	row.push_back(1) ;
	row.push_back(0) ;
	grid.push_back(row)  ;
	row.clear() ;
	
		row.push_back(0) ;
	row.push_back(0) ;
	row.push_back(0) ;
	grid.push_back(row)  ;
	row.clear() ;
	
	cout<<endl<<uniquePathsWithObstacles(grid) ;
	return 0 ;
}

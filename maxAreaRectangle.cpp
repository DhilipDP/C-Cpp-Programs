#include<iostream>
#include<vector>
using namespace std ;


int maximalRectangle(vector<vector<int> > &mat) {
	int m = mat.size() ;
	if(m==0)
		return 0;
	int n = mat[0].size() ;
	int i,j ;
	int S[m][n] ;
	int maxi =0,max_i =0 ,max_j = 0;
	for(i=0 ; i<m ; i++){
		for(j=0 ; j<n ; j++){
			if(i==0 || j==0)
				S[i][j] = mat[i][j] ;
			else if(mat[i][j]==0)
				S[i][j] = 0;
			else
			{
				S[i][j] = min(S[i][j-1],min(S[i-1][j-1],S[i-1][j]))+1;
				if(S[i][j] > maxi)
					maxi = S[i][j],max_i = i,max_j = j;
					
			}
		}
	}

		return maxi*maxi;
}

int main() {
	vector<vector<int> > mat (1,vector<int> (1,0));
	cout<<maximalRectangle(mat) ;
}

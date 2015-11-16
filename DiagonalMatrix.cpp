#include<iostream>
#define v(a,i,j,n)  *((a + i*n) + j)
#include<vector>

using namespace std ;

vector<vector<int> >res;

void print(int *mat, int i , int j,int m,int n,vector<int> &temp)
{
	while ( i<m && j >= 0)
	{
		
		temp.push_back(v(mat,i,j,n));
		i++;
		j--;
	}
}
void diagonal(int *mat,int m,int n)
{
	
	for(int i=0 ; i<n ; i++){
		vector<int> temp ;
		print(mat,0,i,m,n,temp) ;
		res.push_back((temp));
	}
	
	for(int i=1 ; i<m ; i++){
			vector<int> temp ;
		print(mat,i,n-1,m,n,temp) ;
			res.push_back((temp));	
	}
}


int main()
{
	int c = 1;
	int m= 3,n=4 ;
	int mat[m][n] ;
	int i = 1 ;
	for(int i=0 ; i<m ; i++)
		for(int j=0 ; j<n ; j++)
			mat[i][j] = c++;			


	diagonal(*mat,m,n) ;
	for(int i=0 ; i<res.size() ; i++){
		for(int j=0 ; j<res[i].size() ; j++)
			cout<<res[i][j]<<" ";
		cout<<endl;
	}
}

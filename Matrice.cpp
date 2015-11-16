#include<iostream>

using namespace std ;


int main()
{
	int t ;cin>>t ;
	while(t--)
	{
		int n ; cin>>n ;
		int mat[n][n] ;
		memset(mat,0,sizeof mat);
		int num = 1 ;
		int fr = 0 , fc = 0 , lr = n-1 , lc = n-1 ;
		while( num <= n*n)
		{
			for(int i=fc ; num <= n*n && i<=lc ; i++)
				mat[fr][i] = num++;
				
			for(int i=fr+1 ; num <= n*n && i<=lr ; i++)
				mat[i][lc] = num++ ;
				
			for(int i = lc-1 ; num <= n*n && i>=fc ; i--)
				mat[lr][i] = num++;
				
			for(int i=lr-1 ; num <= n*n && i>fr ; i--)
				mat[i][fc] = num++;
				
				
			fr++ , fc++ , lr-- , lc--;			
		}
		
		for(int i=0 ; i<n ; i++)
		{
			for(int j=0 ; j<n ; j++)
				cout<<mat[i][j]<<" ";
			cout<<endl;
		}
	}
}

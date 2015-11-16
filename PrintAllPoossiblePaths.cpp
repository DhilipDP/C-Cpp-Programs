#include<iostream>

using namespace std ;


/*count and print all popssible paths*/

int count(int m,int n){
	int  i ,j ;
	int count[m][n];
	for(i=0 ; i<m; i++)
		count[i][0] = 1;
	for(j=0 ; j<n ; j++)
		count[0][j] = 1;
	for(i=1 ; i<m ; i++){
		for(j=1 ; j<n ; j++)
			count[i][j] = count[i-1][j] + count[i][j-1] + count[i-1][j-1];
	}
	
	return count[m-1][n-1];
}


void printAllpaths(int mat[][3],int i,int j,int m,int n,int path[],int pi){
	
	if(i==m-1){
		int k,l;
		for(k=j ; k<n ; k++)
			path[pi + k-j] = mat[i][k];
		for(l=0 ; l<pi + n - j ; l++)
			cout<<path[l]<<" ";
		cout<<endl ;
		return ;
	}
	if(j==n-1){
		int k,l ;
		for(k=i ; k<m ; k++)
			path[pi+k-i] = mat[k][j];
		for(l=0 ; l<pi + m-i ; l++)
			cout<<path[l]<<" ";
		cout<<endl;
		return ;
	}
	path[pi] = mat[i][j];
	
	printAllpaths(mat,i+1,j,m,n,path,pi+1) ;
	printAllpaths(mat,i,j+1,m,n,path,pi+1) ;
	printAllpaths(mat,i+1,j+1,m,n,path,pi+1);

}

int main(){
	int mat[2][3] = {1,2,3,4,
					5,6};//8},//,
				//	{9,10,11,12}};
	cout<<"\nNumner of possible paths:\n";
	cout<<count(2,3);
	int *path = new int[100];
	cout<<endl;
	printAllpaths(mat,0,0,2,3,path,0);
}

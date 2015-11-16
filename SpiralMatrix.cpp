#include<iostream>

using namespace std ;


void printMatrix(int mat[][4],int r,int c){
	for(int i=0 ; i<r ; i++){
		for(int j=0 ; j<c ; j++)
			cout<<mat[i][j]<<" ";
		cout<<endl;
	}
}


void spiralMatrix(int mat[][4],int r,int c){
	int row_start = 0;
	int row_end = r;
	int col_start = 0;
	int col_end = c ;
	while(row_start < row_end && col_start < col_end){
		int i,j;
		for(i=col_start ; i<col_end ; i++)
			cout<<mat[row_start][i]<<" ";
		row_start++;
		cout<<endl;
		for(j = row_start ; j<row_end ; j++)
			cout<<mat[j][col_end-1]<<" ";
		col_end--;
		cout<<endl;
		if(row_start < row_end){
		for(i = col_end-1 ; i>=col_start ; i--)
			cout<<mat[row_end-1][i]<<" ";
				row_end--;
		cout<<endl;
		}
		if(col_start < col_end){
		for(i = row_end-1 ; i>row_start ; i--)
			cout<<mat[i][col_start]<<" ";
		col_start++;
		cout<<endl;
	}
		
	
		
	}
	
}
int main(){
	int mat[4][4] ={ {1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
	//int row_size = sizeof(mat)/sizeof(mat[0]);
//	int col_size = (sizeof(mat)/sizeof(int))/row_size ;
//	cout<<row_size<<" "<<col_size<<endl;111
	spiralMatrix(mat,4,4);
	//printMatrix(mat,4,4);
}

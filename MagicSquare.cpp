#include<iostream>

using namespace std ;


void printMagicSquare(int n){
	int magic[n][n] ,i,j;
	int row = 0,col = n/2 ;
	for(i=1 ; i<= n*n ; i++){
		magic[row][col] = i;
		if(i % n == 0)
			row++;
		else{
			row--;
			col++;
			if(row == -1)
				row = n-1;
			if(col==n)
				col=0;
		}
	}
	for(i=0 ; i<n ; i++){
		for(j=0 ; j<n ; j++){
			cout<<magic[i][j]<<" ";
		}
		cout<<endl;
	}
}
int main(){
 	printMagicSquare(3);
}

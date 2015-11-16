#include<iostream>

using namespace std ;

#define N 2

int board[N][N] ;


bool isSafe(int row,int col)
{
	int i,j;
	for(i=0 ; i<col ; i++)
		if(board[row][i])
			return false;
	for(i=row , j=col ; i>=0 && j>=0 ; i--,j--)
		if(board[i][j])
			return false ;
	for(i=row,j=col ; i<N && j>=0 ; i++,j-- )
		if(board[i][j])
			return false;
	return true;
}

void print(){
	for(int i=0 ; i<N ; i++)
	{
		for(int j=0 ; j<N ; j++)
			cout<<board[i][j]<<" ";
		cout<<endl;
	}
	cout<<endl;
}


void solve(int c){
	if(c >= N){
		print();
	}
	for(int i=0 ; i<N ; i++){
		if(isSafe(i,c)){
		
		board[i][c] = 1;
		(solve(c+1));
		board[i][c] = 0;
		}
	}
}

int main(){
	solve(0);
//	print();
	return 0;
}

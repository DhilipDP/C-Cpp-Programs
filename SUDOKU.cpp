#include<iostream>
using namespace std;
#define N 9

void printArray(int grid[N][N])
{
	for(int i=0 ; i<N ; i++){
		for(int j=0 ; j<N ; j++)
			cout<<grid[i][j]<<"  ";
		cout<<endl ;
	}
}


bool isUsedBox(int rowStart ,int colStart,int grid[N][N] , int num){
	for(int row = 0  ; row <3 ; row++)
		for(int col=0 ; col<3 ; col++)
			if(grid[row+rowStart][col+colStart]==num)
				return true;
	return false ;	
}

bool isUsedCol(int &col,int grid[N][N],int num){
	for(int row = 0 ; row<N ; row++)
		if(grid[row][col]==num)	
			return true ;
	return false; 
	
}

bool isUsedRow(int &row,int grid[N][N],int num){
	for(int col = 0 ; col<N ; col++)
		if(grid[row][col]==num)	
			return true ;
	return false; 
	
}

bool isSafe(int grid[N][N] , int &row ,int &col,int num){
	if(!isUsedRow(row,grid,num) && !isUsedCol(col,grid,num) && !isUsedBox(row-row%3,col-col%3,grid,num))
		return true ;
	return false;
}

bool findUnassignedLocation (int grid[N][N] , int &row ,int &col){
	for(row = 0 ; row < N ; row++)	
		for(col = 0 ; col < N ; col++)
			if(grid[row][col]==0)
				return true;
	return false ;
}

bool solveSudoku(int grid[N][N]){
	int row,col ;
	if(!findUnassignedLocation(grid,row,col))
		return true ;
	for(int num = 1 ; num<=9 ; num++){
		if(isSafe(grid,row,col,num)){
			grid[row][col] = num ;
			if(solveSudoku(grid))
				return true ;
			grid[row][col] = 0; 
		}
	}
	return false ;
}


int main(){
//[".....7..9",".4..812..","...9...1.","..53...72","293....5.",".....53..","8...23...","7...5..4.","531.7...."]

	int grid[N][N] = {{0, 0, 0, 0, 0, 7, 0, 0, 9},
                      {0, 4, 0, 0, 8, 1, 2, 0, 0},
                      {0, 0, 0, 9, 0, 0, 0, 1, 0},
                      {0, 0, 5, 3, 0, 0, 0, 7, 2},
                      {2, 9, 3, 0, 0, 0, 0, 5, 0},
                     { 0, 0, 0, 0, 0, 5, 3, 0, 0},
                      {8, 0, 0, 0, 2, 3, 0, 0, 0},
                      {7, 0, 0, 0, 5, 0, 0, 4, 0},
                      {5, 3, 1, 0, 7, 0, 0, 0, 0}};
                  //    {0, 0, 0, 2, 7, 5, 9, 0, 0}};
	if(solveSudoku(grid))
		printArray(grid);
	else
		cout<<"No Solution";

}

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


#define ll long long
#define p(a) printf("%d\n",a)
#define s(a) scanf("%d",&a)
#define sl(a) scanf("%lld",&a)
#define sll(a) scanf("%ld",&a)
#define FOR(a,b) for(int i=a ; i<=b ; ++i)

using namespace std ;
 
 
// 
  
bool findUnassignedLocation(vector<vector<char> > &board,int &row,int &col){
	  	for(row = 0 ; row<9 ; row++){
	  		for(col=0 ; col<9 ; col++){
	  			if(board[row][col] == '.')
	  				return true ;
	  		}
	  	}
	  	return false;	  			
  }
  
 bool isPresentBoard(vector<vector<char> > &board,int &num,int rowS,int colS,int r,int c){

		int i,j; 	
	 	for(i=0 ; i<3 ; i++){
	 		for(j=0 ; j<3 ; j++)
			 	if(!(i+rowS==r && j+colS==c) && board[i+rowS][j+colS]-'0' == num)
				 	return true;	
 		}
 	
 		return false ;
 }
	
	
  bool isPresentCol(vector<vector<char> > &board,int &num,int &row,int &col){

  	for(int i=0 ; i<9 ; i++)
  		if(i!=row && board[i][col]-'0'==num)
  			return true ;

	  return false ;
  
  }
  
  bool isPresentRow(vector<vector<char> > &board,int &num,int &row,int &col){
  	for(int i=0 ; i<9 ; i++)
  		if(i!=col && board[row][i]-'0'==num)
  			return true ;

  	return false ;
  
  }
  
  bool isPresent(vector<vector<char> > &board,int num,int &row,int &col){
  	if(isPresentRow(board,num,row,col) || isPresentCol(board,num,row,col) || isPresentBoard(board,num,row-row%3,col-col%3,row,col))
  		return true ;
  	return false ;
  }
  bool sudoku(vector<vector<char> > &board){
  		int row,col ;
  		if(!findUnassignedLocation(board,row,col))
  			return true ;
  		for(int num=1 ; num<=9 ; num++){
  			if(isPresent(board,num,row,col)){
  				board[row][col] = num+'0' ;
  				if(sudoku(board))
  					return true;
		  		board[row][col] = '.';
		  	}
  			
	  	}
  		return false;
  }
  
  
int main() {
	
	vector<vector<char> > board ;
	vector<char> row ;
	row.push_back('.');
	row.push_back('8');
	row.push_back('7');
	row.push_back('6');
	row.push_back('5');
	row.push_back('4');
	row.push_back('3');
	row.push_back('2');
	row.push_back('1');
	board.push_back(row);
	row.clear();
	
	row.push_back('2');
	row.push_back('.');
	row.push_back('.');
	row.push_back('.');
	row.push_back('.');
	row.push_back('.');
	row.push_back('.');
	row.push_back('.');
	row.push_back('.');
	board.push_back(row);
	row.clear();
	
	row.push_back('3');
	row.push_back('.');
	row.push_back('.');
	row.push_back('.');
	row.push_back('.');
	row.push_back('.');
	row.push_back('.');
	row.push_back('.');
	row.push_back('.');
	board.push_back(row);
	row.clear();
	
	row.push_back('4');
	row.push_back('.');
	row.push_back('.');
	row.push_back('.');
	row.push_back('.');
	row.push_back('.');
	row.push_back('.');
	row.push_back('.');
	row.push_back('.');
	board.push_back(row);
	row.clear();
	
	row.push_back('5');
	row.push_back('.');
	row.push_back('.');
	row.push_back('.');
	row.push_back('.');
	row.push_back('.');
	row.push_back('.');
	row.push_back('.');
	row.push_back('.');
	board.push_back(row);
	row.clear();
	
	row.push_back('6');
	row.push_back('.');
	row.push_back('.');
	row.push_back('.');
	row.push_back('.');
	row.push_back('.');
	row.push_back('.');
	row.push_back('.');
	row.push_back('.');
	board.push_back(row);
	row.clear();
	
	row.push_back('7');
	row.push_back('.');
	row.push_back('.');
	row.push_back('.');
	row.push_back('.');
	row.push_back('.');
	row.push_back('.');
	row.push_back('.');
	row.push_back('.');
	board.push_back(row);
	row.clear();
	
	row.push_back('8');
	row.push_back('.');
	row.push_back('.');
	row.push_back('.');
	row.push_back('.');
	row.push_back('.');
	row.push_back('.');
	row.push_back('.');
	row.push_back('.');
	board.push_back(row);
	row.clear();
		
	row.push_back('9');
	row.push_back('.');
	row.push_back('.');
	row.push_back('.');
	row.push_back('.');
	row.push_back('.');
	row.push_back('.');
	row.push_back('.');
	row.push_back('.');
	board.push_back(row);
	row.clear();
	
		
	cout<<isValidSudoku(board)<<endl;
	
	for(int i=0 ; i<9 ; i++){
		for(int j=0 ; j<9 ; j++)
			cout<<board[i][j]<<"\t";
		cout<<endl;
	}
	return 0 ;
}

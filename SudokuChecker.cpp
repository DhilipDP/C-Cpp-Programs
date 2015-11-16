

#include<vector>
#include<iostream>

using namespace std ;



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
  
  
  int main(){
  	vector<vector<char> > board(9,vector<char>(9,'*')) ;
  	for(int i=0 ; i<9 ; i++)
  	for(int j=0 ; j<9 ; j++)
  	{
  		char c;
  		cin>>c;
  		board[i][j] = c;
  	}
  	bool flag = true ;
  	for(int i=0 ; i<9 ; i++){
  		for(int j=0 ; j<9 ; j++){
  			if(isPresent(board,board[i][j]-'0',i,j)){
  				flag = false ;
  				break;
			}
		}
	  
	  }
	  if(flag)
	  	cout<<"Correct"<<endl;
	 	else
	  	cout<<"Incorrect"<<endl;
	  
  }

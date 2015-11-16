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
  
  bool usedBox(vector<vector<char> > board,int rowStart,int colStart,char num){
        for(int row =0 ; row<3 ; row++)
         for(int col=0 ; col<3 ; col++)
            if(board[row+rowStart][col+colStart]==num)
                return true;
        return false;
    }

    bool usedCol(vector<vector<char> > board,int col,char num){
        for(int row=0 ; row<9 ; row++)
            if(board[row][col]==num)
                return true;
        return false;
    }
    
    bool usedRow(vector<vector<char> > board,int row,char num){
        for(int col=0 ; col<9 ; col++)
            if(board[row][col]==num)
                return true;
        return false;
    }

    bool isSafe(vector<vector<char> > board,int row,int col,char num){
        if(!usedRow(board,row,num) && !usedCol(board,col,num) && !usedBox(board,row-row%3,col-col%3,num))
            return true;
        return false;
    }
    bool findUnassigned(vector<vector<char> > board,int &row,int &col){
        for(int i=0 ; i<9 ; i++)
        {
            for(int j=0 ; j<9 ; j++){
                if(board[i][j]=='.'){
                    row=i;
                    col=j;
                    return true;
                }
            }
        }
        return false;
    }
    bool sudoku(vector<vector<char> > &board) {
        int row,col;
        if(!findUnassigned(board,row,col))
            return true;
        for(char num='a' ; num<='z' ; num++){
            if(isSafe(board,row,col,num)){
           // 	cout<<"Safe: "<<row<<" "<<col<<endl;
                board[row][col] = num;
                if(sudoku(board))
                    return true;
                board[row][col] = '.';
            }
        }
        return false;
    }

  
int main() {
	
	vector<vector<char> > board(9,vector<char>(9,'.')) ;
	for(int i=0 ; i<9 ; i++){
		string s;
		cin>>s;
		for(int j=0 ; j<9 ; j++){
			board[i][j] = s[j];
		}
	}
	string word;
	cin>>word;
//	sudoku(board);
	vector<vector<char> > temp;
//	cout<<"hi";
	bool flag = false;
	for(int i=0 ; i<9 ; i++){
		temp = board;
		bool f=false;
		for(int j= 0 ; j<9 ; j++)
		{
			if(temp[i][j]!='.' && temp[i][j] != word[j])
			{
				f=true;
				break;
			}
		}
		if(!f){
			for(int j=0 ; j<9 ; j++)
				temp[i][j] = word[j] ;
			if(sudoku(temp)){
				cout<<"Row "<<i+1;	
				flag= true;
				break;
			}
		}
	}
	if(!flag){
	for(int i=0 ; i<9 ; i++){
		temp = board;
		bool f=false;
		for(int j= 0 ; j<9 ; j++)
		{
			if(temp[j][i]!='.' && temp[j][i] != word[j])
			{
				f=true;
				break;
			}
		}
		if(!f){
			for(int j=0 ; j<9 ; j++)
				temp[j][i] = word[j] ;
			if(sudoku(temp)){
				cout<<"Column "<<i+1;	
				flag= true;
				break;
			}
		}
	}
}	

/*	for(int i=0 ; i<9 ; i++){
		for(int j=0 ; j<9 ; j++)
			cout<<board[i][j]<<"\t";
		cout<<endl;
	} */
	return 0 ;
}

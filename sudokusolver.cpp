#include<iostream>
#include<vector>
using namespace std;

  bool usedBox(vector<vector<char> > board,int rowStart,int colStart,int num){
        for(int row =0 ; row<3 ; row++)
         for(int col=0 ; col<3 ; col++)
            if(board[row+rowStart][col+colStart]-'0'==num)
                return true;
        return false;
    }

    bool usedCol(vector<vector<char> > board,int col,int num){
        for(int row=0 ; row<9 ; row++)
            if(board[row][col]-'0'==num)
                return true;
        return false;
    }
    
    bool usedRow(vector<vector<char> > board,int row,int num){
        for(int col=0 ; col<9 ; col++)
            if(board[row][col]-'0'==num)
                return true;
        return false;
    }

    bool isSafe(vector<vector<char> > board,int row,int col,int num){
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
    
    
    int SuitableVals(vector<vector<char> > &grid, int row, int col)
{
int total = 0;
for (int i = 1; i < 10; i++)
{
if (isSafe(grid, row, col, i))
total++;
}
return total;
}

bool FindUnassignedLocation(vector<vector<char> > &grid, int &row, int &col)
{
int min = 10;
int cur = 0;
int retrow, retcol;
bool solfound = false;
for (retrow = 0; retrow < 9; retrow++)
{
for (retcol = 0; retcol < 9; retcol++)
{
if (grid[retrow][retcol] == '.')
{
solfound = true;
cur = SuitableVals(grid, retrow, retcol);
if (cur < min)
{
min = cur;
row = retrow;
col = retcol;
}
}
}
}
return solfound;
}
    bool solve(vector<vector<char> > &board) {
        int row,col;
        if(!FindUnassignedLocation(board,row,col))
            return true;
        for(int num=1 ; num<=9 ; num++){
            if(isSafe(board,row,col,num)){
           // 	cout<<"Safe: "<<row<<" "<<col<<endl;
                board[row][col] = num+'0';
                if(solve(board))
                    return true;
                board[row][col] = '.';
            }
        }
        return false;
    }
    void print(vector<vector<char> > &board){
         for(int i=0 ; i<9 ; i++){
         	for(int j=0 ; j<9 ; j++)
         		cout<<board[i][j]<<" ";
         	cout<<endl;
		 }
    }
    void solveSudoku(vector<vector<char> > &board){
         solve(board);
       //  cout<<"solved"<<endl;
         //print(board);
    }
    
    
    int main(){
    	//[".....7..9",".4..812..","...9...1.","..53...72","293....5.",".....53..","8...23...","7...5..4.","531.7...."]
    	vector<vector<char> > v;
    	vector<char> t;
    	t.clear();
    	t.push_back('.');t.push_back('.');t.push_back('.');t.push_back('.');t.push_back('.');t.push_back('7');t.push_back('.');t.push_back('.');t.push_back('9');
    	v.push_back(t);
    	t.clear();
    	t.push_back('.');t.push_back('4');t.push_back('.');t.push_back('.');t.push_back('8');t.push_back('1');t.push_back('2');t.push_back('.');t.push_back('.');
    	v.push_back(t);
    	t.clear();
    	t.push_back('.');t.push_back('.');t.push_back('.');t.push_back('9');t.push_back('.');t.push_back('.');t.push_back('.');t.push_back('1');t.push_back('.');
    	v.push_back(t);
    	t.clear();
    	t.push_back('.');t.push_back('.');t.push_back('5');t.push_back('3');t.push_back('.');t.push_back('.');t.push_back('.');t.push_back('7');t.push_back('2');
    	v.push_back(t);
		t.clear();
    	t.push_back('2');t.push_back('9');t.push_back('3');t.push_back('.');t.push_back('.');t.push_back('.');t.push_back('.');t.push_back('5');t.push_back('.');
    	v.push_back(t);
    	t.clear();
    	t.push_back('.');t.push_back('.');t.push_back('.');t.push_back('.');t.push_back('.');t.push_back('5');t.push_back('3');t.push_back('.');t.push_back('.');
    	v.push_back(t);
    	t.clear();
    	t.push_back('8');t.push_back('.');t.push_back('.');t.push_back('.');t.push_back('2');t.push_back('3');t.push_back('.');t.push_back('.');t.push_back('.');
    	v.push_back(t);
    	t.clear();
    	t.push_back('7');t.push_back('.');t.push_back('.');t.push_back('.');t.push_back('5');t.push_back('.');t.push_back('.');t.push_back('4');t.push_back('.');
    	v.push_back(t);
    	t.clear();
    	t.push_back('5');t.push_back('3');t.push_back('1');t.push_back('.');t.push_back('7');t.push_back('.');t.push_back('.');t.push_back('.');t.push_back('.');
    	v.push_back(t);
    	solveSudoku(v);
	}

#include<iostream>
using namespace std ;
#define N 4




void print(int sol[N][N]){
	int i,j;
	for(i=0 ; i<N ; i++){
		for(j=0 ; j<N ; j++)
			cout<<sol[i][j]<<" ";
		cout<<endl;
	}
	cout<<endl;
}


bool isSafe(int x,int y,int maze[N][N]){
	if(x >=0 && x<N && y>=0 && y<N && maze[x][y]==1)
		return true ;
	return false ;
}


bool solve(int maze[N][N],int solution[N][N],int i,int j){
	if(i==N-1 && j==N-1){
		solution[i][j] = 1;
			print(solution);
			return true;
	}
	bool flag = false ;
	if(isSafe(i,j,maze)){
		solution[i][j] =  1 ;
		if(solve(maze,solution,i,j+1))
			return true;
		if(solve(maze,solution,i+1,j))
			return true;

			solution[i][j] = 0;
	}
	if(!flag)
		return false;
	return true;
}

void rat_in_a_maze(int maze[N][N] ){
	int solution[N][N];
	for(int i=0 ; i<N ; i++)
		for(int j=0 ; j<N ; j++)
			solution[i][j] = 0;
	if(solve(maze,solution,0,0)){
		cout<<"\nSolved\n";
	//	print(solution);
	}
	else{
	cout<<"No SOlution";
	}
}
int main(){
	int maze[N][N] = {{1, 0, 0, 0},
	                {1, 1, 0, 1},
	                {0, 1, 1, 0},
	                {1, 1, 1, 1}};
	
    rat_in_a_maze(maze);
    //cout<<"hi";
    return 0;
}

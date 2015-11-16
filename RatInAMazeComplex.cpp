#include<iostream>
using namespace std ;
#define N 4

int mini = 10000;



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


void solve(int maze[N][N],int solution[N][N],int i,int j,int moves,int (*answer)[N],int sol){
	if(i==N-1 && j==N-1){
		sol = 1;
		solution[i][j] = 1;
	//	print(solution);
		moves++;
		if(moves < mini){
			
	//		cout<<moves<<endl;
			//cout<<"moves: "<<moves<<endl;
			mini = moves ;
			//memcpy(answer,solution,sizeof(solution)) ;
			for(int x=0 ; x<N ; x++)
				for(int y=0 ; y<N ; y++)
					answer[x][y] = solution[x][y];
		}
		
		//print(solution);
			return ;
	}
//	int s = 0;
	if(isSafe(i,j,maze)){
		moves++;
		solution[i][j] =  1 ;
		if(moves > mini)
			return ;
	//	cout<<"safe :"<<i<<" "<<j<<endl;
		solve(maze,solution,i,j+1,moves,answer,sol);
		solve(maze,solution,i+1,j,moves,answer,sol);
		solve(maze,solution,i+1,j+1,moves,answer,sol);
		solve(maze,solution,i-1,j-1,moves,answer,sol);
		
		/*	return true;
		if(solve(maze,solution,i+1,j+1,moves))
			return true;
		if(solve(maze,solution,i-1,j-1,moves))
			return true; */
	//	if(sol!=0)
		solution[i][j] = 0;
	}
}

void rat_in_a_maze(int maze[N][N] ){
	int solution[N][N];
	for(int i=0 ; i<N ; i++)
		for(int j=0 ; j<N ; j++)
			solution[i][j] = 0;
	int moves = -1;
	int answer[N][N] ;
	int sol = 0;
	solve(maze,solution,0,0,moves,answer,sol);
	answer[0][0] = 1;
	print(answer);
}
int main(){
//	int maze[N][N] = {{1,0},{1,1}};
	int maze[N][N] = {{1, 0, 0, 0},
                {1, 1, 0, 1},
                {0, 1, 1, 0},
                {1, 1, 1, 1}};
    
	
    rat_in_a_maze(maze);
    //cout<<"hi";
    return 0;
}

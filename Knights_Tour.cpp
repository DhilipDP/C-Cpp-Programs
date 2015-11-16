#include<iostream>
#define N 8
using namespace std ;


void print(int sol[N][N]){
	int i,j;
	for(i=0 ; i<N ; i++){
		for(j=0 ; j<N ; j++)
			cout<<sol[i][j]<<" ";
		cout<<endl;
	}
}


bool isSafe(int x,int y,int sol[N][N]){
	if(x >=0 && x<N && y>=0 && y<N && sol[x][y] == -1)
		return true;
	return false ;
}
bool _solve(int sol[N][N],int xMove[],int yMove[],int x,int y,int move){
	if(move == N*N)
		return true ;
	int k,nextx,nexty ;
	for(k=0 ; k<8 ; k++){
		nextx = x + xMove[k];
		nexty = y + yMove[k];
		if(isSafe(nextx,nexty,sol)){
 		//	cout<<nextx<<" "<<nexty<<" : "<<move<<endl;
 			sol[nextx][nexty] = move;
			if(_solve(sol,xMove,yMove,nextx,nexty,move+1))
				return true ;
			else
				sol[nextx][nexty] = -1;
		}
	}
	return false;
}

void solve_KT(){
	int sol[N][N] ;
	int i,j;
	for(i=0 ; i<N ; i++)
		for(j=0 ; j<N  ; j++)
			sol[i][j] = -1 ;
	sol[0][0] = 0;
	int xMove[8] = {  2, 1, -1, -2, -2, -1,  1,  2 };
    int yMove[8] = {  1, 2,  2,  1, -1, -2, -2, -1 };
	if(_solve(sol,xMove,yMove,0,0,1)){
		cout<<"\nSolved\n";
		print(sol);
		return ;
	}
	cout<<"\nNo Solution";
}
int main(){
	solve_KT();
}

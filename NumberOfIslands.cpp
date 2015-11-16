#include<iostream>
#define value(m,i,j) *(m + i * j)
using namespace std ;



int x[] = {-1,-1,-1,0,0,1,1,1} ;
int y[] = {-1,0,1,-1,1,-1,0,1} ;


bool isValid(int i,int j,int r,int c,int *visited)
{
	if(i>=0 && i<r && j>=0 && j<c && value(visited,i,j)==0)
		return true ;
	return false;
}

void dfs(int *mat,int i,int j,int &r,int &c ,int *visited)
{
//8	cout<<i<<" "<<j<<endl;
	value(visited,i,j) = 1;
	for(int k=0 ; k<8 ; k++){
		if(isValid(i+x[k],j+y[k],r,c,visited))
				dfs(mat,i+x[k],j+y[k],r,c,visited);
	}
}
int numberOfIslands(int *mat,int r,int c)
{
	int count = 0;
		int visited[r][c] ;
		memset(visited,0,sizeof(visited)) ;
		for(int i=0 ;i<r ; i++){
			for(int j=0 ; j<c ; j++){
				if(!visited[i][j]){
			
					dfs(mat,i,j,r,c,*visited);
					count++;
				}
			}
		//
			cout<<endl;
		}
}

int main()
{
	int *p ;
	void * q;
	p = q; 
	
	int mat[][5]= {  {1, 1, 0, 0, 0},
        {0, 1, 0, 0, 1},
        {1, 0, 0, 1, 1},
        {0, 0, 0, 0, 0},
        {1, 0, 1, 0, 1}
    };
 	cout<<numberOfIslands(*mat,5,5);
}

#include<iostream>
#include<vector>
using namespace std ;


int x[] = {-1,1,0,0} ;
int y[] = {0,0,-1,1} ;


bool isValid(int i,int j,int r,int c,vector<vector<int> >&visited,vector<string> &mat)
{
	if(i>=0 && i<r && j>=0 && j<c && visited[i][j]==0 && mat[i][j]=='X')
		return true ;
	return false;
}

void dfs(vector<string> &mat,int i,int j,int &r,int &c ,vector<vector<int> >&visited)
{
//8	cout<<i<<" "<<j<<endl;
	visited[i][j] = 1;
	for(int k=0 ; k<4 ; k++){
		if(isValid(i+x[k],j+y[k],r,c,visited,mat))
				dfs(mat,i+x[k],j+y[k],r,c,visited);
	}
}
int numberOfIslands(vector<string> &mat,int r,int c)
{
	int count = 0;
	
	vector<vector<int> > visited(r, vector<int>(c,0)); 
		for(int i=0 ;i<r ; i++){
			for(int j=0 ; j<c ; j++){
				if(!visited[i][j] && mat[i][j]=='X'){
			
					dfs(mat,i,j,r,c,visited);
					count++;
				}
			}
		//
		//	cout<<endl;
		}
		return count ;
}


int black(vector<string> &A) {
    if(A.size() == 0)
        return 0;
    return numberOfIslands(A,A.size(),A[0].size());    
}


int main()
{
	vector<string> v ;
	string s = "OOOXOOO" ;
	v.push_back(s) ;
	s =  "OOXXOXO" ;v.push_back(s) ;
	s =  "OXOOOXO" ; v.push_back(s) ;
	cout<<black(v) ;
}

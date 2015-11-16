#include<iostream>
#include<vector>
#include<stdio.h>
#include<limits.h>
#define pi pair<int,int>
#define mp(a,b) make_pair(a,b)
using namespace std ;
int n,m;
pi start,end;


bool valid(vector<vector<char> > grid,int row,int col,vector<vector<bool> > visited){
	if(row >= 0 && col>=0 && row <n && col <m && grid[row][col]!='#' && visited[row][col]==false)
		return true;
	return false ;
}


int minimum(int a,int b,int c,int d){
	
	return (min(min(min(a,b),c),d));
}
int solve(vector<vector<char> > grid,int i,int j,int moves,vector<vector<bool> > visited){
	
	
//	cout<<i<<" "<<j<<endl;
	visited[i][j] = true;
	if(i==end.first && j==end.second){
	
		return moves ;
	}
	bool north=false,south=false,left=false,right=false;
	if(valid(grid,i-1,j,visited))
		north = true;
	if(valid(grid,i+1,j,visited))
		south = true;
	if(valid(grid,i,j-1,visited))
		left = true;
	if(valid(grid,i,j+1,visited))
		right = true;
	if(north==false && south==false && left==false && right==false)
		return INT_MAX;
	int mini = INT_MAX ;
	if(north)
		mini = min(mini,solve(grid,i-1,j,moves+1,visited));
	if(south)
		mini = min(mini,solve(grid,i+1,j,moves+1,visited));
	if(left)
		mini = min(mini,solve(grid,i,j-1,moves+1,visited));
	if(right)
		mini = min(mini,solve(grid,i,j+1,moves+1,visited));
	return mini ;
}



int main(){
	
	
	
	cin>>n>>m;
	vector<vector<char> > grid(n, vector<char>(m,'.'));
	vector<vector<bool> > visited(n, vector<bool>(m,false));
//	int i,j;

	for(int i=0 ; i<=n ; i++){
		char s[m+1];
		cin.getline(s,m+1);
		if(i==0)
			continue;
		//cout<<s<<endl;
		for(int j=0 ; j<m ; j++)
			grid[i-1][j] = s[j];
	
	}
	for(int i=0 ; i<n ; i++){
		for(int j=0 ; j<m ; j++){
			char c = grid[i][j] ;
			if(c=='S')
			start = mp(i,j);
		if(c=='E')
			end = mp(i,j);	
		}
	
	}
/*	for(int j= 0 ; j<m ; j++)
	{
		cout<<i<<" "<<j<<" : "<<endl;
		char c;
		cin>>c;
		
		grid[i][j] = c;
	}
	}
	cout<<"hi";*/
	int m = solve(grid,start.first,start.second,0,visited);
	if(m==INT_MAX)
		cout<<"-1";
	else
		cout<<m;
	
}


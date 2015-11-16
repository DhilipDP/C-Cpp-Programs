#include <iostream>
#include<vector>
#include<stdio.h>
#include<stack>
#include<vector>
#include<queue>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<limits.h>
#include<map>
#include<algorithm>
#include<utility>


#define ll long long
#define p(a) printf("%d\n",a)
#define s(a) scanf("%d",&a)
#define sll(a) scanf("%lld",&a)
#define sl(a) scanf("%ld",&a)
#define FOR(a,b,it) for( it=a ; it<=b ; ++it)
#define pi pair<int,int> 

using namespace std ;


bool valid(int n,int r,int c,vector<vector<bool> > &visited,vector<vector<int> > &S)
{
	if( r >=0 && r<n && c>=0 && c<n && visited[r][c]==false && S[r][c] != 0)
		return 1;
	return 0;
}


int rec(vector<vector<int> > S,int cost,vector<vector<bool> > visited,int i,int j,int des,int cl,int cr,int cd){

	if(i==des)
		return cost;
	
	visited[i][j] = true ;
	if(S[i][j]==0)
	   return INT_MAX;
	int a,b,c;
	a=b=c=INT_MAX;
	if(valid(des+1,i,j-1,visited,S))
	{
		cost += cl;
		a = rec(S,cost,visited,i,j-1,des,cl,cr,cd);
	}
		if(valid(des+1,i,j+1,visited,S))
	{
		cost += cr;
		b = rec(S,cost,visited,i,j+1,des,cl,cr,cd);
	}
		if(valid(des+1,i+1,j,visited,S))
	{
		cost += cd;
		c = rec(S,cost,visited,i+1,j,des,cl,cr,cd);
	}
	return min(min(a,b),c);
	
}

int main() {
	int t;
	s(t);
	while(t--)
	{
		int cl,cr,cd ;
		s(cl);
		s(cr);
		s(cd);
		int n ;
		s(n);
		vector<vector<int> >S ; 
		int i,j;
		FOR(0,n-1,i){
			vector<int> temp;
			FOR(0,n-1,j){
				int tp ;
				s(tp);
				temp.push_back(tp);
			}
			S.push_back(temp);
		}
		int start;
		s(start);
		if(S[0][start]==0)
		{
			cout<<"-1"<<endl;
			continue;
		}
		vector<vector<bool> >  visited(n, vector<bool>(n,false));
		int cost = 0;
		cout<<rec(S,cost,visited,0,start,n-1,cl,cr,cd)<<endl; 
	}
	return 0 ;
}

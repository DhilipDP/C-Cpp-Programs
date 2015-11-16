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

int row,col,k,n,m;

bool isValid(int r,int c, vector<vector<int> > visited){
	if(r >=0 && r<n && c>=0 && c<m && visited[r][c] == 0)
		return true;
	return false;
		
	
}


vector<vector<char> > travel(vector<vector<char> > v,int i,int j,int moves,vector<vector<int> > visited){
	cout<<i<<" "<<j<<" "<<moves<<endl;
	if(i==row && j==col && moves==0)
		return v;
	if(moves>0)	
	{
		visited[i][j] = 1;
		if(isValid(i-1,j,visited)){
			v[i][j] = 'U';
			travel(v,i-1,j,moves-1,visited);
		}	
		if(isValid(i+1,j,visited)){
			v[i][j] = 'D';
			travel(v,i+1,j,moves-1,visited);
		}	
		if(isValid(i,j+1,visited)){
			v[i][j] = 'R';
			travel(v,i,j+1,moves-1,visited);
		}	
		if(isValid(i,j-1,visited)){
			v[i][j] = 'L';
			travel(v,i,j-1,moves-1,visited);
		}	
	}
	return v;
	
}
int main() {
	s(n);
	s(m);
	s(k);
	int i;
	vector<string> arr(n," ");
	FOR(0,n-1,i){
		cin>>arr[i];
		int  len = arr[i].length() ;
		for(int j=0 ; j<len ; j++)
			if(arr[i][j] == '*')
			{
				row = i;
				col = j;
			}
	}
	vector<vector<char> > v(n,vector<char>(m,'-'));
	vector<vector<int> >visited(n,vector<int>(m,0));
	v = travel(v,0,0,k,visited); 
	for(int i=0 ; i<n ; i++){
		for(int j=0 ; j<m ; j++)
			cout<<v[i][j]<<" ";
		cout<<endl;
	}
	cout<<"hello";
	vector<vector<char> > :: iterator it ;
	for(it = v.begin() ; it!=v.end() ; it++)
	{
		vector<char> t = *it;
		vector<char> :: iterator ite ;
		for(ite = t.begin() ; ite != t.end() ; ite++)
			cout<<*ite<<" ";
		cout<<endl;
	}
	return 0 ;
}

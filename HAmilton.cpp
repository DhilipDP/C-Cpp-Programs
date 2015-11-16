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


bool valid(int n,int r,int c)
{
	if( r >=0 && r<n && c>=0 && c<n)
		return 1;
	return 0;
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
		int S[n][n] ;
		int i,j;
		FOR(0,n-1,i)
			FOR(0,n-1,j)
				s(S[i][j]);
			int start;
		s(start);
		if(S[0][start]==0)
		{
			cout<<"-1"<<endl;
			continue;
		}
		if(valid(n,0,start-1))
			S[0][start-1] = S[0][start] + cl;
		if(valid(n,1,start))
			S[1][start] = S[0][start] + cd;
		if(valid(n,0,start+1))
			S[0][start+1] = S[0][start] + cr;
						
		FOR(1,n-1,i){
			FOR(0,n-1,j){
				//left
				if(S[i][j]!=0 && S[i][j]!=1  &&  valid(n,i,j-1) && S[i][j-1] != 0 && ( S[i][j-1]==1 || S[i][j] + cl < S[i][j-1] ))
					S[i][j-1] = S[i][j] + cl;
					
				//down
				if(S[i][j]!=0 && S[i][j]!=1  && valid(n,i+1,j) && S[i+1][j] != 0 && ( S[i+1][j]==1 || S[i][j] + cd < S[i+1][j]))
					S[i+1][j] = S[i][j] + cd;
				//bottom
					if( S[i][j]!=0 && S[i][j]!=1  && valid(n,i,j+1) &&  S[i][j+1] != 0 && ( S[i][j+1]==1 ||  S[i][j] + cr < S[i][j+1]))
					S[i][j+1] = S[i][j] + cr;
			}
			
		}
		for(i=0;i<n;i++){
			for(j=0 ;j<n ; j++)
				cout<<S[i][j]<<" ";
			cout<<endl;
		}
		int mini  = INT_MAX;
		bool flag  = false;
		for(i=0 ; i<n ; i++)
			if(S[n-1][i]!=0 && S[n-1][i] != 1)
			{
				flag = true;
				break;
			}
		if(!flag)
			cout<<"-1"<<endl;
		else{
			for(int i=0 ; i<n ; i++){
				if( S[n-1][i] !=0  && S[n-1][i]!=1)
				mini = min(S[n-1][i],mini);
			}
			cout<<mini<<endl;
		}
	}
	return 0 ;
}

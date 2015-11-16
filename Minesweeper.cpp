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

int mat[105][105];

bool valid(int r,int c,int n,int m)
{
	if(r>=0 && r<n && c>=0 && c<m && mat[r][c]!=-1)
		return true;
	return false;
}


int main() {
	int c=1;
	while(1){
		int n,m;
		s(n);
		s(m);
		if(n==0 && m==0)
			break;
		if(c!=1)
		cout<<endl;
		for(int i=0 ; i<n ; i++)
		{
			string s ;
			cin>>s;
			for(int j=0 ; j<m ; j ++)
			{
				if(s[j]=='.')
					mat[i][j] = 0;
				else
					mat[i][j] = -1;
			}
		}
	
		for(int i=0 ; i<n ; i++){
			for(int j=0 ; j<m ; j++)
			{
				if(mat[i][j]==-1){
					if(valid(i-1,j-1,n,m))
						mat[i-1][j-1]++;
					
					if(valid(i-1,j,n,m))
						mat[i-1][j]++;
				
					if(valid(i-1,j+1,n,m))
						mat[i-1][j+1]++;
				
					if(valid(i,j-1,n,m))
						mat[i][j-1]++;
						
				
					if(valid(i,j+1,n,m))
						mat[i][j+1]++;
				
				
					if(valid(i+1,j-1,n,m))
						mat[i+1][j-1]++;
				
					if(valid(i+1,j,n,m))
						mat[i+1][j]++;
					
					
					if(valid(i+1,j+1,n,m))
						mat[i+1][j+1]++;
				}
			}
		}
		cout<<"Field #"<<c<<":\n";
		c++;
		for(int i=0;i<n ; i++){
			for(int j=0 ; j<m ; j++)
				mat[i][j]==-1 ? cout<<'*'  :cout<<mat[i][j];
			cout<<endl;
		}
		
	//	cout<<"\n";
	}
	return 0 ;
}

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
#define FOR(a,b,it) for(it=a ; it<=b ; ++it)
#define pi pair<int,int> 

using namespace std ;

int main() {
	int N;
	s(N);
	int matrix[N][N];
	int i,j;
	FOR(0,N-1,i)
	FOR(0,N-1,j)
		s(matrix[i][j]);
	map<int , bool> row;
	map<int , bool> col;
	bool found ;
	int k=0;
	FOR(0,N-1,i){
		FOR(k,N-1,j){
			if(matrix[i][j]==0){
				row[i]=1,col[j]=1;
				k=j+1;
				break;
			}
		}
	}
	FOR(0,N-1,i)
		if(row[i]==1)
			FOR(0,N-1,j)
				matrix[i][j] = 0;
	FOR(0,N-1,i)
		if(col[i]==1)
			FOR(0,N-1,j)
				matrix[j][i] = 0;		
	FOR(0,N-1,i)	{
		FOR(0,N-1,j)
			cout<<matrix[i][j]<<" ";
		cout<<endl;
	}
 	return 0 ;
}

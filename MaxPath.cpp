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
#define val(mat,i,j,n) *(mat + ((i)*n)+(j))
using namespace std ;



int main() {
	int t ;
	s(t);
	while(t--){
		int n ;
		s(n);
		int mat[n][n] ;
		memset(mat,0,sizeof(mat));
	
		int i,j;
		FOR(0,n-1,i)
		FOR(0,i,j)
		s(mat[i][j]); 
		
		FOR(0,n-1,i){
			FOR(0,i,j)
				cout<<mat[i][j]<< " ";
			cout<<endl;
		}
		for(i=n-2 ; i>=0 ; i--)
		for(j=0 ; j<=i ; j++)
			mat[i][j]  +=  max(mat[i+1][j], mat[i+1][j+1]);
		p(mat[0][0]);
	//	cin>>n;
	}
	return 0 ;
}

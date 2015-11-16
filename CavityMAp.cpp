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

int main() {
	int n,i,j;
	s(n);
	char matrix[n][n];
	FOR(0,n-1,i){
		string str ;
		cin>>str;
		FOR(0,n-1,j)
			matrix[i][j] = str[j];
	}
	FOR(1,n-2,i){
		FOR(1,n-2,j){
			int temp =  matrix[i][j] - '0';
			if(matrix[i-1][j] - '0' < temp && matrix[i+1][j]-'0' <temp && matrix[i][j+1]-'0' < temp && matrix[i][j-1] -'0'<temp)
				matrix[i][j] = 'X';
		}
	}
	FOR(0,n-1,i){
		FOR(0,n-1,j)
			cout<<matrix[i][j];
		cout<<endl;
	}
	return 0 ;
}

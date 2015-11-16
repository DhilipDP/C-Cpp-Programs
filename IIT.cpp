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


#define ll long long
#define p(a) printf("%d\n",a)
#define s(a) scanf("%d",&a)
#define sll(a) scanf("%lld",&a)
#define sl(a) scanf("%ld",&a)
#define FOR(a,b) for(int i=a ; i<=b ; ++i)

using namespace std ;
int **mat;


bool possible(int t,int n,int cost){
	if(cost==t)
		return true ;
	for(int i=0 ; i<n ; i++)
		{
			
		}
}
int main() {
	int n;
	s(n);
	int t;
	s(t);
	*mat = new int[n] ;
	FOR(0,n-1)
		mat[i] = new int[n] ;
	int cost=0;
	if(possible(t,n,cost))
		cout<<"possible";
	else
		cout<<"not possible";
	return 0 ;
}

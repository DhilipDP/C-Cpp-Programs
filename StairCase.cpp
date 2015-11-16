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
	int t;
	s(t);
	while(t--){
	int n;
	s(n);
	int k;
	s(k);
	int p;
	s(p);
	int A[n],B[n],i;
	FOR(0,n-1,i)
		s(A[i]);
	FOR(0,n-1,i)
		s(B[i]);
	int X1[n],X2[n] ;
	X1[0] = A[0] ;
	X2[0] = B[0] ;
	FOR(1,n-1,i){
		int j=i-1;
		int val=k;
		int mini = INT_MAX;
		while(j>=0 && val--){
			mini = min(X1[j] + A[i],mini);
			j--;
		}
		j = i-1;
		val = k;
		while(j>=0 && val--){
			mini = min(X2[j] + p + A[i] ,mini);
		}
		X1[i] = mini ;
		j=i-1;
		val=k;
		mini = INT_MAX;
		while(j>=0 && val--){
			mini = min(X2[j] + B[i],mini);
			j--;
		}
		j = i-1;
		val = k;
		while(j>=0 && val--){
			mini = min(X1[j] + p + B[i] ,mini);
		}
		X2[i] = mini;
	}
	p(min(X1[n-1],X2[n-1]));
}
	return 0 ;
}

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
		int n,i;
		s(n);
		int arr[n+1];
		FOR(0,n,i)
			s(arr[i]);
		int T;
		s(T);
		ll int time = 0;
		int val = 0;
		FOR(0,n,i){
			time += arr[i] ;
			if(arr[i] == 60*(i+1) + val)
				time += 10;
			val += 10;
		}
		if(time <= T)
			printf("PC\n");
		else
			printf("PF\n");
	}
	return 0 ;
}

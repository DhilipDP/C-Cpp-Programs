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
		int n,m;
		s(n);
		s(m);
		int arr[n];
		int i;
		FOR(0,n-1,i)
			s(arr[i]);
		sort(arr,arr+n);
		n = n-m;
		int j;
		ll int s = 0;
		FOR(0,n-2,i){
			FOR(i+1,n-1,j){
				s += (arr[i] * arr[j]);
			}
		}
		printf("%lld\n",s);
	}
	return 0 ;
}

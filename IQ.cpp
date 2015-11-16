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
		int arr[n];
		int i;
		map<int ,int> m;
		FOR(0,n-1,i)
			s(arr[i]);
		FOR(0,n-1,i){
			int val;
			s(val);
			m[val]++;
		}
		int c =0;
		FOR(0,n-1,i){
			int pair = k - arr[i];
			if(m[pair]!=0){
				c+=m[pair];
			}
		}
		p(c);
	}
	return 0 ;
}

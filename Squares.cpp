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

int main() {
	int t;
	s(t);
	while(t--){
		int a,b;
		s(a);
		s(b);
		int count = 0;
		int val = sqrt(a);
		if(val * val == a)
			count++;
		val++;
		while(val*val <= b){
			count++;
			val++;
		}
		p(count);
		
	}
	return 0 ;
}

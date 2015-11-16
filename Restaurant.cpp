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
#define FOR(a,b) for(int i=a ; i<=b ; ++i)
#define pi pair<int,int> 

using namespace std ;


int gcd(int a,int b){
	if(a < b)
		return gcd(b,a);
	if(b==0)
		return a;
	return gcd(b,a%b);
}

int main() {
	int t;
	s(t);
	while(t--){
		int l,b;
		s(l);
		s(b);
		int val = gcd(l,b);
		p((l*b)/(val*val));
	}
	return 0 ;
}

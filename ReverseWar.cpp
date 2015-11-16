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


int reverse(int num){
	int n = 0;
	while(num > 0){
		n = n*10 + num%10;
		num/=10;
	}
	return n;
}
	
int main() {
	int t;
	s(t);
	while(t--){
		int n1,n2 ;
		s(n1);
		s(n2);
		p(reverse(reverse(n1)+reverse(n2)));
	}
	return 0 ;
}

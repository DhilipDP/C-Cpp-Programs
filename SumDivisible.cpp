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
	
	
	int n ;
	s(n);
	int k;
	s(k);
	int arr[n] ;
	FOR(0,n-1)
		s(arr[i]);
	map<int ,int > m;
	int s = 0;
	m[0] = 1 ;
	FOR(0,n-1){
		s = ((s +arr[i]) % k) ;
//		cout<<s<<" " ;
		m[s]++;
//		cout<<m[s]<<endl;
	}
	int count = 0;
	FOR(0,k-1){
		int val = m[i] ;
		//cout<<val<<endl;
		count += ((val*(val-1))/2) ;
	}
	p(count);
	return 0 ;
}


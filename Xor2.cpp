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
	int n;
	s(n);
	int arr[n];
	int i;
	FOR(0,n-1,i)
		s(arr[i]);
	int q;
	s(q);

	while(q--){
		char c;
		int l,r;
		cin>>c;
		if(c=='U'){
			int index,val ;
			s(index);
			s(val);
			arr[index-1] =  val;
		}
		else{
		s(l);
		s(r);
		int ans = 0;
		for(int i=l-1 ; i<=r-1 ; i++)
			ans ^= arr[i];
		p(ans);
		}
	}
	return 0 ;
}

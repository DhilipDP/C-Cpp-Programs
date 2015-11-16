#include <iostream>
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
		
		int a[n];
		int hash[103] = {0} ;
		int i;
		FOR(0,n-1,i){
			s(a[i]);
			hash[a[i]]++;
		}
	
		int o=0;
		FOR(0,100,i){
			if(hash[i] & 1)
				o++;
		}
		if(o==1 || o==0)
			cout<<"yes"<<endl;
		else
			cout<<"no"<<endl;
	}
	return 0 ;
}

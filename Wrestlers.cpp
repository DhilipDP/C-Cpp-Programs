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
#include<algorithm>
#include<map>


#define ll long long
#define p(a) printf("%d\n",a)
#define s(a) scanf("%d",&a)
#define sl(a) scanf("%lld",&a)
#define sll(a) scanf("%ld",&a)
#define FOR(a,b) for(int i=a ; i<=b ; ++i)

using namespace std ;

int main() {

	int n ;
	s(n);
	int last ;
	vector<int> first ;
	vector<int> second ;
	int fcount=0,scount=0;
	ll fsum =0,ssum=0;
	FOR(0,n-1){
		int f;
		s(f);
		if(f>0)
			first.push_back(f),fsum += f;
		else
			second.push_back(-f),ssum += (-f);
		if(i==n-1)
			last = f;
	}
	if(fsum!=ssum)
		fsum > ssum ? printf("first") : printf("second");
	else{
		if(lexicographical_compare(first.begin(),first.end(),second.begin(),second.end()))
			printf("second");	
		else if(lexicographical_compare(second.begin(),second.end(),first.begin(),first.end()))
			printf("first");	
		else
			last > 0 ? printf("first") : printf("second");
	}return 0 ;
}


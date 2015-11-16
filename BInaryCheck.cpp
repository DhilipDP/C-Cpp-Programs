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


int countSetBits(int n){
//	cout<<n<<endl;
	int c=0;
	while(n){
		n &= (n-1);
		c++;
	}
	return c;
}

int main() {
	int n,m,k;
	s(n);
	s(m);
	s(k);
	int x ;
	s(x);
	int c=0;
	FOR(0,m-1)
	{
		int val;
		s(val);
		if(countSetBits(val ^ x) <= k)
			c++;
	}
	p(c);
	return 0 ;
}

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


long long f(long long a) {
     long long res[] = {a,1,a+1,0};
     return res[a%4];
}

long long getXor(long long a, long long b) {
     return f(b)^f(a-1);
}

int main() {
	int n;
	s(n);
	int size = pow(2,(int)ceil(log2(n))+1)-1;
	segTree = new int[size];
	int arr[n];

	int i,j;
	FOR(0,n-1,i)
		cin>>arr[i];
//	createST(arr,0,n-1,0);
	int q;
	s(q);
//	for(int i=0 ; i<size ; i++)
//		cout<<segTree[i]<<" ";
	while(q--){
		char c;
		int l,r ;
		cin>>c;
		if(c=='A'){
		s(l);
		s(r);
		p(getMin(arr,l-1,r-1,0,n-1,0));
		}
		else{
			int ind,val;
			s(ind);
			s(val);
			updateValue(arr,n,ind-1,val);
			
		}
	}
	return 0 ;
}

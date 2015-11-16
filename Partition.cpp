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
	int n;
	s(n);
	int arr[n];
	FOR(0,n-1)
		s(arr[i]);
	int j=0,k=0;
	int lis1[n],lis2[n];
	FOR(1,n-1){
		if(arr[i] < arr[0] )
			lis1[j++] = arr[i] ;
		else
			lis2[k++] = arr[i] ;
	}
			
	FOR(0,j-1)
		cout<<lis1[i]<<" ";
	cout<<arr[0]<<" ";
	FOR(0,k-1)
		cout<<lis2[i]<<" ";
	
}

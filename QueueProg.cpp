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
	int arr[n];
	int a[n];
	int b[n];
	int start,end ;
	map<int ,int> ai;
	map<int ,int> bi;
	FOR(0,n-1){
		s(a[i]);
		s(b[i]);
		ai[a[i]] = b[i];
		bi[b[i]] = a[i] ;
		if(a[i]==0)
			start = b[i] ;
		if(b[i]==0)
			end = a[i] ;
	}	
	cout<<start<<" "<<end<<endl;
	int index = 1 ;
	arr[index] = start ;
	index+=2;
	while(true){
		int val = ai[start] ;
		if(val==0)
			break;
		arr[index] = val;
		start = val;
		index += 2; 
	}
	
	index = n-2;
	arr[index] = end;
	index -= 2;
	while(true){
		int val = bi[end];
		if(val==0)
			break;
		arr[index] = val;
		end = val;
		index -= 2;
	}
	for(int i=0 ; i<n; i++)
		printf("%d ",arr[i]);
	printf("\n");
	return 0 ;
}

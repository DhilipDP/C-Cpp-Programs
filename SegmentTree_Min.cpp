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



int createST(int arr[],int start,int end,int index,int segTree[]){
	if(start == end){
		//	cout<<"["<<index<<"]"<< " " << arr[start]<<endl;
		segTree[index] = arr[start];
		return arr[start];
	}
	int mid = (start+end)/2;
	segTree[index] = min(createST(arr,start,mid,index*2+1,segTree),createST(arr,mid+1,end,index*2+2,segTree));
	return segTree[index];
}

int getMin(int arr[],int l,int r,int start,int end,int index,int segTree[]){
	if(l > end || r < start)
		return INT_MAX;
	if(l<=start && r>=end )
		return segTree[index];
	int mid = (start+end)/2;
	return min(getMin(arr,l,r,start,mid,index*2+1,segTree),getMin(arr,l,r,mid+1,end,index*2+2,segTree));
}


int main() {
	int t;
	s(t);
	while(t--){
	int n;
	s(n);
	int size = pow(2,(int)ceil(log2(n))+1)-1;
	int * segTree1 = new int[size];
	int * segTree2 = new int[size];
	int arr1[n],arr2[n];
	int i;

	FOR(0,n-1,i)
		s(arr1[i]);
	FOR(0,n-1,i)
		s(arr2[i]);
		
	createST(arr1,0,n-1,0,segTree1);
	createST(arr2,0,n-1,0,segTree2);
	int val = INT_MIN ;
	for(int i=0 ; i<n ; i++)
	{
		for(int j=0 ; j<n ; j++){
			int min1 = getMin(arr1,i,j,0,n-1,0,segTree1);
			int min2 = getMin(arr2,i,j,0,n-1,0,segTree2);
			int num = j-i+1;
			int m = min(min1,min2);
			val = max(val,m*num);
		//	cout<<val<<endl;
			
		}
	}
	p(val);
	}	
	return 0 ;
}

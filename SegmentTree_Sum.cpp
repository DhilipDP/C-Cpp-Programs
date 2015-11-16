#include<iostream>
#include<math.h>
using namespace std ;



int constructST(int st[],int start,int end,int arr[],int index){
	if(start==end){
		st[index] = arr[start];
		return arr[start];
	}
	int mid = (start+end)/2;
	st[index] = constructST(st,start,mid,arr,index*2+1) + constructST(st,mid+1,end,arr,index*2+2);
	return st[index];
}

int getSum(int arr[],int l,int r,int st[],int start,int end,int index){
	if(l > end || r < start)
		return 0;
	if(l <= start && r>=end)
		return st[index];
	int mid = (start+end)/2;
return  getSum(arr,l,r,st,start,mid,index*2+1) + getSum(arr,l,r,st,mid+1,end,index*2+2);

}

int main(){
	int arr[] ={2,5,4,3,10};
	int n = sizeof(arr)/sizeof(arr[0]);
	int height = ceil(log2(n));
	int num = pow(2,height+1)-1;
	int segment_tree[num];
	constructST(segment_tree,0,n-1,arr,0);
	cout<<getSum(arr,0,4,segment_tree,0,n-1,0);
}

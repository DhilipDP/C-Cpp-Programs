#include<iostream>

using namespace std ;

int findPivot(int arr[],int low,int high){
		if(high < low)
			return -1;
		if(high == low)
			return arr[low];
		int mid = (low + high)/2;
		if(mid < high && arr[mid] > arr[mid+1])
			return mid ;
		if(mid > low && arr[mid-1] > arr[mid])
			return mid-1;
		if(arr[mid] > arr[low])
			return findPivot(arr,mid+1,high);
		return findPivot(arr,low,mid);
}


int binarySearch(int arr[],int low,int high,int key){
	if(high < low)
		return -1 ;
	int mid = (low + high)/2;
	if(arr[mid]==key)
		return mid ;
	if(arr[mid] > key)
		return binarySearch(arr,0,mid-1,key);
	return binarySearch(arr,mid+1,high,key);
	}
void pivotedSearch(int arr[],int n,int key){
	int pivot = findPivot(arr,0,n-1);
	if(pivot==-1){
		cout<<binarySearch(arr,0,n-1,key);
		return ;
	}
	if(arr[0] > key)
		cout<<binarySearch(arr,pivot+1,n-1,key);
	else
		cout<<binarySearch(arr,0,pivot,key);
	
}
int main(){
	int arr[] = {2,3,4,5,1};
	int n = sizeof(arr)/sizeof(arr[0]);
	pivotedSearch(arr,n,3);
}

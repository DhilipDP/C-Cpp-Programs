#include<iostream>
using namespace std ;


int findPivot(int arr[],int low,int high){
	int pivot=-1;
	for(int i=low ; i<high ; i++){
		if(arr[i] > arr[i+1])
			pivot = i;
	}
	return pivot ;

}


bool binarySearch(int A[],int low,int high,int target){
	if(low > high)
		return false;
	int mid = (low + high)/2;
	if(A[mid] == target)
		return true;
	if(A[mid] > target)
		return binarySearch(A,low,mid-1,target);
	else
		return binarySearch(A,mid+1,high,target);
		
}
bool search(int A[] ,int n,int target){
	int pivot = findPivot(A,0,n-1);
	if(n==0)
		return false;
	if(pivot==-1)
		return binarySearch(A,0,n-1,target);
	if(A[pivot]==target)
		return true;
	if(A[0] <= target)
	{
		return 	binarySearch(A,0,pivot,target);
	}
	else{
		return binarySearch(A,pivot+1,n-1,target);
	}
}
int main(){

	int arr[] = {3,4,5,1,2};
	cout<<search(arr,5,3);
}

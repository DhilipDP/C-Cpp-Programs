#include<iostream>

using namespace std ;


 int binarySearch(int arr[],int low,int high,int key){
 	if(high < low)
 		return low ;
 	if(low==high){
 		if(arr[low]==key)
 			return low ;
 		if(key < arr[low])
		 	return  low; 
		else
			return high + 1 ;
	}
	
	int mid = (low+high)/2 ;
	if(arr[mid]==key)
		return mid ;
	if(arr[mid] < key)
		return binarySearch(arr,mid+1,high,key);
	return binarySearch(arr,low,mid-1,key);
 }
 int searchInsert(int A[], int n, int target) {
    	return binarySearch(A,0,n-1,target);
	    
	}

int main() {
	int arr[] = {3,5,7,9,10};
	int n = sizeof(arr)/sizeof(arr[0]) ;
	cout<<searchInsert(arr,n,8);
}




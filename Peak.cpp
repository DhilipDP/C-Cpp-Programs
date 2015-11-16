#include<iostream>

using namespace std;


int findPeak(int arr[],int low,int high,int n){
	if(low <= high){
		int mid = (low + high)/2;
		if((mid == 0 || (arr[mid] > arr[mid-1])) && (mid==n-1 || (arr[mid] > arr[mid+1])) )
			return mid;
		if(mid > 0 && (arr[mid-1] > arr[mid]))
			return findPeak(arr,low,mid-1,n);
		else
			return findPeak(arr,mid+1,high,n);
	}
}
int main(){
	int n;
	cout<<"Enter number of elements: ";
	cin>>n;
		int i,arr[100];
	cout<<"Enter elements";
	for(i=0 ; i<n ;i++)
		cin>>arr[i];
	cout<<"Peak: "<<arr[findPeak(arr,0,n-1,n)];
}

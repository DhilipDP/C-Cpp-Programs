#include<iostream>

using namespace std;

int mini(int a,int b)
{
	return a<b ? a : b;
}


int findMin(int arr[],int low,int high){

	if(high < low)
		return arr[0];
	if(high==low)
		return arr[low];
	int mid = (low + high)/2;
	if(mid>high &&  arr[mid+1] < arr[mid])
		return arr[mid+1];
	if( mmid < low && arr[mid] < arr[mid-1])
		return arr[mid];
	 if (arr[low]==arr[mid] && arr[high]==arr[mid]){	 
	 	cout<<"Finding min among: "<<low<<" - "<<mid-1<<" & "<<mid+1<<" - "<<high;
		return mini(findMin(arr,low,mid-1),findMin(arr,mid+1,high));
	}
	if(arr[high] > arr[mid])
		return findMin(arr,low,mid-1);
	return findMin(arr,mid+1,high);
}

int main(){
	int n;
	cout<<"Enter number of elements: ";
	cin>>n;//"
	int i,arr[100];
	cout<<"Enter a rotated sorted array:\n";
	for(i=0 ; i<n ;i++)
		cin>>arr[i];
	cout<<"Minimum: "<<findMin(arr,0,n-1);
	return 0;
}

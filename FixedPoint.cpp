#include<iostream>

using namespace std;


int findFixedPoint(int arr[],int low,int high)
{
	if(low<=high){
		int mid = (low + high)/2;
		if(arr[mid]==mid)
			return mid;
		if(arr[mid] > mid)
			return findFixedPoint(arr,low,mid-1);
		return findFixedPoint(arr,mid+1,high);
	}
	return -1;
}
int main()
{
	char b[1000000];
	int n,i,arr[100];
	cout<<"Number of elemets";
	cin>>n;
	cout<<"Elements: ";
	for(i=0 ; i<n ; i++)
	{
		cin>>arr[i];
	}	
	cout<<"Fixed Point: "<<findFixedPoint(arr,0,n-1);
}

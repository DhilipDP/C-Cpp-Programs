#include<iostream>

using namespace std;


int Count(int arr[],int low,int high){
	if(low > high)
		return -1;
	int mid = (low + high)/2;
	if(mid==0 || (arr[mid-1]==1) && arr[mid]==0)
		return mid;
	if(arr[mid]==0)
		return Count(arr,low,mid-1);
	return Count(arr,mid,high-1);
}

int main()
{
	int n;
	cout<<"Enter number of elements: ";
	cin>>n;//"
	int i,arr[100];
	cout<<"Enter a sequence of 1's followed by 0's";
	for(i=0 ; i<n ;i++)
		cin>>arr[i];
	int first_index = Count(arr,0,n-1);
	if(first_index==0 && arr[0]==1)
		cout<<0;
	else
		cout<<"Number of Zeroes: "<<n-first_index;
}



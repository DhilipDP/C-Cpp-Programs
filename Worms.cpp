#include<iostream>
using namespace std;

int search(int val,int *arr,int low,int high){

	if(low <= high){
	
		int mid = (low+high)/2;
		if(val == arr[mid])
			return mid;
		if(val < arr[mid] && mid > low && val > arr[mid-1])
			return mid;
		if(val > arr[mid] && mid < high && val <= arr[mid+1] )
			return mid+1;
		if(val < arr[mid])
			return (search(val,arr,low,mid-1));
		return search(val,arr,mid+1,high);
	}

}

int main(){

	int n;
	cin>>n;
	int arr[n];
	int sum=0;
	for(int i =0 ;i<n ; i++){
		int val ;
		cin>>val;
		sum+=val;
		arr[i] = sum;
	
	}
	int m;
	cin>>m;
	while(m--)
	{
		int p;
		cin>>p;
		int index  =search(p,arr,0,n-1);
		cout<<index+1<<endl;
		
		
	
	}

}

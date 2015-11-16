#include<iostream>

using namespace std ;


int merge(int arr[],int temp[],int left,int mid,int right){
	int i = left ;
	int k = left ;
	int j = mid+1;
	int inv = 0;
	while(i<=mid && j<=right){
		if(arr[i] < arr[j])
			temp[k++] = arr[i++];
		else{
			temp[k++] = arr[j++];
			inv += mid+1-i;
		}
	}
	while(i<=mid)
		temp[k++] = arr[i++];
	while(j<=right)
		temp[k++] = arr[j++];
	for(i=left ; i<=right ; i++)
		arr[i] = temp[i];
	return inv ; 
}

int  merge_sort(int arr[],int temp[],int p,int r){
	int inv = 0;
	if(p<r){
		int q = (p+r)/2 ;
		inv += merge_sort(arr,temp,p,q);
		inv += merge_sort(arr,temp,q+1,r);
		inv += merge(arr,temp,p,q,r);
	}
	return inv ;
}
void merge_sort(int arr[],int n){
	int *temp = new int[n];
	cout<<merge_sort(arr,temp,0,n-1)<<endl;	
}

int main(){
	int arr[] = {2,4,1,3,5};
	int n = sizeof(arr)/sizeof(arr[0]);
	merge_sort(arr,n);
	for(int i=0 ; i<n ; i++)
		cout<<arr[i]<<" ";
}

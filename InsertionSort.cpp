#include<iostream>
using namespace std ;



void swap(int &a,int &b){
	int temp = a ;
	a= b;
	b=temp;
}


void print(int arr[],int n){
		for(int i=0 ; i<n ; i++)
		cout<<arr[i]<<" ";
	cout<<endl;
}
void insertion_sort(int arr[] ,int n){
	
	int i , j;
	for(j=1 ; j<n ; j++){
	
		for(i=0 ; i<=j-1  ; i++){
			if(arr[i] > arr[j] )
				swap(arr[i],arr[j]);
		}
		print(arr,n);
	}
	

	
}
int main(){
	int arr[] = {1,4,3,5,6,2} ;
	int n = sizeof(arr)/sizeof(arr[0]);
	insertion_sort(arr,n);
}

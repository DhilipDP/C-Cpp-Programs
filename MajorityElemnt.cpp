#include<iostream>

using namespace std ;


int findMajority(int *arr,int n){
	int count = 1,maj_index = 0;
	for(int i=1 ; i<n ; i++){
		if(arr[i]==arr[maj_index])
			count++;
		else
			count--;
		if(count==0){
			count++;
			maj_index = i;
		}
	}
	return arr[maj_index];
}
int main(){
	int arr[]= {2,2,3,4,2};
	int n= sizeof(arr)/sizeof(arr[0]);
	cout<<findMajority(arr,n);
}

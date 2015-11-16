#include<iostream>
using namespace std ;


int solve(int arr[],int n,int x){
	int result = 0;
	for(int i=0 ; i<n ; i++){
		result = result*x + arr[i] ;
	}
	return result ;
}
int main(){
	int arr[] = {1,2,2,1};
	int n=sizeof(arr)/sizeof(arr[0]);
	int x = 2 ;
	cout<<solve(arr,n,x);
}

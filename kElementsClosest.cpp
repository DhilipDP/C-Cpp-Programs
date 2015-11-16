#include<iostream>
#include<stdio.h>
using namespace std ;
 //k closest elements in a sorted  array
 
 
 int findCrossOver(int *arr ,int low,int high ,int x){
 	if(arr[high] <= x)	
 		return high;
 	if(arr[low] > x)
 		return low;
 	int mid = (low + high)/2;
 	if(arr[mid] <= x && arr[mid+1] >x)
 		return mid;
 	if(x < arr[mid])
 		return findCrossOver(arr,low,mid-1,x);
 	return findCrossOver(arr,mid+1,high,x);
 } 
 
 void printClosest(int *arr,int n,int k,int x)
 {
 	int l , r,count=0;
	int crossOver = 	findCrossOver(arr,0,n-1,x);
	l = crossOver ;
	r = crossOver+1;
	if(arr[crossOver]==x)
		l=crossOver-1;
	while(count < k && l>=0 && r<n){
		if(x-arr[l] < arr[r]-x)
			cout<<arr[l--]<<" ";
		else if(x)
			cout<<arr[r++]<<" ";
		count ++;
	}
	while(count < k && l>=0){
		cout<<arr[l--]<<" ";
		count ++;
	}
	while(count < k && r<n){
		cout<<arr[r++]<<" ";
		count++;
	}
 }
 int main(){
 	printf("%d",3-7%3);
 	//sorted array
 	int arr[] = {12, 16, 22, 30, 35, 39, 42,45, 48, 50, 53, 55, 56};
 	int n = sizeof(arr)/sizeof(arr[0]);
 	int k=5;
 	int x = 35 ;
 	printClosest(arr,n,k,x);
 }
 
 
 

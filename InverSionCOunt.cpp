#include<iostream>
#include<stdio.h>
using namespace std;

long long int merge(int arr[],int temp[],int left,int mid,int right){
	int i = left;
	int j = mid ;
	int k = left ;
	long long int inv = 0;
	while(i<=mid-1 && j<=right){
		if(arr[i]<=arr[j])
			temp[k++]=arr[i++];
		else{
			temp[k++]=arr[j++];
			inv += (mid-i);
		}
	}
	while(i<=mid-1)
		temp[k++]=arr[i++];
	while(j<=right)
		temp[k++]=arr[j++];
	for(int l = left ; l<=right ; l++)
		arr[l] = temp[l];
	return inv;
}
long long int mergeSort(int arr[],int temp[],int left,int right){
	long long int incount = 0;
	if(left < right){
		int mid =(left+right)/2;
		incount = mergeSort(arr,temp,left,mid);
		incount += mergeSort(arr,temp,mid+1,right);
		incount += merge(arr,temp,left,mid+1,right);
	}
	return incount;
}
long long int mergeS(int arr[],int n){
	int *temp = new int[n];
	return mergeSort(arr,temp,0,n-1);
}


int main(){
	int  tests;
	scanf("%d",&tests);
	while(tests--){
		int n;
		scanf("%d",&n);
		int *arr = new  int[n];
		for(int i=0 ; i<n ; i++)
			scanf("%d",&arr[i]);
		printf("%lld\n",	mergeS(arr,n));
	}
}

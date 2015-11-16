 #include<iostream>
#include<stdlib.h>
using namespace std;

void swap(int *x,int *y){
	int temp = *x ;
	*x = *y;
	*y = temp;
}

int Partition(int *arr,int l ,int r){
	int p = rand()%(r-l+1) + l;
	int pivot = arr[p];
	swap(&arr[l],&arr[p]);
	int i=l+1,j;
	for(j=l+1 ; j<=r ; j++){
		if(arr[j] < pivot)
			{
	//			cout<<"swapping :"<<arr[i]<<" and "<<arr[j]<<endl;
				swap(&arr[i],&arr[j]);
				i++;
			}		
	}
	//cout<<"swapping :"<<arr[i-1]<<" and "<<arr[l]<<endl;
	swap(&arr[i-1],&arr[l]);
	return i-1;
	
}

void QuickSort(int *arr,int p,int r){
	if(p<r){
		int q = Partition(arr,p,r);
		QuickSort(arr,p,q);
		QuickSort(arr,q+1,r);
	}	
}
int main(){
	int arr[] = {3,8,2,5,1,4,7,6};
	int n = sizeof(arr)/sizeof(int);
	QuickSort(arr,0,n-1);
	cout<<endl<<endl;
	for(int i=0 ; i<n ; i++)
		cout<<arr[i]<<" ";
}

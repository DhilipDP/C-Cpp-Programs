#include<iostream>

using namespace std;



void LIS(int arr[],int n){

	int lis[n];
	int i,j;
	
	for(i=0 ; i<n ; i++)
		lis[i]=1;

	int maxi = 1;
	int maxi_index=0;
	for(i=1 ; i<n ; i++){
		for(j=0 ; j<i ; j++){
			if(arr[i] > arr[j] && lis[i] < lis[j]+1){
				lis[i] = lis[j]+1;
				if(lis[i] > maxi)
					maxi = lis[i],maxi_index=i;;			
			}
		}
		
	}
	
	for(i=0 ; i<n ; i++){
		cout<<lis[i]<<" ";
	}
	cout<<endl;
	cout<<"Length of the longest increasing sequence is:"<<maxi<<endl;
	cout<<"LIS is: "<<endl;
	int cur_max =maxi-1 ;
	int l[maxi];
	int k=maxi-1;
	l[k--] = arr[maxi_index];
	for(i=maxi_index-1 ; i>=0 ; i--){
		if(lis[i] == cur_max)
			 l[k--] = arr[i],cur_max--;
	}
	for(i=0 ; i<maxi ;i++)
		cout<<l[i]<<" ";
}
int main(){

	int arr[]={1,6,3,4,2,4};
	int n = sizeof(arr)/sizeof(arr[0]);
	LIS(arr,n);
}

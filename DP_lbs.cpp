#include<iostream>

using namespace std ;



int LBS(int arr[],int n){
	int lis[n];
	int i ,j ;
	for(i=0 ; i<n ; i++)
		lis[i] = 1 ;
	for(i=1 ; i<n ; i++){
		for(j=0 ; j<i  ; j++){
			if(arr[i] > arr[j] && lis[i] < lis[j] + 1)
				lis[i] = lis[j] + 1;
		}
	}
	
	int lds[n] ;
	for(i=0 ; i<n ; i++)
		lds[i] = 1;
	for(i=n-2 ; i>=0  ; i--){
		for(j=n-1 ; j>i ; j--){
			if(arr[i] > arr[j] && lds[i] < lds[j] + 1)
				lds[i] = lds[j] +1 ;
		}
	}
	
	cout<<"LIS: \n";
	for(i=0 ; i<n ; i++)
		cout<<lis[i]<<" " ;
	cout<<endl<<"LDS :"<<endl;
	for(i=0 ; i<n ; i++)
		cout<<lds[i]<<" " ;
	cout<<endl;
	int maxi = lis[0] + lds[0]  - 1 ;
	int index=0 ; 
	for(i=1 ; i<n ; i++){
		if(lis[i] + lds[i] - 1 > maxi)
			maxi = lis[i] + lds[i] -1,index = i ;
	}
	cout<<index<<endl;
	int ans[maxi],k=lis[index]-1;
	int cur = lis[index];
	for(i=index ; i>=0 ; i--){
			if(cur==lis[i])
			{
				ans[k--] = arr[i];
				cur--;
			}
	}
	k = lis[index] ;
	cur = lds[index]-1;
	for(i=index+1 ; i<n ; i++){
		if(cur==lds[i]){
			ans[k++] = arr[i];
			cur--;
		}
	}
	
	cout<<"LBS is: "<<endl;
	for(i=0 ; i<k ; i++)
		cout<<ans[i]<<" ";
	cout<<endl; 
	return maxi;

}

int main(){

	int arr[] = {0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15};
	int n = sizeof(arr)/sizeof(arr[0]);
	cout<<endl<<LBS(arr,n);
}

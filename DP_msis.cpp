#include<iostream>

using namespace std ;



int maxSum(int arr[] , int n){
	
	int dp[n];
	int i,j;
	for(i=0 ; i<n ; i++)
		dp[i] = arr[i];
	for(i=1 ; i<n ; i++){
		for(j=0 ; j<i  ; j++){
			if(arr[j] < arr[i] &&  dp[j] + arr[i] > dp[i])
				dp[i] = arr[i] + dp[j];
		
		}
	}
	int maxi = dp[0],max_index=0;
	for(i  = 1 ; i<n  ; i++){
	//	cout<<dp[i]<<endl;
		if(dp[i] > maxi)
			maxi = dp[i],max_index=i;
	}
	int cur = maxi ;
	int ans[maxi] , k=0 ;
	for(i=max_index ; i>=0 ; i--){
		if(dp[i] == cur){
			ans[k++]  =  arr[i] ;
			cur = cur - arr[i];
		}
	}
	
	cout<<endl<<"Sequence : "<<endl;
	for(i=k-1 ; i>=0 ; i--)
		cout<<ans[i]<<" ";
	cout<<endl;
	return maxi;
}
int main(){
	int arr[] = {1,101,2,3,100,4,5};
	int n = sizeof(arr)/sizeof(arr[0]);
	cout<<endl<<maxSum(arr,n);

}

#include<iostream>
#include<limits.h>
using namespace std ;



int coin(int arr[],int m,int n){

	int tab[n+1][m+1];
	int i,j;
	for(i=0 ; i<=n ; i++){
		for(j=0 ; j<=m ; j++){
			if(i==0)
				tab[i][j] = 1;
			else if(j==0)
				tab[i][j] = 0;
			else if(arr[j-1]  > i)
				tab[i][j] = tab[i][j-1];
			else
				tab[i][j] = tab[i-arr[j-1]][j] + tab[i][j-1];	
		}
		
	
	}
	for(i=0 ; i<=n ; i++){
		for(j=0 ; j<=m ; j++)
			cout<<tab[i][j]<<" ";
		cout<<endl;
	}
	return  tab[n][m-1];

}

int Coin(int arr[],int n,int sum){
	if(sum <  0)
		return INT_MAX ;
	if(sum == 0)
		return 0;
	int mini = INT_MAX ;
	for(int x = 0 ; x<n ; x++)
		if(sum >= arr[x])
			mini = 1+min(mini,Coin(arr,n,sum-arr[x]));
	return mini ;
}

int minCoin(int arr[],int n ,int sum)
{
	cout<<Coin(arr,n,sum)<<endl;
	int C[sum+1];
	C[0] = 0;
	for(int i=1 ; i<=sum ; i++){
		int mini = INT_MAX ;
		for(int j = 0 ; j<n ; j++){
			if(i >= arr[j])
				mini =1+ min(mini,C[i-arr[j]]);
		}
		C[i] = mini ;
		cout<<C[i]<<" ";
	}
	return C[sum];
}
int main(){
	int arr[] = {1,5,10,25};
	int n = sizeof(arr)/sizeof(arr[0]);
	cout<<coin(arr,n,37);
	cout<<endl<<minCoin(arr,n,37);

}

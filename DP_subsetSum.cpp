#include<iostream>

using namespace std ;



bool subset(int arr[],int n,int sum){
	if(sum == 0)
		return true ;
	if(n==0)
		return false ;
	if(arr[n-1] > sum)
		return subset(arr,n-1,sum) ;
	return subset(arr,n-1,sum) || subset(arr,n-1,sum-arr[n-1]);	
}

bool subsetDP(int arr[] ,int n ,int sum){
	bool tab[sum+1][n+1] ;
	int i,j ;
	for(i=0 ; i<=n ; i++)
		tab[0][i] = true;
	for(i=1 ; i<=sum ; i++)
		tab[i][0] = false ;
	for(i=1 ; i<=sum ; i++){
		for(j=1 ; j<=n ; j++){
			if(arr[j-1] > i)
				tab[i][j] = tab[i][j-1];
			else
				tab[i][j] = tab[i][j-1] || tab[i-arr[j-1]][j-1] ;
		}
	}
	
	for(i=0 ; i<=sum ; i++){
		for(j=0 ; j<=n ; j++)
			cout<<tab[i][j]<<" ";
		cout<<endl;
	}
	if(tab[sum][n]){
		int r = sum,l=n ;
		while(r!=0 && l!=0){
			for(i=l ;   tab[r][i]!=0 ; i--);
			cout<<arr[i]<<endl;
			r = r - arr[i] ;
			l -- ;
			
		}
	}
	return tab[sum][n];
}
int main()
{
	int arr[] = {1,2,3};
	int n = sizeof(arr)/sizeof(arr[0]);
	cout<<subset(arr,n,6)<<endl;
	cout<<subsetDP(arr,n,6);
}

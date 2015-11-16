#include<iostream>
#include<limits.h>
using namespace std ;


int llap(int *arr,int n){
	int L[n][n] ;
	memset(L,0,sizeof(L));
	int i,j,k ;
	for(i=0 ; i<n ; i++)
		L[i][n-1] = 2 ;
	int lap = 2 ;
	for(j=n-2 ; j>=1 ; j--){
		
		i=j-1 ;
		k=j+1 ;
		while(i>=0 && k<n){
			if(arr[i] + arr[k] < 2*arr[j])
				k++;
			else if(arr[i] + arr[k] > 2*arr[j])
				L[i][j] = 2,i--;
			else{
				L[i][j] = L[j][k] + 1;
				if(L[i][j] > lap)
					lap = L[i][j] ;
				i--,k++;
			}
		}
		
		while(i>=0){
			L[i][j] = 2 ;
			i--;
		} 
	}
	
	for(i=0 ; i<n ;i++){
		for(j=0 ; j<n ; j++)
			cout<<L[i][j]<< " ";
		cout<<endl;
	
	}
	 return lap;
	}


int  main() {
	int arr[] = {1,7,10,15,29} ;
	int n = sizeof(arr)/sizeof(arr[0]);
	cout<<llap(arr,n);

}

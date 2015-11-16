#include<iostream>
#include<limits.h>
using namespace std ;


// matrix chain multiplication



int matchain(int p[],int i,int j){
	if(i==j)
		return 0;
	int k,count;
	int min = INT_MAX;
	for(k=i ; k<j ; k++){
		count = matchain(p,i,k) + matchain(p,k+1,j) + (p[i-1] * p[k] * p[j]);
		if(count < min)
			min = count;
	
	}
	return min;
	
}


int matOrder(int p[],int n){
	int mat[n][n];
	int L,i,j,k,q;
	for(i=0 ; i<n ; i++)
		mat[i][i] = 0;
	for(L=2 ; L<n ; L++){
		for(i=0 ; i<=n-L ; i++){
			j = i+L-1;
			mat[i][j] = INT_MAX;
			for(k=i ; k<j ; k++){
				q = mat[i][k] + mat[k+1][j] + p[i-1] * p[k] * p[j];
				if(q < mat[i][j])
					mat[i][j] = q;
			
			}
		
		}
	
	}
	return mat[1][n-1];
	

}
int main(){
	int arr[] = {18,19};
	int n = sizeof(arr)/sizeof(arr[0]);
	cout<<"Recursive solution:" <<matchain(arr,1,n-1)<<endl;
	cout<<"DP: "<<matOrder(arr,n);

}

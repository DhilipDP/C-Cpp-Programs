#include<iostream>
using namespace std ;


bool isBalanced(int arr[],int n){
	int i;
	int sum = 0;
	for(i=0 ; i<n ; i++)
		sum += arr[i];
	bool part[(sum)/2 + 1][n+1];
	int j;
	for(i=0 ; i<=n ; i++)
		part[0][i] = true ;
	for(i=1 ; i<=(sum)/2 ; i++)
		part[i][0] = false ;
	for(i=1 ; i<=(sum)/2 ; i++){
		for(j=1 ; j<=n ; j++){
			if(i < arr[j-1])
				part[i][j] = part[i][j-1] ;
			else
				part[i][j] = part[i][j-1] || part[i-arr[j-1]][j-1];
		}
	}
	//table
	/*for(i=0 ; i<=(sum)/2 ; i++)
	{
		for(j=0 ; j<=n ; j++)
			cout<<part[i][j]<<"  ";
		cout<<endl;
	} */
	return part[(sum)/2][n];
}

int main(){
	int arr[] = {1,2,3,6,8,9,10};
	int n =  sizeof(arr)/sizeof(arr[0]);
	if(isBalanced(arr,n)){
		cout<<"Yes";
		
	}
	else
		cout<<"No";
}

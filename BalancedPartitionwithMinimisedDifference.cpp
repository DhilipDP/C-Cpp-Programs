#include<iostream>
using namespace std ;


void findBalanced(int arr[],int n){
	int sum = 0;
	int i,j;
	for(i=0 ; i<n ; i++)
		sum += arr[i];
	int ROW,COL ;
	ROW = (sum+1)/2 ;
	COL = n ;
	bool part[ROW+1][COL+1];
	for(i=0 ; i<=COL ; i++)
		part[0][i] = true ;
	for(i=1 ; i<=ROW ; i++)
		part[i][0] = false ;
	for(i=1 ; i<=ROW ; i++){
		for(j=1 ; j<=COL ; j++){
			if(i < arr[j-1])
				part[i][j] = part[i][j-1] ;
			else
				part[i][j] = part[i][j-1] || part[i-arr[j-1]][j-1];
		}
	}
	//table
/*	for(i=0 ; i<=ROW ; i++)
	{
		for(j=0 ; j<=COL ; j++)
			cout<<part[i][j]<<"  ";
		cout<<endl;
	}
	 */
	int s=0;
	int subset[COL];
	int b[COL];
	memset(b,0,sizeof(b));
	int k,l=COL;
	for(k=ROW ; part[k][l]!=1 ; k--);
	while(k!=0 && l!=0){
		int t ;
		for(t=l ; part[k][t] !=0 ; t--);
		subset[s++] = arr[t];
		b[t] =1 ;
		k = k - arr[t];
		l--;
	}
	cout<<"Subset 1: "<<endl;
	for(i=0 ; i<s ; i++)
		cout<<subset[i] <<" ";
	cout<<"\nSubset 2 :"<<endl;
	if(s==n)
		cout<<"NIL"<<endl;
	else{
	for(i=0 ; i<n ; i++)
		if(!b[i])
			cout<<arr[i]<<" ";
	cout<<endl;
	}
}

int main(){
	int arr[] = {10,200,20,100};
	int n =  sizeof(arr)/sizeof(arr[0]);
	findBalanced(arr,n);
}

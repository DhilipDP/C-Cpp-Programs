#include<iostream>
#include<limits.h>
using namespace std ;


int summation(int arr[],int st,int end){
	int s = 0;
	for(int i=st ; i<=end ; i++)
		s+=arr[i];
	return s ;
}
int optimalCost(int freq[],int i,int j){
	if(j < i)
		return 0;
	if(j==i)
		return freq[i] ;
	int sum = summation(freq,i,j);
	int r ,c;
	int mini = INT_MAX ;
	for(r = i; r<=j ; r++){
		c = optimalCost(freq,i,r-1) + optimalCost(freq,r+1,j);
		cout<<"c : "<<c<<endl;
		if(c < mini)
			mini = c;
	}
	cout<<"i: "<<i<<" j: "<<j<<" "<<mini<<" "<<sum<<endl;
	return mini+sum ;
}


int OC(int *freq,int n ){
	int oc[n][n] ;
	int i,j,k,r;
	for(i=0 ; i<n ; i++)
		oc[i][i] = freq[i] ;
	for(k=2 ; k<=n ; k++){
		for(i=0 ; i<=n-k ; i++){
			j =  i+k-1 ;
			oc[i][j] = INT_MAX ;
			for(r=i ; r<=j ; r++ ){
				int c = ((i <= r-1) ? oc[i][r-1] : 0) + (r+1 <= j ? oc[r+1][j] : 0)+ summation(freq,i,j);
				if(c < oc[i][j])
					oc[i][j] = c;
			}
		}
	}
	return oc[0][n-1] ;
}
int main(){

	int keys[] = {10,12,20};
	int freq[] = {34,8,50};
	int n = sizeof(keys)/sizeof(keys[0]);
	cout<<optimalCost(freq,0,n-1) ;
	
	cout<<endl<<OC(freq,n);
}

#include<iostream>
#include<vector>
#include<stdio.h>
#include<stack>
#include<vector>
#include<queue>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<limits.h>
#include<map>
#include<algorithm>


#define ll long long
#define p(a) printf("%d\n",a)
#define s(a) scanf("%d",&a)
#define sl(a) scanf("%lld",&a)
#define sll(a) scanf("%ld",&a)
#define FOR(a,b) for(int i=a ; i<=b ; ++i)

using namespace std ;




int sum(int arr[] ,int st,int end){
	int i;
	int sum=0;
	for(i=st ; i<=end ; i++)
		sum = (sum +arr[i])%100;
	return sum ;
}
int minValue(int arr[],int i,int j){
	if(i==j)
		return 0;
	int q=0;
	int mini = INT_MAX ;
	int k;
	for(k=i ; k<j ; k++){
		int smoke = arr[i-1]*arr[k];
		q = minValue(arr,i,k) + minValue(arr,k+1,j) + sum(arr,i,k) * sum(arr,k+1,j) ;
		if(q < mini)
			mini = q;
	}
	return mini ;
}



int minvalue(int arr[],int n){

	int sum[n][n] ;
	int i,j,k,l ;
	for(i=0 ; i<n ; i++){
		for(j=i ; j<n ; j++)
		{
			if(i==j)
				sum[i][i] = arr[i] ;
			else
				sum[i][j] = (sum[i][j-1] + arr[j])%100;
		}
	}
	int tab[n][n] ;
	for(i=0 ; i<n ; i++){
		tab[i][i] = 0 ;
		if(i!=n-1)
			tab[i][i+1] = arr[i] * arr[i+1] ; 
	}
	
	for(l=3 ; l<=n ; l++){
		for(i=0 ; i<=n-l ; i++){
			j = i+l-1 ;
			tab[i][j] = INT_MAX ;
			for(k=i ; k<j ; k++)
			{
				tab[i][j] = min(tab[i][k] + tab[k+1][j] + sum[i][k] * sum[k+1][j] , tab[i][j]);
			}
		}
	}
	
//	return tab[0][n-1] ;
	return tab[0][n-1] ;
	
}


int main() {
	int n;
	while((s(n)!=EOF)){
		int arr[n];
		FOR(0,n-1)
			s(arr[i]);
		p(minvalue(arr,n));
	}
	return 0 ;
}

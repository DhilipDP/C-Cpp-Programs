#include<stdio.h>
#include<iostream>
using namespace std;

int maxi(int a,int b){
	return a>b ? a : b;
}
void calculate(int val[],int wei[],int n,int capacity){
	int K[2][capacity+1];
	for(int i=0 ; i<2 ; i++)
		for(int j=0 ; j<=capacity ; j++)
			K[i][j]=0;
	for(int i=1 ; i<=n  ;i++){
		int j;
		if(i%2){
			for(j=1 ; j<=capacity ; j++){
				if(wei[i-1] <= j)
					K[1][j] = maxi(K[0][j],val[i-1] + K[0][j-wei[i-1]]);
				else
					K[1][j] = K[0][j];
 			}
		}
		else{
			for(j=1 ; j<=capacity ; j++){
				if(wei[i-1] <= j)
					K[0][j] = maxi(K[1][j],val[i-1] + K[1][j-wei[i-1]]);
				else
					K[0][j] = K[1][j];
 			}
			
		}
	}
	if(n&1)
		printf("%d", K[1][capacity]);
	else
		printf("%d", K[0][capacity]);
}
int main(){
	int  capacity,n;
	scanf("%d%d",&capacity,&n);
	int value[n];
	int weight[n];
	for(int i=0 ; i<n ; i++)
		scanf("%d%d",&value[i],&weight[i]);
	calculate(value,weight,n,capacity);
}

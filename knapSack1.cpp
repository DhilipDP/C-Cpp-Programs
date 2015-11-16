#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#define cap 200
#define n  2000
using namespace std ;


int maxi(int a,int b){
	return a>b ? a : b ;
}
int main(){
	int ar[1][2000001];
	
	int wei[101];
	int pro[101];
//	int arr[2][101];
	FILE *fp ;
	fp = fopen("knapsack_big.txt","r");
	char a[100];
	int i=1 ;
	int w=1 , p=1 ;
	while((fscanf(fp,"%s",a))!=EOF){
		string s(a);
	//	cout<<s<<endl;
		if(i % 2)
			pro[p++]=atoi(s.c_str());
		else
			wei[w++] = atoi(s.c_str());
		i++;
	}
	int arr[2][cap+1]={0};
	int j;
//	cout<<"hello";
//	for(i=0 ; i<=n ; i++)
//		for(j=0 ; j<=cap ; j++)
//			arr[i][j] = 0;

	for(i=1 ; i<=n ; i++){
		
		if(i%2){
			for(j= 0 ; j<=cap ; j++){
				if(wei[i] > j)
					arr[1][j] = arr[0][j];
				else
					arr[1][j] = max(arr[0][j] , pro[i] + arr[0][j-wei[i]]);
			}
			cout<<"arr[1]["<<j<<"] : "<<arr[1][j]<<endl;
		}
		else{
			for(j=0 ; j<=cap ; j++){
				if(wei[i] > j)
					arr[0][j] = arr[1][j];
				else
					arr[0][j] = max(arr[1][j] , pro[i] + arr[1][j-wei[i]]);
			}
			cout<<"arr[0]["<<j<<"] : "<<arr[0][j]<<endl;
		}
		
	/*	for(j=0 ; j<=cap ; j++){
			cout<<i<<" "<<j<<endl;
			if(wei[i] > j)
				arr[i][j] = arr[i-1][j];
			else
				arr[i][j] = maxi(arr[i-1][j] , pro[i] + arr[i-1][j-wei[i]]);
			cout<<"arr["<<i<<"]["<<j<<"] : "<<arr[i][j]<<endl;
		//	break;
		}
	//	break; */
	}
	
	if(n & 1)
		cout<<arr[1][cap];
	else
		cout<<arr[0][cap];
}
	

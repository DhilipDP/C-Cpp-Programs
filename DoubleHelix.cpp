#include<stdio.h>
#include<iostream>

using namespace std ;

int maxi(int a,int b){
	return a > b ? a : b;
}

int maxSumPath(int *arr1,int *arr2,int m,int n){
	
	int i=0 , j=0 , sum1 = 0,sum2 = 0,result = 0 ;
	while(i<m && j<n){
		if(arr1[i] < arr2[j]){
			sum1 += arr1[i] ;
			i++;
		}
		else if(arr2[j] < arr1[i]){
			sum2 += arr2[j];
			j++;
		}
		else{
			result += maxi(sum1,sum2);
			sum1 = sum2 = 0;
			while(i<m && j<n && arr1[i] == arr2[j] ){
				result += arr1[i];
				i++;
				j++;
			}
		}
	}
	while(i<m)
		sum1 += arr1[i++];
	while(j<n)
		sum2 += arr2[j++];
	result += maxi(sum1,sum2);
	return result ;
}
int main(){
	int num1,num2  ;
	bool first=false,second = false ;
	int *arr1,*arr2;
	while(true){
		if(!first)
		{
			scanf("%d",&num1);
			if(num1==0)
				break ;
			arr1 = new int[num1];
			for(int i=0 ; i<num1 ; i++)
				scanf("%d",&arr1[i]);
			first = true ;
		}
		else{
			scanf("%d",&num2);
			arr2 = new int[num2];
			for(int i=0 ; i<num2 ; i++)
				scanf("%d",&arr2[i]);
			second = first = false ;
		}
		if(!first && !second){
	/*	for(int i=0 ; i<num1 ; i++)
			cout<<arr1[i]<<" ";
		cout<<endl;
		for(int i=0 ; i<num2 ; i++)
			cout<<arr2[i]<<" ";
		cout<<endl; */
			printf("%d\n",maxSumPath(arr1,arr2,num1,num2));
		}
	}
}

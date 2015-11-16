#include<iostream>
#include<stdio.h>

using namespace std;

int main(){
	while(1){
		int n;
		scanf("%d",&n);
		if(n==-1)
			break;
		int arr[n+1];
		long int sum = 0,i;
		for(i=0 ; i<n ; i++)
		{
			scanf("%d",&arr[i]);
			sum += arr[i];
		}
		if(sum % n != 0 )
			printf("-1\n");
		else{
			long int val = sum/n;
			long int shortage = 0,add = 0,count=0;
			for(i=0 ; i<n ; i++){
				if(arr[i] < val){
					shortage += (val - arr[i]);
					count++;
				}
				else if(arr[i] > val)
					add += (arr[i]-val);
			}
			if(shortage == add){
				printf("%ld\n",count);
			}
			else
				printf("-1\n");
		}
	
	}
	
}

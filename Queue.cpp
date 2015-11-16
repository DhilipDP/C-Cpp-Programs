#include<iostream>
#include<algorithm>
#include<stdio.h>

using namespace std;

struct people{
	int height;
	int number;
};

bool compare(people a,people b){
	return a.height > b.height;
}

int main(){
	int tests;
	scanf("%d",&tests);
	while(tests--){
		int n;
		scanf("%d",&n);
		people arr[n];
		int output[n];
		memset(output,-1,sizeof(output));
		int i;
		for( i=0 ; i<n ; i++)
			scanf("%d",&arr[i].height);
		for( i=0 ; i<n ; i++)
			scanf("%d",&arr[i].number);
		make_heap(arr,arr+n,compare);
		for(i=0 ; i<n ; i++)
		{
					pop_heap(arr,arr+n-i,compare);
			int hei = arr[n-1-i].height;
			int num = arr[n-1-i].number;
			int count = -1;
			if(num==0){
				for(int k=0 ; k<n ; k++){
					if(output[k]==-1){
						output[k]=hei;
						break;
					}
				}
			}
			else{
				for(int j=0 ; j<n ; j++){
				if(output[j]==-1)
					count++;
				if(count==num){
					output[j]=hei;
					break;
				}
		
			}
		}
		printf("\n");		
	}
	for(i=0 ; i<n ; i++)
			printf("%d ",output[i]);
		printf("\n");
		
}
}

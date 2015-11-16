#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;

struct knapsack{
	int value;
	int weight;
	float ratio;
};

int compare(const void * a,const void *b){
	knapsack * p1 = (knapsack *)a;
	knapsack * p2 = (knapsack *)b;
	return p1->weight - p2->weight;
}
int main(){
	int  capacity,n;
	scanf("%d%d",&capacity,&n);
	knapsack arr[n];
	for(int i=0 ; i<n ; i++){
		scanf("%d%d",&arr[i].value,&arr[i].weight);
		arr[i].ratio = (float)arr[i].value/(float)arr[i].weight;
	}
	qsort(arr,n,sizeof(arr[0]),compare);
//	for(int i=0 ; i<n ; i++){
//		cout<<arr[i].ratio<<" ";
//	}
	int total=0;
	for(int i=0 ; i<n ; i++){
		if(arr[i].weight < capacity){
			total += arr[i].value;
			capacity -= arr[i].weight;
		}
		else
			break;
	}
	printf("%d",total);
}

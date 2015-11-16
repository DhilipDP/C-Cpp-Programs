#include<stdio.h>
#include<algorithm>
using namespace std;
int compare(const void * a,const void * b){
	return  (*(int *)a - *(int *)b);
}
int main(){
	int b,g,m,s;
	int count =1 ;
	while(scanf("%d%d%d%d",&b,&g,&m,&s)!=EOF){
		int arr[4];
		arr[0]=b;arr[1]=g;arr[2]=m ;arr[3]=s;
		
		qsort(arr,4,sizeof(int),compare);
		printf("Case %d: %d\n",count++,arr[2]+arr[3]);	
	}
	return 0;
}

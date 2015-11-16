
#include<stdlib.h>
#include<stdio.h>

int values[100000000]={0};


int main(){
	int i,arr[500001],val;
	arr[0]=0;
	values[0]=1;
	for( i=1 ; i<=500000 ; i++){
		  val = arr[i-1] - i;
		if(val>0 && values[val]==0){
			arr[i]=val;
			values[val]=1;
		}
		else{
			arr[i]=arr[i-1]+i;
			values[arr[i]]=1;			
		}
	}
	while(1){
	int k;
	scanf("%d",&k);
	if(k!=-1)
		printf("%d\n",arr[k]);
	else 
		break;
		
}
}

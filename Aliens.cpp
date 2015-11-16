#include<stdio.h>
#include<limits.h>
int main(){
	int tests;
	scanf("%d",&tests);
	while(tests--){
		int at,bt;
		scanf("%d%d",&at,&bt);
		int arr[at],i,j;
		int peo=INT_MAX,sta=INT_MIN,count;
		long int sum,pre_sum;
		for(i=0 ; i<at ; i++)
			scanf("%d",&arr[i]);
		for(i=0 ; i<at && sta <= (at-i) ; i++){
			sum=0;count=0;
			for(j=i ;  j<at  ; j++ ){
				sum += arr[j];
				if(sum > bt){
					sum -= arr[j];
					break;
				}
				count++;
			}
			if(count >= sta && sum < peo){
				peo=sum;
				sta=count;
			}
		}
		printf("%d %d\n",peo,sta);		
	}
	return 0;
}

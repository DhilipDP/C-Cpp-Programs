#include<stdio.h>

int findNum(float num){
	double sum=0.0;int i;
	for( i=2 ; sum < num ; i++)
		sum += 1.0/(float)i;
	return i-2;
}


int main(){
	while(1){
		float val;
		scanf("%f",&val);
		if(val==0.00)
			break;
		printf("%d card(s)\n",findNum(val));
	}
}

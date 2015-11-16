#include<stdio.h>

int main(){


	int a=1;
	a=a++;
	printf("%d ",a);
	int i=0,j=0;
	do{
		printf("Nandu ");
		i=i++;
		j++;
		printf("%d\n",i);
	}while(j<5);
}

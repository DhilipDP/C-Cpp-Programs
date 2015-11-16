#include<stdio.h>
int main(){
	int n,flag=0 ;
	scanf("%d",&n);
	int i,j,k,l,spaces = n-1 ;
	int m=-1;
	for(i=1 ; i<= n ; i++){
		for(k=1 ; k<=spaces ; k++){
			printf(" ");
		}
		for(l=1 ; l<=i ; l++){
			printf("* ");
		}
		spaces--;
		printf("\n");	
	}
	
}


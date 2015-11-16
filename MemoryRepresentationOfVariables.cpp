#include<stdio.h>


typedef unsigned char * byte_pointer;


void show(byte_pointer start,int size){
	int i;
	printf("%d \n",size);
	for( i=0 ; i<size ; i++){
		printf("%x ",start[i]);
	}
	printf("\n");
}
int main(){
	
	printf("Integer\n");
	int i=256;
	show((byte_pointer)&i,sizeof(i));
	
	printf("Float\n");
	float f =0.1;
	show((byte_pointer)&f,sizeof(f));
	
	printf("ChAR\n");
	char c= 'a';
	show((byte_pointer)&c,sizeof(c));
	
		
	printf("pointer\n");
int *j=&i; 
	show((byte_pointer)&j,sizeof(j));
	
}

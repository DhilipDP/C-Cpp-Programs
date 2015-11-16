#include<stdio.h>

void main()
{
	
	int (*arr)[2] ;
	//arr[0][0] = 1;
	printf("%u %u %u %u %u %u\n",arr,&arr[0],&arr[1],arr+2,arr+0,&arr+1);
	void * q ;
	int * p ;
	p = q;
	int s[10][10] ;
	float c = 3.5 + 3;
	int a,b =16;
	printf("%d %d %d",b==16,b = 20 , b<30);
}

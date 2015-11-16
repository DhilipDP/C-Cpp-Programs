#include<stdio.h>

#define _ 0
#define sync(i) while(i++<4) printf("SYNC") 
#define __(a,b) a##b 

void main()
{
	int a = 4 , b = 3 ;
	
	printf("%d %d\n",a,b);
	a = a + b - (b=a) ;
	printf("%d %d\n",a,b);

	printf("%d" , a=100);
}

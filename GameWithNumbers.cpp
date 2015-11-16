#include<stdio.h>

int main()
{
	int value;
	scanf("%d",&value);
	value % 10 ? printf("1\n%d\n",value%10) : printf("2\n");
}

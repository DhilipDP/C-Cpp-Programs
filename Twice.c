#include<stdio.h>

int main()
{
	int i, n , val, count = 0,  pre = 0, pre_pre = 0 ;
	scanf("%d",&n) ;
	for(i=0 ; i<n ; i++)
	{
		scanf("%d",&val) ;
		if(i> 1 && val*2 == pre_pre)
			count++;
		pre_pre = pre ;
		pre = val;
	}
	printf("%d ",count) ;
}

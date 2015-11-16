#include<stdio.h>

int main()
{
	int t,n ,res=0,val;
	scanf("%d",&t) ;
	while(t--)
	{
		 res=0;
		scanf("%d",&n) ;
		if(!(n & 1))
			n++;
		while(n--)
		{
			scanf("%d",&val) ;
			res ^= val;	
		//	printf("%d",res) ;
		}
		printf("%d\n",res);
	}
}

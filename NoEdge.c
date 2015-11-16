#include<stdio.h>
int main()
{
	int N , i , j ,sum = 0,val;
	scanf("%d",&N) ;
	for(i=0 ; i<N ; i++)
	{
		for(j=0 ; j<N ; j++)
		{
			scanf("%d",&val) ;
			if(i==0 || i==N-1 || j==0 || j==N-1)
				continue ;
			sum += val;
		}
	}
	printf("%d",sum)  ;
}

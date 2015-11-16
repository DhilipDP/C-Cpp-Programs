#include<stdio.h>
#include<math.h>

int main()
{
	int n ,digit=1,sum = 0,i,k=0,j,place;
	char ans[1000] ;
	scanf("%d",&n) ;
	while( sum + pow(2,digit) < n)
	{
		sum = sum +  pow(2,digit) ;
		digit++;
	}
	place = n - sum ;
	place--;
	for(i=digit-1 ; i>=0 ; i--,k++){
	
		if((place & (1<<i)) != 0)
			ans[k] = '4' ;
		else
			ans[k] = '3';
	}
	ans[k] = '\0' ;
	printf("%s\n",ans) ;
}

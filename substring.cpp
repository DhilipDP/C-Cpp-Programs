#include<stdio.h>
#include<string.h>
int main()
{
	int i,j,k,found=0;
	char s[1000] , t[100] ;
	scanf("%s",s) ;
	scanf("%s",t) ;
	for(i = 0 ; i<strlen(s) ; i++)
	{
		if(s[i] == t[0]){
			k = i ;
			for(j=0  ; j<strlen(t)  ;  j++)
			{ 
				if(t[j] != s[k++])
					break;
			}
			if(j==strlen(t)){
				printf("%d\n",i);
				found = 1 ;
				break;
			}
		}
	}
	if(!found)
		printf("%d\n",-1) ;
}

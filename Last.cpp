#include<stdio.h>
#include<math.h>
int main()
{
	int tests;
	scanf("%d",&tests);
	while(tests--){
		int a;
		long int b;
		scanf("%d%ld",&a,&b);
		a= a%10;
		if(a==2 || a==3 || a==7 || a==8){
			long int val = b%4;
			printf("%d\n",(int)pow((double)a,(double)val));
		}
		else if(a==0 || a==1 || a==5 || a==6)
			printf("%d\n",a);
		else if(a==4){
			if((b%10) % 2 )
				printf("4\n");
			else
				printf("6\n");
		}
		else{
			if((b%10) % 2)
			   printf("9\n");
			else
				printf("1\n");
		}
	}
}

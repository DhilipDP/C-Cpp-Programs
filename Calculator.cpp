#include<stdio.h>

int main(){
	printf("1)Add \n2)Sub \n3)Mul \n4)Div \n");
	printf("\nEnter ur choice");
	int ch;
	scanf("%d",&ch);
	printf("\nEnter two numbers: ");
	float a,b ;
	scanf("%d%d",&a,&b);
	switch(ch){
		case 1 :
			printf("The sum is : %d\n",a+b);
			break;
		case 2:
			printf("The diff is : %d\n",a-b);
			break;
		case 3:
			printf("The prd is : %d\n",a*b);
			break;
		case 4:
			printf("The quo is : %f\n",a/b);
			break;
		case 5: 
		default : printf("Invalid");	
	}
}

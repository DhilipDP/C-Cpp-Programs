#include<stdio.h>
#include<string.h>

int main(){
	char s1[1000],s2[1000] ,result[1000];
	int pos ;
	printf("Enter 1st string: ");
	scanf("%s",s1);
	printf("Enter 2nd string: ");                                                 
	scanf("%s",s2);
	int l1 = strlen(s1);
	int l2 = strlen(s2);
	printf("Enter position in the first string: ");
	scanf("%d",&pos);
	pos--;
	if(pos >= l1)
		printf("Invalid  index !");
	else{
		int index = 0,i;
		for(i=0 ; i<pos ; i++)
			result[index++] = s1[i];
		for(i=0 ; i<l2 ; i++)
			result[index++] = s2[i];
		for(i=pos ; i<l1 ; i++)
			result[index++] = s1[i];
		result[index] = '\0';
		printf("Result : %s",result);
	}
		
	return 0;
}


#include<stdio.h>

void main(){
	 static int i = 1;
	if(i > 200)
		return ;
	printf("%d ",i++);
	main();
}

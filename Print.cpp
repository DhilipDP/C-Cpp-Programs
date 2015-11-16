#include<stdio.h>

int main(){
	static int i = 1;
	if(i > 200)
		return 0;
	printf("%d ",i++);
	main();
}

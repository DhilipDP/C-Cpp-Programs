#include <stdio.h>
#include <stdlib.h>
struct st{
	double a;
	float b;
	int c;
	short d;
	char e;
};

int main(){
	printf("%d\n",sizeof(struct st));
	printf("%d\n",sizeof(double));
	printf("%d\n",sizeof(float));
	printf("%d\n",sizeof(int));
	printf("%d\n",sizeof(short));
	printf("%d\n",sizeof(char));
	return 0;
}


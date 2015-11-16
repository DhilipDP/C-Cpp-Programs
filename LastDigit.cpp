#include<iostream>

#include<stdio.h>
#include<math.h>

int findbase(int a){
	switch(a){
		case 1 : return 1;
		case 2 : return 4;
		case 3 : return 4;
		case 4 : return 2;
		case 5 : return 1;
		case 6 : return 1;
		case 7 : return 4;
		case 8 : return 4;
		case 9 : return 2;
		case 0 : return 1;
	}
}
int main()
{
	int tests;
	scanf("%d",&tests);
	while(tests--){
		int a;
		long int b;
			scanf("%d%ld",&a,&b);//cin>>a>>b;
		long int val = b%findbase(a);
		printf("%ld\n",pow(a,val));
	}
}

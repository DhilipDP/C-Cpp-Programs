#include<stdio.h>
#include<iostream>
using namespace std;
int main(){
	int n = 1 ;
	double x = 5 ;
	while( 1){
		x = ((x + 23) * 17)/19;
		n++;
		if(n==100)
			printf("%.7f",x);
	}
}

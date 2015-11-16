#include<iostream>
#include<stdio.h>
using namespace std ;

int main(){
	int count = 1;
	int a[3][3][3] ;
	for(int i=0 ; i<3 ; i++)
		for(int j=0 ; j<3 ; j++)
			for(int k=0 ; k<3 ; k++)
				a[i][j][k] = count++;
	int *q = a[0][0] ;
	int **k = &q ;
	int ***p=&k;
	printf("%u %u %u %u\n",a,***p,*q,**k);
	**p = *k + 1;
	*k = **p+1;
	printf("%u %u\n",*q,**k);
	q = a[1][1] ;
	k = &q;
	p=&k;
	++***p;
	++*k;
	printf("%u %u %u\n",***p,*q,**k);
	return 0;
}


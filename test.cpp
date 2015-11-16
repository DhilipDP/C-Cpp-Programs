#include<iostream>
#include<stdio.h>
using namespace std ;

class test1{
	int a ;
	
	public :
	//	test1(){}
		
			virtual void fun(){}
			
};
int main(argc, argv)
{//
	cout<<argc<<" "<<argv[0]<<endl;
	test1 a ;	
	cout<<sizeof(a)<<endl;
	printf("%p\n",15);
	printf("%0.2f\n",1.23556);
	///int const * nan = 5;
	//(*nan)++;
	int arr[] = {1,2,3};
	int i=10,j=20,d ;
	int k=30;
	int l = 40;
	int &p = l;
	int *m = &j + 3;
	cout<<&i<<endl;
	cout<<&j<<endl;
	d = &i - &l;
	printf("%u %u %u %u %u",&i,&j,&k,&l,m);
	int f = &arr[2] - &arr[0] ;
	cout<<endl<<d<<endl<<f;
}

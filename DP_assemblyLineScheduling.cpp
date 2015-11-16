#include<iostream>
#include<limits.h>
using namespace std ;


int minimumTime(int l1[],int l2[],int t1_2[],int t2_1[],int n,int e[],int x[]){
	
	int T1[n] ;
	int T2[n] ;
	T1[0] = e[0] + l1[0] ;
	T2[0] = e[1] + l2[0] ;
	for(int i=1 ; i<n ; i++)
	{
		T1[i] = min(T1[i-1] + l1[i] , T2[i-1] + t2_1[i] + l1[i]) ;
		T2[i] = min(T2[i-1] + l2[i] , T1[i-1] + t1_2[i] + l2[i]);
	}
	return min(T1[n-1] + x[0],T2[n-1] + x[1]);
}

int main() {

	int line1[]= {4,5,3,2} ;
	int line2[] = {2,10,1,4};
	int t1_2[] = {0,7,4,5} ;
	int t2_1[] = {0,9,2,8};
	int n = sizeof(line1)/sizeof(line1[0]);
	int entry[] = {10,12};
	int exit[] = {18,7};
	
	cout<<minimumTime(line1,line2,t1_2,t2_1,n,entry,exit);
}

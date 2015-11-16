#include<iostream>
#include<vector>
#include<limits.h>
#include<algorithm>
#include<stdio.h>
#define p(a) printf("%d\n",a)
#define s(a) scanf("%d",&a)
using namespace std;


int main(){
	int n;
	s(n);
	while(n--){
		int a;
		s(a);
		p((a&1));
	}
	return 0;
}

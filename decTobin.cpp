#include<iostream>
#include<stdlib.h>

using namespace std;

int main(){
	int n = 101;
	char a[100];
	itoa(n,a,10);
	cout<<a;
}

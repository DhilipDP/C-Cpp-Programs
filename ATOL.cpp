#include<stdio.h>
#include<iostream>
#include<stdlib.h>

using namespace std;
int main(){
	string output ="12345";
	char *a = new char(output.size());
	a[output.size()] = 0;
	memcpy(a,output.c_str(),sizeof(output));
	cout<<a;
	cout<<endl<<atol(a) % 1000000007<<endl;
	cout<<atol(output.c_str());
}

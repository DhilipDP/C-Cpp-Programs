#include<iostream>

using namespace std;


int main(){
//	int i=1,2,3;
int 	i=(1,2,3);
int a,b,c,d;
	a=1;
	b=1;
	c=a || --b;
	cout<<c<<b<<endl;
//	d= 0 || -1;
	
	d=a-- && --b;
	cout<<d<<endl;
	cout<<sizeof(i++);
	cout<<i<<endl;	
}

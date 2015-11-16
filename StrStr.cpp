#include<iostream>
#include<string.h>
using namespace std;

int main()
{
	char *str = "12.34.45";
	char *s = strstr(str,".") ;
	char *t = strstr(s,".");
	cout<<s<<endl<<t;
}

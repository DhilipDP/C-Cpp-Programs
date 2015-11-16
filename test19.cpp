#include<iostream>
#include<stdlib.h>
using namespace std ;

int main(){
	int i,j;
	char * ptr = (char *)malloc(10);
	if(NULL == ptr)
		cout<<"no";
		else
		cout<<"yes";
		
	for(i=0,j=0 ; i<5,j<10 ; i++,j++)
		cout<<"hi"<<endl;
		
	i=1;
	switch(i);{
		case 1: ;
	}
}

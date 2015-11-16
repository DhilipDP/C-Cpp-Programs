#include<stdio.h>
#include<iostream>

using namespace std ;

void print(int num)
{
		for(int i=31 ; i>=0 ; i--){
		if((num & (1<<i)) != 0)
			cout<<"1";
		else 
			cout<<"0";
	//	cout<<endl;
		}
		cout<<endl;
}

int main(){
	
	int num = 9;
	print(num);
	print(~num);
	print(2);
}

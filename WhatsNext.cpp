#include<iostream>
#include<stdlib.h>

using namespace std;


int findProgression(int x,int y,int z){
	if(abs(y-x) == abs(z-y))
		return 1;
	else
		return 2;
}
int main()
{
	int first_no,second_no,third_no;
	while(1){
		cin>>first_no>>second_no>>third_no;
		if(first_no==0 && second_no==0 && third_no==0)
			break;
		int prog = findProgression(first_no,second_no,third_no);
		if(prog==1)
			cout<<"AP "<<(second_no-first_no)+third_no;
		else
			 cout<<"GP "<<(second_no/first_no)*third_no;
	}
	return 0;
}

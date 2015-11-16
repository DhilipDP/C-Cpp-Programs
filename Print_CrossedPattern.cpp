#include<iostream>
using namespace std ;


void print_pattern(string str){
	int length = str.length();
	if(length % 2==0){
		cout<<"Give odd length string";
		return ;
	}
	int start = 0,end = length - 1 ;
	int spaces = length-2;
	int st_space = 0;

	while(start < end){
		for(int k=0 ; k<st_space ; k++)
			cout<<" ";
		st_space++;
		cout<<str[start];
		for(int k=0 ; k<spaces ; k++)
			cout<<" ";
		spaces-=2;
		cout<<str[end];
		cout<<endl;
		start++;
		end--;
	}
//	return ;
	for(int k=0 ; k<start ; k++)
		cout<<" ";
	cout<<str[start]<<endl;
	start--;end++;
	spaces = 1;
	st_space = start ;
	while(start!=-1){
		
		for(int k=0 ; k<st_space ; k++)
			cout<<" ";
		st_space--;
		cout<<str[start];
		for(int k=0 ; k<spaces ; k++)
			cout<<" ";
		spaces+=2;
		cout<<str[end];
		cout<<endl;
		start--;
		end++;
	}
}
int main(){
	string str ="encyclopedian";
	print_pattern(str);
}

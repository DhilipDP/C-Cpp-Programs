#include<stdio.h>
#include<iostream>
using namespace std ;

void printUnsigned(size_t bytes){

	int bits = bytes*8;
	int from = 0 ;
	unsigned long int to = (1<<(bits-1))-1 + (1<<(bits-1));
	cout<<"\nUnsigned: \n";
	cout<<"from "<<from<<" to "<<to<<endl;
}

void printSigned(size_t bytes){
	int bits = bytes*8;
	int from = -(1<<bits-1) ;
	int to = (1<<(bits)-1)-1;
	cout<<"\nSigned: \n";
	cout<<"from "<<from<<" to "<<to<<endl;
}

int main(){
	


	while(true){
		cout<<"Menu!\n(1)Int \n(2)Char \n(3)Float \n(4)ShortInt \n(5)Quit"<<endl;
		int choice;
		string arr[] = {"","int","char","float","short int"};//}
		cin>>choice;
		if(choice==5)
			break;
		if(choice < 1 || choice > 4)
			cout<<"Invalid Choice"<<endl;
		else{
				printSigned(sizeof(arr[choice]));
				if(choice!=3)
					printUnsigned(sizeof(arr[choice]));
				
		}
	}
	return 0;
}

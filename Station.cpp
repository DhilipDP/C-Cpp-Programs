#include<iostream>
#include<stdio.h>
using namespace std;

struct station{
	int num;
	string name;
};


int main(){
	int n;
	cout<<"NO of stations?: ";
	cin>>n;
	station arr[n];
	cout<<"Enter number and name of stations: ";
	for(int i=0 ; i<n ; i++)
	{	cin>>arr[i].num;
		cin>>arr[i].name;
	
	}
	int br = 1;
	while(br){
	cout<<"\nEnter ur choice\n (1) Number \n(2) Name (3) Quit:";
	int choice;
	cin>>choice;
	string str;
	switch(choice){
		case 1:
			int no;
			cout<<"ENter number: ";
			cin>>no;
			for(int i=0 ; i<n ; i++){
				if(arr[i].num == no){
					cout<<endl<<"The station is "<<arr[i].name;
					break;
				}
			}
			break;
			case 2:
					 str;
			cout<<"ENter name: ";
			cin>>str;
			for(int i=0 ; i<n ; i++){
				if(arr[i].name == str){
					cout<<endl<<"The station number is "<<arr[i].num;
					break;
				}
			}
			break;
			case 3 : br =0;
	}
	}
}

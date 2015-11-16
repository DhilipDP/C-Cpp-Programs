#include<iostream>

using namespace std;

int main(){
	string str;
	cin>>str;
	if(isdigit(str[0]))
		cout<<"number";
	else
		cout<<"word";
}

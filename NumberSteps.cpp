#include<iostream>
using namespace std;


int check (int x,int y){
	if(y==x || y==x-2)
		return 1;
	return 0;
}
int main(){

	int tests;
	cin>>tests;
	int x,y;
	while(tests--){
		cin>>x>>y;
		if(check(x,y)){
			if(x%2==0){
				cout<<endl<<x+y;
			}
			else{
				cout<<endl<<x+y-1;
			}
		}
		else{
			cout<<endl<<"No Number";
		}
	}
	return 0;
}



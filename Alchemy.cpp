#include<iostream>
#include<math.h>
using namespace std;

int main(){
	while(1){
	int i,w;
	cin>>i>>w;
	if(i==-1)
		break;
	if(i*37 == 1000*w)
		cout<<"Y\n";
	else
		cout<<"N\n";
}
}

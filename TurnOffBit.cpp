#include<iostream>
#include<math.h>
using namespace std;


int numberOfBits(int n){
	int no=0; 
	int temp=n;
	while(n > pow(2,no)){
		no++;
	}
	return (n && (n-1)) ?  no :  no+1;
}

int main(){
	//cout<<(1<<3);
	//cout<<sizeof(unsigned int)*8;	
	
	int n,k,i=0 ;
	while(i<5){
	cout<<"ENter n:\n"; 
	cin>>n;
	cout<<numberOfBits(n);
	i++;
}
	cout<<"\nEnter the bit to be turned off\n";
	cin>>k;
}

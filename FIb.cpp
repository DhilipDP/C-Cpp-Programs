#include<iostream>
using namespace std ;


int arr[1000];


int main(){
	arr[0] = 0;
	arr[1] = 1;
	for(int i=2 ; i<=40 ; i++)
		arr[i] = arr[i-1] + arr[i-2];
	int c=0;
	for(int i=0 ; i<=40 ; i++)
		if(arr[i] & 1)
			cout<<++c<<" :"<<arr[i]<<endl;
}

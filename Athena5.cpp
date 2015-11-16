#include<iostream>
using namespace std ;


int arr[10001];

int main(){
	int size = 10000;
	for(int i=1 ; i<=size ; i++)
		arr[i]=i;
	
	int t=3;
	while(t--)
	{
		cout<<"A:"<<endl;
for(int i=1 ; i<=size ; i++)
		cout<<arr[i]<<" ";
	cout<<endl;	 
	for(int i=1 ; i<=size ; i+=2)
		arr[i]=0;
	int b[10001];
	int k=1;
	for(int i=1 ; i<=size ; i++)
		if(arr[i]!=0)
			b[k++] = arr[i];
		cout<<"B:"<<endl;
	for(int i=1 ; i<k ; i++)
		cout<<b[i]<<" ";
	cout<<endl;
	for(int i=5 ; i<=k ; i+=5){
		b[i]=0;
	}
	int l=1;
	int c[10001];
	for(int i=1 ; i<=k ; i++)
		if(b[i]!=0)
			c[l++] = b[i];
		cout<<"C"<<endl;
	for(int i=1 ; i<l ; i++)
		cout<<c[i]<<" ";
	cout<<endl;
	for(int i=7 ; i<=l ; i+=7)
		c[i] = 0;
		size = 1;
	for(int i=1 ; i<=l ; i++)
		if(c[i]!=0)
			arr[size++]  = c[i];
//	size = l;
//	cout<<arr[1]<<endl;
	}
	int n=0;
	for(int i=1 ; i<=size ; i++)
	`cout<<arr[i]<<endl;
	cout<<arr[150];
//	for(int i=1 ; i<=size ; i++)
		
}

#include<iostream>
using namespace std;

int main(){
	int h1=0,min1=0,h2=0,min2=0 ;
	cin>>h1>>min1>>h2>>min2 ;
	int hr, min ;
	if(h2 > h1)
		hr = h2-h1;
	else
		hr = (24 - h1) + h2;
	if(min2 <  min1){
		hr--;
		min =  60 - (min1 - min2);
	}
	else{
		min = min2-min1;
	}
	cout<<"O JOGO DUROU "<<hr<<" HORA(S) E "<<min<<" MINUTO(S)\n";
	
}

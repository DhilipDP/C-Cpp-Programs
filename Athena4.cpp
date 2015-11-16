#include<iostream>
#include<map>
using namespace std ;

map<int,int> t;
map<int,int> p;

int main(){
	int i=1;
	int val=1;
	while(val<=10000){
		val = (i*(i+1))/2;
		t[val]=1;
		i++;
	}
	for(i=0 ; i<=100 ; i++)
		p[i*(i+1)]=1;
	i=10000;
	while(1){
		if(t[i]==1 && p[i]==1)
		{
			cout<<i;
			break;
		}
		i--;
	}
}

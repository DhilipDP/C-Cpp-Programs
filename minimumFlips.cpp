#include<iostream>

using namespace std ;


int setBits(int x){
	int count = 0;
	while(x){
		if(x & 1)
			count++;
		x>>=1;
	}
	return count ;
}
int minimumFlips(int num1 ,int num2)
{
	return setBits(num1 ^ num2) ;
	
}

int main(){
//	cout<<(1 << 2);
	int num1 = 10;
	int num2 = 15;
	cout<<minimumFlips(num1,num2);
}

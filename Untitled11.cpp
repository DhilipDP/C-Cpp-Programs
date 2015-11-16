#include<iostream>
using namespace std;


int function(string key)
{
	long int sum=0;
	for(int i=0 ; key[i] ; i++){
			sum +=( (int)key[i] * (i+1));
	}
	return (19 * sum) % 101;
}

int main(){
	string s ="ziemii";
	cout<< function(s);
}

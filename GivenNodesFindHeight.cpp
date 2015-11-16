8#include<iostream>
#include<math.h>
using namespace std ;

int main(){
	int t= 10;
	
	int nodes ;
	
	cout<<"Number of Nodes: "<<endl;
	cin>>nodes ;
	/* N = 2 ^ (h+1) - 1
		2^(h+1) = N+1
		h = log (N+1)(base 2) -1
	*/
	// assuming height of a NULL tree is -1
	int height ,val = 0;
	while(pow(2,val) < (nodes+1))
		val++;
	height = val - 1;
	cout<<"\nHeight of the complete binary tree is: "<<height<<endl;	
}

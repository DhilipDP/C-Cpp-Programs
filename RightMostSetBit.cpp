#include <iostream>
#include<math.h>
using namespace std;

int main() {
	// your code goes here
	int n;
	cin>>n;
	int rightmost_set_bit ;
	rightmost_set_bit = (n) & ~(n-1);
	cout<<log2(rightmost_set_bit)+1;
	return 0;
}

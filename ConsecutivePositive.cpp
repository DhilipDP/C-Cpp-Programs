#include<iostream>
using namespace std ;



bool isPossible(int n){
	int p=2;
	int st = n/p++;
	int c=2;
	while(true){
		int sum =0;
		int num = st;
		for(int i=1 ; i<=c ; i++)
			sum += num++;
		cout<<sum<<endl;
		if(sum==n)
			return true;
		if(sum < n)
			return false;
		st = n/p++;
		c++;
		//num++;
	}
}


int main(){
	cout<<isPossible(10);
	return 0;
	int arr[]={32, 37, 13, 21, 16, 55, 58, 37, 20, 50, 32, 14, 6, 25, 28, 51, 33, 1, 16, 8, 128, 25, 8, 64, 18, 16, 44, 19, 31, 3, 57, 21, 21, 20, 32, 8, 60, 27, 23, 8, 37, 33, 39, 10, 15, 56, 53, 26, 10, 4};
	int c=0;
	int n = sizeof(arr)/sizeof(arr[0]);
	cout<<n<<endl;
	for(int i=0 ; i<n ; i++)
		if(isPossible(arr[i]))
			cout<<arr[i]<<" ",	c++;
 cout<<endl<<c<<endl;
}

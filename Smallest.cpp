#include<iostream>
#include<limits.h>


using namespace std;

int main()
{
	int min=INT_MAX;
	long int n;
	cin>>n;
	long int i;
	long int count = 0;
	for(i=0 ; i<n ; i++){
		long int val;
		cin>>val;
		if(val < min){
			count=1;
			min=val;
		}
		else	if(val==min){
			count++;
		}
	}
	cout<<min<<endl<<count;
}

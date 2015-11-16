#include<iostream>
#include<limits.h>

using namespace std;

int main (){
	int n,arr[100];
	cout<<"ENter the number of elements: ";
	cin>>n;
	int i,j,min,max,longest_start=-1,longest_end=0;
	cout<<"Enter the elements: ";
	for(i=0 ; i<n  ;i++)
		cin>>arr[i];
	for(i=0 ; i<n ;i++){
			min=INT_MAX;
			max=INT_MIN;
		for(j=i ; j<n  ; j++){
			int val = arr[j];
			if(val < min)
				min = val;
			if(val > max)
				max = val;
			if(2*min <= max)
				break;
			if((j-i > longest_end-longest_start) || (longest_start==-1))	
				{
					longest_start = i;
					longest_end = j;
				}	
		}
	}		
	cout<<longest_start<<" "<<longest_end;
	cout<<"\nNumber of removals: ";
	if(longest_start == -1)
		cout<<endl<<n;//""
	else
		cout<<endl<<n-(longest_end-longest_start + 1);
	return 0;
}


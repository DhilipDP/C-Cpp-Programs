#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;


		struct data{
			long int start;
			long int end;
		};

int compare(const void * a,const void * b)
{
	data *p1 = (data *)a;
	data *p2 = (data *)b;
	if(p1->end == p2->end)
		return p1->start < p2->start;
	return p1->end >= p2->end;
}
int main()
{
	int tests;
	cin>>tests;
	while(tests--){
		long int n;
		cin>>n;
		data arr[n];
		for(int i=0 ; i<n ; i++){
			cin>>arr[i].start>>arr[i].end;
		}
		qsort(arr,n,sizeof(arr[0]),compare);
		long int count = 1;
/*		for(int i=0 ; i<n ; i++){
			cout<<arr[i].start<<" "<<arr[i].end<<endl;
		}*/
		long int j=0;
		for(long int i=1 ; i<n ; i++){
			if(arr[i].start >= arr[j].end ){
				j=i;
				count++;
		}	
		}
		cout<<count<<endl;
	}
}

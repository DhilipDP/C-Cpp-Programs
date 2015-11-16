#include<iostream>
#include<stdlib.h>

using namespace std;

int myCompare(const void * a,const void *b)
{
	cout<<"COmparing: "<<*(int *)a<<" "<<*(int *)b;
	return (*(int*)a-*(int *)b);
}
int main()
{
	int n,arr[10];
	cout<<"No of elements";
	cin>>n;
	cout<<"Elements: ";
	int i;
	for(i=0 ; i<n ; i++)
		cin>>arr[i];
	qsort(arr,n,sizeof(int),myCompare);
	for(i=0 ; i<n ; i++)
		cout<<endl<<arr[i];
	return 0;
}

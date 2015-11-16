#include<iostream>

using namespace std;

int max(int a,int b)
{
	return a>b?a:b;
}
void find(int *a,int n)
{
	int max_so_far=a[0];
	int max_curr=a[0];
	int start=0,end=0,finalstart=0,finalend=0;
	for(int i=1;i<n;i++)
	{
	if(a[i]>max_curr*a[i])
	{
		max_curr=a[i];
		start=i;
		end=i;
	}
	else
	max_curr=max_curr*a[i],end++;
	if(max_curr>max_so_far)
	{
		max_so_far=max_curr;
		finalstart=start;
		finalend=end;
	}
	}
	for(int i=finalstart;i<=finalend;i++)
	cout<<a[i]<<" ";
	
	cout<<endl<<max_so_far;
}
int main()
{
	int arr[]={0,4,-5,5,6};
	int n=sizeof(arr)/sizeof(arr[0]);
	find(arr,n);
	return 0;
}

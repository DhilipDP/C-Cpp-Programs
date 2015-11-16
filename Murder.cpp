#include<iostream>
#include<stdio.h>
using namespace std;


long long int count ,p_count,r_count;
long long int p_array[100000],p_;
long long int r_array[100000];

bool search(long long int val ,int mode){
	bool exist = false ;
	switch(mode){
		case 1: 
		for(long long int i = 0 ; i<p_count ; i++){
			if(p_array[i]==val){
				exist = true;
				break;
		}
		}
		break;
		case 2: 
		for(long long int i = 0 ; i<r_count ; i++){
			if(r_array[i]==val){
				exist = true;
				break;
		}
		}
		break;
	}
	return exist;
}
void Combine(long long int *arr,long long int p,long long int r)
{
	
	if(!search(p,1) && !search(r,2))
{
	p_array[p_count++]=p;
	r_array[r_count++]=r;
	long long int n1 = p+1;
	long long int L[n1],i;
	for(i=0 ; i<=p ; i++)
	{
	//	cout<<"\nCOmparing "<<arr[i]<<" "<<arr[r];
		L[i]=arr[i];
		if(L[i] < arr[r]){
			count += L[i];
		}
	//	cout<<endl<<count;
	}
}
}
void Divide(long long int *arr,int n)
{
/*	for(int i=0 ; i<n ; i++)
		cout<<arr[i]<<" ";
	cout<<endl;*/
	if(n>1){
		int mid = n-2;
		Divide(arr,mid);
		Divide(arr,mid+1);
		Combine(arr,mid,mid+1);
	}
}
int main(){
	cout<<(2 & -2);
	int t;
	scanf("%d",&t);
	while(t--){
		long long int n;
		scanf("%lld",&n);
		long long int arr[n];
		long long int i;
		for(i=0 ; i<n ; i++)
			scanf("%lld",&arr[i]);
		Divide(arr,n);
		printf("%lld\n",count);
	}
}

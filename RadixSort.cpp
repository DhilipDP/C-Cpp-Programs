#include<iostream>
#include<vector>
#include<limits.h>
using namespace std ;



void countSort(vector<int> &v,int digit)
{
	int n = v.size() ;
	int count[10] = {0} ;
	int output[n];
	
	memset(output,0,sizeof(output));
	for(int i=0  ; i<n ; i++)
		count[(v[i]/digit) % 10]++;
	
	for(int i=1 ; i<10 ; i++)
		count[i] += count[i-1] ;
	
	for(int i=n-1 ; i>=0 ; i--)
	{
		output[count[(v[i]/digit) %10]-1] = v[i] ;
		count[(v[i]/digit)%10]--; 
	}	
	
	for(int i=0 ; i<n ; i++)
		v[i] = output[i] ;
}

void radixSort(vector<int> &v)
{
	int maxi = -1 ;
	for(int i=0 ; i<v.size() ; i++)
		maxi = max(maxi,v[i]) ;
	for(int digit=1 ; maxi/digit > 0 ; digit = digit *10){
	
		countSort(v,digit) ;
	for(int i=0 ; i<v.size() ; i++)
		cout<<v[i]<<" " ;
		cout<<endl;
	}
}

int main()
{
	int arr[] = {12,34,123,5,23} ;
	int n = sizeof(arr)/sizeof(arr[0]) ;
	vector<int> v(arr,arr+n) ;
	radixSort(v) ;

	for(int i=0 ; i<n ; i++)
		cout<<v[i]<<" " ;
}


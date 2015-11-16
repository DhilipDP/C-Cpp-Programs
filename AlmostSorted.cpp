#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


bool is_sorted(int arr[],int n){
	cout<<n<<endl;
	for(int i=1 ; i<n ; i++)
		if(arr[i] < arr[i-1]){
			cout<<"hi"<<i<<endl;
			return false;
		}
		return true;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n,i,j ;
    cin>>n;
    int arr[n] ;
    int sorted[n] ;
    for(i=0 ; i<n ; i++)
        cin>>arr[i],sorted[i]=arr[i];
    if(is_sorted(arr,n))
    {
        cout<<"yes";
        return 1;
    }
    sort(sorted,sorted+n);
    for(i=0 ; i<n ; i++){
        if(arr[i]!=sorted[i])
            break;
    }
    
    int st = i;
    for(j=n-1 ; j>i ; j--)
        if(arr[j]!=sorted[j])
            break;
     int end = j;
    int temp[end-st+1];
    int l=st,k;
    cout<<st<<" "<<end<<endl;
    for( k=0 ;  k<=end-st; k++)
        temp[k]=arr[l++];
  	for(i=0 ; i<k ; i++)
  		cout<<temp[i]<<" ";
  	cout<<endl;
  	int t = arr[st];
  	arr[st] = arr[end];
  	arr[end] = t;
  	if(is_sorted(arr,n))
	{
		cout<<"swap"<<endl;
		cout<<st+1<< " " <<end+1;
		return 1;
	}
	 t = arr[st];
  	arr[st] = arr[end];
  	arr[end] = t;
  	reverse(temp,temp+k);
  		for(i=0 ; i<k ; i++)
  		cout<<temp[i]<<" ";
  	if(is_sorted(temp,k))
  	{
  		cout<<"reverse"<<endl;
  		cout<<st+1<< " " <<end+1;
		return 1;
  	}
        cout<<"no";
    return 0;
}


#include<iostream>

using namespace std;

int main()
{
	while(1){
		long int n;
	    long int arr[100001];
	 	cin>>n;
	 	if(n==0)
	 		break;
	 	long int inv[100001];
	 	for(long int i=1 ; i<=n ; i++){
	 		cin>>arr[i];
	 		inv[arr[i]]=i;
	 	}
	 	long int i;
	 	for( i=1 ; i<=n ; i++){
	 		if(inv[i]!=arr[i]){
	 			cout<<"not ambiguous"<<endl;
	 			break;
	 		}
	 	}
	 	if(i==n+1)
	 			cout<<"ambiguous"<<endl;
	}
}

#include<iostream>

using namespace std;

int findsum(int arr[],int n){
	int sum=0;
	for(int i=0 ; i<n ; i++){
	sum+=arr[i];
	}
	return sum;
}

int findmax(int arr[],int n){
	int max=arr[0];
	for(int i=1 ; i<n ; i++){
	if(max < arr[i])
		max=arr[i];
	}
	return max;
}
int main(){

	int n;
	cout<<"Enter number of elements: ";
	cin>>n;//"
	int i,arr[100];
	cout<<"Enter a sequence ";
	for(i=0 ; i<n ;i++)
		cin>>arr[i];
	int sumhash = findsum(arr,n);
	int maxhash =  findmax(arr,n);
	int hashlength = sumhash > maxhash ? sumhash : maxhash;
	int hash[100];
//	int count[n];
	memset(hash,-1,sizeof(hash));
	int sum=0;
	for(i=0; i<n ; i++){
		sum += arr[i];
		if(sum < 0)
			continue;
	//	cout<<arr[i]<<sum<<hash[sum];
		if(arr[i]==0 || sum==0 || hash[sum]!=-1)
			{
			
				cout<<"Found!";
				return 0;
			}
		hash[sum]=i;
	}
	cout<<"Not Found";
}

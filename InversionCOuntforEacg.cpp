

#include<bits/stdc++.h>

#define ll long long
#define p(a) printf("%d\n",a)
#define s(a) scanf("%d",&a)
#define sll(a) scanf("%lld",&a)
#define sl(a) scanf("%ld",&a)
#define FOR(a,b) for(int i=a ; i<=b ; ++i)

using namespace std ;


void merge(int arr[],int temp[],int left,int mid,int right , map<int,int> &hash){
	int i = left;
	int j = mid ;
	int k = left ;
	int c=0;
	while(i<=mid-1 && j<=right){
		if(arr[i]<=arr[j]){
		
			temp[k++]=arr[i] ;
			 hash[arr[i++]] += c;
		}
		else{
			temp[k++]=arr[j++];
			int l = i;
			c++;
			//	inv += (mid-i);
		}
	}
	while(j<=right)
		temp[k++]=arr[j++] , c++;

	while(i<=mid-1)
	{
		temp[k++]=arr[i] ;
		hash[arr[i++]] += c;
	
	}
	for(int l = left ; l<=right ; l++)
		arr[l] = temp[l];

}
void mergeSort(int arr[],int temp[],int left,int right,map<int , int> &hash){

	if(left < right){
		int mid = (left+right)/2;
		 mergeSort(arr,temp,left,mid,hash);
		 mergeSort(arr,temp,mid+1,right,hash);
		 merge(arr,temp,left,mid+1,right,hash);
	}
}
void mergeS(int arr[],int n,map<int ,int> &hash){
	int *temp = new int[n];
	mergeSort(arr,temp,0,n-1,hash);
}

int main() {
	ios :: sync_with_stdio(false);
	
	
	int t ;
	s(t) ;
	while(t--)
	{
		int n ;
		s(n) ;
		
		int arr[n], temp[n] ;
		FOR(0,n-1)
			s(arr[i]) , temp[i] = arr[i];
		
		map<int , int>  hash ;
		mergeS(arr,n,hash) ;
		FOR(0,n-1)
			cout<<hash[temp[i]]<<" ";
		cout<<endl;
	}
	return 0;
}




#include<iostream>

using namespace std ;


void printArray(int arr[],int n)
{
	cout<<endl;
	for(int i=0 ; i<n ; i++)
		cout<<arr[i]<<" ";
	cout<<endl;	
}

void leftRotate_bf(int arr[],int d,int n){
	int *temp = new int[d];
	int i,j=0;
	for(i=0 ; i<d ; i++)
		temp[i] = arr[i];
	for(i= d ; i<n ; i++,j++)
		arr[j] = arr[i];
	for(i=0 ; i<d ; i++)
		arr[j++]=temp[i];
}

void lR(int arr[],int n){
	int i,temp = arr[0];
	for( i=0 ; i<n-1 ; i++)
		arr[i]  = arr[i+1];
	arr[i] = temp;
}
void leftRotate_1by1(int arr[],int d,int n){
	for(int i=0 ; i<d ; i++)
		lR(arr,n);
}

int gcd(int a,int b){
	if(b==0)
		return a ;
	return gcd(b,a%b);
}
void juggler(int arr[],int d,int n){
	int g = gcd(d,n);
	for(int i=0 ; i<g ; i++){
		int j = i ,k;
		int temp = arr[i];
		while(1){
			k = j+d ;
			if(k >= n)
			 	k-=n;
			if(k==i)
				break;
			arr[j] = arr[k];
			j = k;
		}
		arr[j] = temp;
	}
}


void reverse(int arr[],int start,int end){
	while(start < end){
		int temp = arr[start];
		arr[start] = arr[end];
		arr[end] = temp ;
		start ++,end --;
	}
}
void leftRotateReverse(int arr[],int d,int n){
	reverse(arr,0,d-1);
	reverse(arr,d,n-1);
	reverse(arr,0,n-1);	
	
}

void swap(int arr[],int fi,int si,int d){
	for(int i=0 ; i<d ; i++){
		int temp = arr[fi+i];
		arr[fi+i] = arr[si+i];
		arr[si+i] = temp;
	}
}
void leftRotateBlockSwap(int arr[],int d,int n){
	int i = d ;
	int j = n-d ;
	while(i!=j){
		if(i < j){
			swap(arr,d-i,d+j-i,i);
			j = j - i;
		}
		else{
			swap(arr,d-i,d,j);
			i = i - j;
		}
		printArray(arr,n);
	}
	swap(arr,d-i,d,i);
}
void leftRotate(int arr[],int d,int n){
	//brute_force
	leftRotate_bf(arr,d,n);
	printArray(arr,n);
	//one by one
	leftRotate_1by1(arr,d,n);
	printArray(arr,n);
	//juggler
	juggler(arr,d,n);
	printArray(arr,n);
	//reverse
	leftRotateReverse(arr,d,n);
	printArray(arr,n);
	//block swap algorithm
	leftRotateBlockSwap(arr,d,n);
	printArray(arr,n);
}

int main(){
	int arr[]  = {1,2,3,4,5,6,7};
	leftRotate(arr,3,7);
}

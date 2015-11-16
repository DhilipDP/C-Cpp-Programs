 #include<iostream>
#include<stdlib.h>
#include<stdio.h>
using namespace std;

void swap(int *x,int *y){
	int temp = *x ;
	*x = *y;
	*y = temp;
}

int no_of_comparisions ;

int compare(const void * a,const void * b){
	return *(int *)a - *(int *)b;
}

int median(int a,int b,int c){
	int arr[3] = {a,b,c};
//	cout<<a<<b<<c;
	qsort(arr,3,sizeof(int),compare);
	return arr[1];
	
}
int Partition(int *arr,int l ,int r){
	int p = rand()%(r-l+1) + l;
	//no_of_comparisions += r-l-1 ;
/**	int len = r-l + 1;
	int first=arr[l] ,last=arr[r],middle ;
	if(len%2)
		middle = arr[len/2+l];
	else 
		middle = arr[len/2 -1 + l];
	int pivot= median(first,last,middle);
	int pos ;
	if(pivot ==  first)
		pos = l;
	else if(pivot == last)
		pos = r ;
	else
		pos = (len%2) ? len/2+l : len/2-1+l ;	
//	cout<<pivot<<" "<<pos;*/
	int pivot = arr[p];
	swap(&arr[l],&arr[p]);
	int i=l+1,j;
	for(j=l+1 ; j<=r ; j++){
		if(arr[j] < pivot)
			{
	//			cout<<"swapping :"<<arr[i]<<" and "<<arr[j]<<endl;
				swap(&arr[i],&arr[j]);
				i++;
			}		
	}
	//cout<<"swapping :"<<arr[i-1]<<" and "<<arr[l]<<endl;
	swap(&arr[i-1],&arr[l]);
	return i-1;
	
}

void QuickSort(int *arr,int p,int r,int n){
	int len = r-p+1;
		

	if(p<r){
		no_of_comparisions +=  len-1;	
		int q = Partition(arr,p,r);
	//	cout<<q<<endl;
	//	cout<<"Q : "<<q <<endl;
	//		if(q > p)
	//		no_of_comparisions += q-p-1;
	//	cout<<endl<<no_of_comparisions ;
		QuickSort(arr,p,q-1,n);
	//	if(r > q)
	//	no_of_comparisions += r-q-1;
	//	cout<<endl<<no_of_comparisions ;
		QuickSort(arr,q+1,r,n);
	}	
}
int main(){
		int n;
		scanf("%d",&n);
		int *arr = new  int[n];
		for(int i=0 ; i<n ; i++)
			scanf("%d",&arr[i]);
	QuickSort(arr,0,n-1,n);
	cout<<endl<<endl;
	for(int i=0 ; i<n ; i++)
		cout<<arr[i]<<" ";
	cout<<endl<<no_of_comparisions ;
	//sleep(5000);
}

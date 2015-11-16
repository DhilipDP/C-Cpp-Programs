#include<iostream>
#include<algorithm>

using namespace std;



int h_low[10000];
int h_high[10000];

int size1 ;
int size2 ;


void insert_hlow(int n){
	cout<<"Inserting "<<n<<" in hlow"<<endl;
	int i;
	size1++;
	for(i=size1; i>1 && (h_low[i/2] < n) ; i/=2)
		h_low[i]=h_low[i/2];
	h_low[i]=n;
}

void insert_hhigh(int n){
	cout<<"Inserting "<<n<<" in hhigh"<<endl;
	int i;
	size2++;
	for(i=size2; i>1 && (h_high[i/2] > n) ; i/=2)
		h_high[i]=h_high[i/2];
	h_high[i]=n;
}

int extract_max(){
	cout<<"Deleting "<<h_low[1]<<" from hlow"<<endl;
	int i,child ;
	int max = h_low[1];
	int last = h_low[size1--];
	for(i=1 ; 2*i <= size1 ; i=child){
		child = 2*i;
		if(child!=size1 && h_low[child+1] > h_low[child])
			child++;
		if(last < h_low[child])
			h_low[i]=h_low[child];
		else
			break;
	}
	h_low[i]=last ;
	return max ;
}

int extract_min(){
	
	cout<<"Deleting "<<h_high[1]<<" from hhigh"<<endl;
	int i,child ;
	int min = h_high[1];
	int last = h_high[size2--];
	for(i=1 ; 2*i <= size2 ; i=child){
		child = 2*i;
		if(child!=size2 && h_high[child+1] < h_high[child])
			child++;
		if(last > h_high[child])
			h_high[i]=h_high[child];
		else
			break;
	}
	h_high[i]=last ;
	return min ;
}
int size=0;
int arr[10000];

int myCompare(const void * a,const void *b)
{
//	cout<<"COmparing: "<<*(int *)a<<" "<<*(int *)b;
	return (*(int*)a-*(int *)b);
}
int main(){
	
	int sum = 0;
	for(int i =0 ; i<5 ; i++)
	{
		size++;
		cin>>arr[i] ;
		qsort(arr,size,sizeof(int),myCompare);
		if(size%2)
			sum += arr[size/2];
		else
			sum += arr[size/2 -1];
	}
	cout<<sum<<endl;
/*	for(int i=1 ; i<=5  ; i++){
		int num;
		cin>>num ;
		if(i==1 || num < h_low[1])
			insert_hlow(num);
		else
			insert_hhigh(num);
		if(size1 - size2 > 1)
			insert_hhigh(extract_max());
		if(size2 - size1 > 1)
			insert_hlow(extract_min());
		cout<<h_low[1]<<endl;
*/
		
}

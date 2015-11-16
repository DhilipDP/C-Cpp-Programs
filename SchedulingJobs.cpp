#include<iostream>
#include<algorithm>

using namespace std ;

struct jobs{
	float weight ;
	float length ;
	float diff ;
};

int compare(const void * a,const void * b){
	jobs * j1 = (struct jobs *) a ;	
	jobs * j2  = (struct jobs *) b ;
	if(j1->diff == j2->diff)
		return j2->weight - j1->weight ;
	return j2->diff - j1->diff ; 
}


void swap(int &a,int &b){
	int temp = a ;
	a = b;
	b = temp ;
}

void bsort(jobs *arr,int n){
	int i , j ;
	for(i=0 ; i<n ; i++){
		for(j=i+1 ; j<n ; j++){
			if((arr[i].diff == arr[j].diff) && (arr[i].weight < arr[j].weight)){
				swap(arr[i],arr[j]);
			}
			else if(arr[i].diff < arr[j].diff)
				swap(arr[i],arr[j]);
		}
	}
}
int main(){
	//int arr[15000];
	int n ;
	cin>>n ;
	int i;
	jobs arr[n];
	for(i=0 ; i<n ; i++){
		cin>>arr[i].weight>>arr[i].length;
		arr[i].diff = (float)arr[i].weight - (float)arr[i].length ;
	}
	cout<<"Size: "<<i ;
	bsort(arr,n);
//	qsort(arr,n,sizeof(arr[0]),compare);
	
	cout<<endl ;
	for(i=0 ; i<n ; i++){
		cout<<arr[i].weight<<" "<<arr[i].length<<" "<<arr[i].diff<<endl;
	}
	cout<<endl;
	long long int total_time =0 ,completion = 0;
	for(i=0 ; i<n ; i++){
	//	cout<<arr[i].weight<<" "<<arr[i].length<<" "<<arr[i].diff<<endl;
		completion += arr[i].length;
		total_time += (arr[i].weight * completion);
	}
	
	cout<<total_time ;
	
}

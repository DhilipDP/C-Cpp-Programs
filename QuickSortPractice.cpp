#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

int n;
int i_count,q_count ;


void insertion_sort(vector<int> arr ,int n){
	
	int i , j;
	for(j=1 ; j<n ; j++){
	
		for(i=0 ; i<=j-1  ; i++){
			if(arr[i] > arr[j] )
				i_count++,swap(arr[i],arr[j]);
		}
	}
}

void swap(int &a,int &b){
    int temp = a;
    a = b;
    b = temp;
    
}

int partition(vector<int> &arr,int p,int r){
	int pivot = arr[r];
	int i=p,j;
	for(j=p ; j<r ; j++){
		if(arr[j] < pivot){
			q_count++;
			swap(arr[j],arr[i]);
			i++;
		}
	}
	q_count++,swap(arr[r],arr[i]);
    return i;
}

void QuickSort(vector<int> &arr,int p,int r){
    if(p < r){
        int q = partition(arr,p,r);
     
        
        QuickSort(arr,p,q-1);
        
       
       QuickSort(arr,q+1,r);
       
    }    
}
void quickSort(vector <int>  &ar, int ar_size) {
    QuickSort(ar,0,ar_size-1);

}
int main(void) {
   vector <int>  _ar;
   int _ar_size;
cin >> _ar_size;
n=_ar_size;
for(int _ar_i=0; _ar_i<_ar_size; _ar_i++) {
   int _ar_tmp;
   cin >> _ar_tmp;
   _ar.push_back(_ar_tmp); 
}

insertion_sort(_ar,_ar_size);
cout<<i_count<<endl;
quickSort(_ar, _ar_size);
cout<<q_count<<endl;
cout<<i_count-q_count;
   
   return 0;
}


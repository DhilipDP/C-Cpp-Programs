#include<iostream>

using namespace std ;


void find_max_sum(int *arr,int n){

	int cur_max = arr[0],max_so_far = arr[0],pre_cur_max;
	int t_start=0 ,start=0 ,end=0;
	for(int i=1 ; i<n ; i++){
		pre_cur_max = cur_max;
		cur_max  =  max(arr[i],arr[i]+cur_max);
		if(cur_max == arr[i])
			start = i;
		if(cur_max < arr[start] && cur_max < pre_cur_max)
			end = i-1;
		max_so_far = max(cur_max,max_so_far);
	}	
	cout<<start<<" "<<end<<endl;
	for(int i=start ; i<=end; i++)
		cout<<arr[i]<<" ";
	cout<<endl<<max_so_far;
}
int main(){
	int arr[] = {-2, -3, 4, -1, -2, 1, 5, -3};
	int n = sizeof(arr)/sizeof(arr[0]);
	find_max_sum(arr,n);
}

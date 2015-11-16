/*#include<iostream>

using namespace std;


int lis(int *arr,int n,int * maxref)
{
	if(n==1)
		return 1;
	int res ,max_end_here=1;
	
	for(int i=1  ; i<n ; i++){
		res = lis(arr,i,maxref);
		if(arr[i-1] < arr[n-1] && res+1 > max_end_here)
			max_end_here = res + 1;
	}
	
	if(max_end_here > *maxref)
		*maxref = max_end_here;
	return max_end_here;
} 
int main(){
	int num;
	cin>>num;
	int arr[num];
	for(int i=0 ; i<num ; i++)
		cin>>arr[num];
	int maxlength=1;
	cout<<lis(arr,num,&maxlength);
}*/

#include<stdio.h>
#include<iostream>

using namespace std;

int _lis( int arr[], int n, int *max_ref)
{
    /* Base case */
    if(n == 1)
        return 1;
 
    int res, max_ending_here = 1; // length of LIS ending with arr[n-1]
 
    /* Recursively get all LIS ending with arr[0], arr[1] ... ar[n-2]. If 
       arr[i-1] is smaller than arr[n-1], and max ending with arr[n-1] needs
       to be updated, then update it */
    for(int i = 1; i < n; i++)
    {
        res = _lis(arr, i, max_ref);
        if (arr[i-1] < arr[n-1] && res + 1 > max_ending_here)
            max_ending_here = res + 1;
    }
 
    // Compare max_ending_here with the overall max. And update the
    // overall max if needed
    if (*max_ref < max_ending_here)
       *max_ref = max_ending_here;
 
    // Return length of LIS ending with arr[n-1]
    return max_ending_here;
}
 
// The wrapper function for _lis()
int lis(int arr[], int n)
{
    // The max variable holds the result
    int max = 1;
 
    // The function _lis() stores its result in max
    _lis( arr, n, &max );
 
    // returns max
    return max;
}
 
/* Driver program to test above function */
int main()
{
	int num;
	cin>>num;
	int arr[num];
	for(int i=0 ; i<num ; i++)
		cin>>arr[num];
	int maxlength=1;
	cout<<lis(arr,num);
}

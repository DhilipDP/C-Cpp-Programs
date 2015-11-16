#include<iostream>
#include<vector>

using namespace std ;

int first = -1, last =-1,size;
void binarySearch(const vector<int> A,int low,int high,int key)
{
	cout<<low<< " "<<high <<endl;
    if(low > high)
        return ;
    if(low == high)
    	return ;
    int mid = (low + high) / 2 ;
    if(A[mid]==key  && (mid-1 < 0 || (mid-1 >= low && A[mid-1] != key)) )
        first =  mid ;
    if(A[mid]==key && (mid+1 > size || ( mid+1 <=high && A[mid+1] != key)))
       last = mid;
    if(A[mid] < key)
         binarySearch(A,mid+1,high,key) ;
    else 
        binarySearch(A,low,mid,key) ;
}


int findCount( vector<int> &A, int B) {
    size = A.size()-1;

    binarySearch(A,0,A.size()-1,B) ;
if(first == -1 )
    return 0;
    return (last - first + 1);
}


int main()
{
	int arr[] = {1,1,2,2,2,3} ;
	vector<int> v(arr,arr+6) ;
	cout<<findCount(v,1);
	
}

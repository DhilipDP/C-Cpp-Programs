#include<iostream>
#include<vector>
#include<algorithm>
using namespace std ;

int main()
{
	int arr[] = {1 ,0 ,-1, 0, -2, 2};
	int n = sizeof(arr)/sizeof(arr[0]);
	vector<int> v(arr,arr+n);
	vector<vector<int> > res = fourSum(v,0);
	int size = res.size() ;
	for(int i=0 ; i<size ; i++)
	{
		for(int j=0 ; j<4 ; j++)
			cout<<res[i][j]<<" ";
		cout<<endl;
	}
}

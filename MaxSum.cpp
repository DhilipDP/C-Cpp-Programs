#include<iostream>
#include<vector>
#include<map>
#include<limits.h>
using namespace std ;

vector<int> maxiSum(vector<int> v)
{
	vector<int> res ;
	int n = v.size() ;
	if(n==0)
		return res ;
	map<int , int> hash ;
	hash[v[0]]  = 1 ;
	int cur_len = 1 , ans = INT_MIN , cur_sum = v[0] ;
	for(int i=1 ; i<n ; i++)
	{
		cout<<cur_sum<<" " ;
		int pre_index = hash[v[i]] ;
		if(pre_index==0 || (i-cur_len) > pre_index)
		{
			cur_sum += v[i] ;
			cur_len++;
		}
		else{
			cur_len = i - pre_index + 1;
			ans = max(ans,cur_sum) ;
		//	cur_sum -= v[i] ;
		}
		hash[v[i]] = i+1 ;
		cout<<ans<<endl;
	}
	ans = max(ans,cur_sum) ;
	cout<<ans<<endl;
	return res;
}

int main()
{
	int arr[] = {1,2,3,1,4,3,4,1,2} ;
	int n = sizeof(arr)/sizeof(arr[0]) ;
	vector<int> v(arr,arr+n) ;
	vector<int> res = maxiSum(v) ;
}

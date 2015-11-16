#include<iostream>
#include<vector>
using namespace std ;


int maxDist(vector<int> v)
{
	int n = v.size() ;
	if(n ==0)
		return 0;
	int lstMin[n] ;
	int lstMax[n] ;
	lstMin[0] = v[0];
	lstMax[n-1] = v[n-1] ;
	for(int i=1; i<n ; i++)
		lstMin[i] = min(lstMin[i-1],v[i]);
	for(int i=n-2 ; i>=0 ; i--)
		lstMax[i] = max(lstMax[i+1],v[i]) ;
	int i = 0 ,j = 0,res = 0;
	while(i < n && j <n)
	{
		if(lstMin[i] < lstMax[j]){
			res = max(res,j-i);
			j++;
		}
		else
			i++;
	}	
	return res;
}

int main()
{
	int arr[] = {3,4,1,6,7,8,0,1} ;
	int n = sizeof(arr)/sizeof(arr[0]) ;
	vector<int> v(arr,arr+ n) ;
	cout<<maxDist(v) ;
}

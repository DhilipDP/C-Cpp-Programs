#include<iostream>
#include<limits.h>
#include<vector>
#include<math.h>
using namespace std ;


int maxGap(vector<int> v)
{
	int n = v.size()  ;
	int mini = INT_MAX , maxi = INT_MIN ;	
	for(int i =0 ; i<n  ; i++)
		mini = min(mini , v[i]) , maxi = max(maxi,v[i]) ;
	int avg_gap = ceil(float(maxi -  mini) / (float)(n-1 ));
	
	cout<<avg_gap<<endl;
	int minim[n-1] ;
	int maxim[n-1] ;
	for(int i=-0 ; i<n-1 ; i++)
		minim[i] = INT_MAX ,maxim[i] = INT_MIN ;

	for(int i=0 ; i<n ; i++)
	{
		cout<<v[i]<< " : ";
		int pos = (v[i] - mini)/avg_gap ;
		minim[pos] = min(minim[pos],v[i]) ;
		maxim[pos] = max(maxim[pos],v[i]) ;
		cout<<pos<<" "<<minim[pos]<<" "<<maxim[pos]<<endl;
	}		
	
	int pre = maxim[0] ;
	int res = INT_MIN ;
	for(int i=1 ; i<n ; i++){
	
		cout<<i<<endl;
		if(minim[i] == INT_MAX)
			continue;
		cout<<res<<" "<<minim[i]<<" "<<pre<<endl; 
		res=  max(res,minim[i] - pre) ;
		pre = maxim[i] ;
		cout<<res<<" "<<minim[i]<<" "<<pre<<endl; 
	}
	res = max(res, maxi - pre) ;
	return res ;
}

int main()
{
	int arr[] = {67163940, 5180365, 17412933, 1372133, 3379743, 2336349, 387636 } ;
	int n = sizeof(arr)/sizeof(arr[0]) ;
	vector<int> v(arr,arr+n) ;
	cout<<maxGap(v) ;
}

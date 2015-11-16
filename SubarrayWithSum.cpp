#include<iostream>
#include<math.h>
#include<vector >
using namespace std ;


bool subarray_sum(vector<int> v , int x)
{
	int n = v.size() ;
	int cur_sum = 0 ;
	int st =  0;
	for(int i=0 ; i<n ; i++)
	{
		cur_sum += v[i] ;
		
		if(cur_sum == x)
			return true ;
		while( cur_sum > x && st < i)
			cur_sum -= v[st++] ;
		if(cur_sum==x)
			return true;
	} 
	return false ;
}

int main()
{
	int t ;
	cin>>t ;
	while(t--)
	{
		int n,x ,flag =0;
		cin>>n>>x ;
		vector<int> v (n);
		for(int i=0 ; i<n ; i++){
			int val;
			cin>>val;
			v[i] = val;
			if(val == x)
				flag=1;
				
		}
		if(flag)
		{
			cout<<"YES"<<endl;
			continue ;
		}
		
		if(subarray_sum(v,x))
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
		
		
	/*	int height = ceil(log2(n));
		int num = pow(2,height+1)-1;
		vector<int> segment_tree(num);
		constructST(segment_tree,0,n-1,v,0);
		for(int l = 2 ; l<=n && !flag ; l++)
		{
			for(int i=0 ; i<=n-l ; i++)
			{
				int j = i+l-1 ;
			//	cout<<i<<" "<<j<<" "<<getSum(v,i,j,segment_tree,0,n-1,0)<<endl;
				if(getSum(v,i,j,segment_tree,0,n-1,0) == x)
				{
			//		cout<<i<<" "<<j<<endl;
					flag = 1;
					break;
				}
			}
		}
		if(flag)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	
	
		*/
		
		}
}

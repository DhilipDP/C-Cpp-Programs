#include <iostream>
using namespace std;

int solve(int cur,int n,int h,int a,int health[],int arr[],int res)
{
	if(cur == n)
	{
		return res;
	}
	int p = solve(cur+1,n,h-health[cur],a-arr[cur],health,arr,res+1);
	int q = solve(cur+1,n,h,a,health,arr,res);
	if(p>q)
	return q;
	else
	return p;
}

int main() {
	// your code goes here
	int t,i,j;
	cin>>t;
	while(t--)
	{
		int n,h,a;
		cin>>n>>h>>a;
		int health[n],arr[n];
		for(i=0;i<n;i++)
		cin>>health[i];
		for(i=0;i<n;i++)
		cin>>arr[i];
		cout<<solve(0,n,h,a,health,arr,0)<<"\n";
	}
	return 0;
}



#include <iostream>
#include <climits>
#include <cstdio>
#include <algorithm>
using namespace std;
 
int dp[51][510][510],n;
int he[510],arr[510];
 
void init()
{
	int i,j,k;
	for(i=0;i<51;i++)
	for(j=0;j<510;j++)
	for(k=0;k<510;k++)
	dp[i][j][k]=-1;
}
 
int calc(int pos,int health,int armor)
{
	if(health<=0 || armor<=0)
	return INT_MIN;
 
	if(pos<0)
	return 0;
 
	if(dp[pos][health][armor]!=-1)
	return dp[pos][health][armor];
 
	int ans;
 
/*	if(health<=0 || armor<=0)
	{
		ans = INT_MIN;
	}
	else  */
	{
 
	ans = max(1 + calc(pos-1,health-he[pos],armor-arr[pos]) ,calc(pos-1,health,armor));
 
	dp[pos][health][armor]=ans;
	}
//cout<<ans<<" "<<pos<<" "<<health<<" "<<armor<<endl;
	return ans;
	
}
int main()
{
	int t,h,i,arm;
 
	scanf("%d",&t);
	while(t--)
{
	init();
	scanf("%d %d %d",&n,&h,&arm);
 
	for(i=0;i<n;i++)
	scanf("%d",he+i);
 
	for(i=0;i<n;i++)
	scanf("%d",arr+i);
 
	printf("%d\n",calc(n-1,h,arm));
}
	return 0;
}	
	
 
 
 


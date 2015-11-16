#include<iostream>
#include<vector>
#include<stdlib.h>
using namespace std;

int main(){
	vector<int> start ;
	vector<int> :: iterator it;
	int n,a,b,k;
	cin>>n>>a>>b>>k;
	int dp[k+1];
	memset(dp,0,sizeof(dp));
	dp[0] =0;
	start.push_back(a);
	vector<int> temp;
	for(int i=1 ; i<=k ; i++){
		 int val = dp[i-1];
		for(it = start.begin() ; it!=start.end() ; it++){
			int x = *it;
			int score = abs(x-b);
			if(score < 1 )
			{
				if(i==1){
				 dp[i] = 0;
				 goto l;
				}
			    else{
			    	dp[i-1]--;
				}
			}
			else{
				int c=0;
				int num=0;
					for(int j=x-1 ; j>=1 && num<score-1 ; j--,num++)
						temp.push_back(j),c++;
					num=0;
				//	cout<<"hello";
					for(int j=x+1 ; j<=n && num<score-1 ; j++,num++)
						temp.push_back(j),c++;//,cout<<"oh hi";
				//	cout<<"hi";
				dp[i] = dp[i-1]+ c;
				//dp[i] = ;
			}

		}
	//	cout<<"hi";
		start = temp;
	}
l:	cout<<dp[k]<<endl;
}

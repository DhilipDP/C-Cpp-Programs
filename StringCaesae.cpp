#include<iostream>
using namespace std;

int main(){
	string s = "6781234967";
	int pre[s.length()];
	pre[0] = s[0]-'0';
	for(int i=1 ; i<s.length() ; i++)
		pre[i] = pre[i-1] + (s[i]-'0');
		for(int i=0;i<s.length();i++)
			cout<<pre[i]<<" ";
			cout<<endl;
	int sum = 0;
	for(int i=0 ; i<s.length() ; i++)
	{
		for(int j=i;j<s.length() ;j++){
			if(i==0 ){
			 if(pre[j]%3==0)
				cout<<i<<" "<<j<<pre[j]<<endl,sum++;
			}
			else if((pre[j] - pre[i-1]) % 3==0)
				cout<<i<<" "<<j<<endl,sum++;
		}
	}
	cout<<sum<<endl;
	
}


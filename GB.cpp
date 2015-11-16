#include<iostream>
#include<limits.h>

using namespace std;

int main()
{
	while(1){
		int g,b;
		int ans;
		cin>>g>>b;
		if(g==-1 && b==-1)
			break;
		if(g==0 && b!=0)
			ans = b;
		else if(b==0 && g!=0)
			ans = g;
		else if(b==0 && g==0)
			ans = 0;
		else{
			int a,b;
			if(g > b){
				a=g;
			}
			else{
				a = b;
				b = g;
			}
			ans = INT_MAX;
			for(int i=1 ; (b*i) < (a+b) ; i++){
				if(((a+b) - (b*(i+1))) < ans){
					ans = (a+b) - (b*(i+1));
					cout<<ans;
				}
				else
					break;
			}
		}
		cout<<ans<<endl;
	}
}

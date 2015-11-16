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
		else if(b==g)
			ans = 1;
		else{
			int x,y;
			if(g > b){
				x=g;
				y=b;
			}
			else{
				x = b;
				y = g;
			}
			ans = INT_MAX;
		//	cout<<x+y;
			for(int i=1 ; i< (x+y)/2 && (y*(i+1)) < (x+y) ; i++){
				if(((x+y) - (y*(i+1))) < ans){
					ans = (x+y) - (y*(i+1));
		//			cout<<endl<<ans;
				}
				else
					break;
			}
		}
		cout<<ans<<endl;
	}
}

#include<iostream>
using namespace std ;

int main(){

	int t = 1;
	while(1){
		int ans = t;
		int n = 255;
		while(n--){
	//	int ans = t ;
		ans += 4;
		ans/=2;
		ans+=8;
		ans-=2;
		ans*=2;
		}
		cout<<ans<<endl;
		if(ans==4092)
		{
			cout<<t;
			break;
		}
		t++;
	}
		
}	

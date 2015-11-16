#include<iostream>
#define mod 1000000007

using namespace std ;

int main(){

	int t;
	int k;
	cin>>t>>k;
	while(t--){
		int a,b;
		cin>>a>>b;
		int sum = 0;
		for(int i=a ; i<=b ; i++ ){
			if(i==k)
				sum = (sum+2)%mod;
			else if(i < k)
				sum++;
			else {
				
				int dif = i-k;
				sum += (dif + 1+1)%mod;
				if(i%k==0)
				sum = (sum+1)%mod;
			}
		}
		cout<<sum%mod<<endl;
	
	}

}

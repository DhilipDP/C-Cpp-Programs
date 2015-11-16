#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
	int t ;
	cin>>t;
	while(t--){
		int n ;
		cin>>n;
		string ans ="";
		int five = n/3 ,three = n/5 ;
		while(five !=0){
			if((n-(five*3))%5==0)
				break;
			five--;
		}
		if(five!=0)
		{
			int rem = n -(five*3);
			for(int i=0 ; i<five*3 ; i++)
				ans += '5' ;
			for(int i=0 ; i<rem ; i++)
				ans += '3' ;
			cout<<ans<<endl;
			continue ;
		}
		if(n % 5 ==0)
		{
			for(int i=0 ; i<n ; i++)
				ans += '3' ;
			cout<<ans<<endl;
			continue;
		}
		cout<<"-1"<<endl;
		
			
	}
    return 0;
}


#include<iostream>
#include<vector>
#include<stdio.h>
#include<stack>
#include<vector>
#include<queue>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<limits.h>
#include<map>
#include<algorithm>


#define ll long long
#define p(a) printf("%d\n",a)
#define s(a) scanf("%d",&a)
#define sll(a) scanf("%lld",&a)
#define sl(a) scanf("%ld",&a)
#define FOR(a,b) for(int i=a ; i<=b ; ++i)

using namespace std ;

int main() {
	int t;
	s(t);
	while(t--){
		for(int k=1000000 ; k< 10000000; k++){
	//	int n ;
	//	s(n);1
	cout<<k<<endl;
	   int n = k;
		string ans ;
		string arr[] = {"0","P","Q","Pq","Pp"};
		if(n < 5)
		{
			cout<<arr[n]<<endl;
			continue ;
		}
		vector<int> v;
		while(n > 0){
		//	cout<<"hi";
			v.push_back(n%5);
			n /= 5 ;
		//	cout<<n<<endl;
		}
	//	reverse(v.begin(),v.end());
		int carry =0;
		for(vector<int> :: iterator it = v.begin() ; it!=v.end() ; it++){
		//	cout<<*it<<endl;
			int i=*it ;
			int sum = (i+carry);
			if(sum <= 2)
				carry=0,ans += arr[sum];
			else {
				if(sum==5)
					ans += "0";
				else if(sum==4)
					ans += "p";
				else
					ans += "q";
				carry = 1;
			
			}
		//		cout<<ans<<endl;
		}
		if(carry==1)
			ans += "P";
		reverse(ans.begin(),ans.end());
	//	cout<<ans<<endl;
		
		int num = ans.length() ;
		int sum = 0;
		int l=0;
		for(int j=num-1 ; j>=0 ; j--){
			if(ans[j]=='Q')
				sum += (2 * pow(5,l)); 
			
			if(ans[j]=='P')
				sum += (1 * pow(5,l));
				
	
			if(ans[j]=='p')
				sum += (-1 * pow(5,l));
				
			
			if(ans[j]=='q')
				sum += (-2 * pow(5,l));
			l++;
		}
	//	cout<<sum<<endl;
		if(sum!=k){
			cout<<"Wrong: "<<k<<endl;
			break;
		}
	}
	}
	return 0 ;
}

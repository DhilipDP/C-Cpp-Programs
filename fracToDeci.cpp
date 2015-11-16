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
#include<string>
#include<algorithm>
#include<utility>


#define ll long long
#define p(a) printf("%d\n",a)
#define s(a) scanf("%d",&a)
#define sll(a) scanf("%lld",&a)
#define sl(a) scanf("%ld",&a)
#define FOR(a,b) for(int i=a ; i<=b ; ++i)
#define pi pair<int,int> 

using namespace std ;
 string to_string(int val){
 	if(val==0)
 		return "0";
 	string ans="";
 	while(val > 0){
 		ans += (val%10 + '0');
 		val /= 10;
 	
	 }
	 reverse(ans.begin(),ans.end());
	 return ans ;
 }

   string fractionToDecimal(long long int num, long long int den) {
  	string frac = "";
  	if(num == 0)
  		return "0";
  	if(num<0 ^ den<0)
  		frac += "-";
  	num = abs(num) ;
  	den = abs(den);
  long long	int quo = num/den ;
  	long long int rem = num%den ;
	 frac +=  to_string(quo);
	 if(rem==0)
	 	return frac;	 
	frac += ".";
	map<long long int,long long int>  m;
	//cout<<frac<<endl;
	for(long long int r = num%den ;  r!=0 ; r = r%den){
		if(m[r]!=0){
			frac.insert(m[r],"(");
			frac += ')';
			break;
		}
		m[r] = frac.size() ;
		r =  r*10;
		frac += to_string(r/den);
	}
	return frac ;
  }
  int main() {
	cout<<fractionToDecimal(-1,INT_MIN);
	return 0 ;
}

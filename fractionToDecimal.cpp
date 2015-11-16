#include<stdio.h>
#include<algorithm>
#include<limits.h>
#include<stdlib.h>
#include<iostream>
using namespace std ;


string to_string(long long int num)
{
	if(num==0)
		return "0";
	string s="";
	while(num > 0)
	{
		s += num%10 + '0';
		num /=10;
	}
	reverse(s.begin(),s.end());
	return s;
}
string fractionToDecimal(int num,int den)
{
	
	if(num==INT_MIN ){
		if(den==1)
		return "-2147483648";
			return "2147483648";
	}
	bool neg = false;
	if(num < 0 && den <0)
		neg = false;
	else if(num < 0 || den < 0)
		neg = true;
	//num = abs(num) ;
	//cout<<num<<endl;
	//den = abs(den) ;
	string ans;
	if(num==0)
		return "0";
	long long int n = abs(num) ;
	long long int d = abs(den) ;
	ans += to_string(n/d);
	printf("%lld",d);
	int hash[10]  ;
	memset(hash,-1,sizeof(hash));

	int rem = n%d ;
	string deci = "";
	string r = to_string(rem);
	r += "0";
	int i=0;
	while( rem != 0)
	{
		int quo = atoi(r.c_str())/den ;
		//cout<<hash[quo]<<endl;
		if(hash[quo] != -1){
				deci.insert(hash[quo],"(");
				deci += ")";
			break;
		}
		else
		deci += to_string(quo);
		rem = atoi(r.c_str()) % den ;
		r = to_string(rem) + "0";
		//cout<<deci<<endl;
		hash[quo] = i++;
	}
	if(neg)
		ans = "-" + ans;
	if(deci=="")
		return ans;
	return ans + "." + deci;
}


int main()
{
	cout<<fractionToDecimal(-1,-2147483648);
}

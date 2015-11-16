#include<stdio.h>
#include<iostream>
#include<algorithm>

using namespace std ;



string add(string a,char b){
	int carry = 0;
	reverse(a.begin(),a.end());
	string sum ="";
	long long int len1 = a.length();
	for(long long int i=0 ; i < len1; i++){
		int n1 = i<len1 ? a[i]-'0' : 0;
		int n2 = i<1 ? b-'0' : 0;
		int s = (n1+n2+carry)%10;
		carry = (n1+n2+carry)/10;
		sum.push_back(s+'0');	
	}
	if(carry)
		sum.push_back(carry + '0');
	reverse(sum.begin(),sum.end());
	return sum;
}
string getSum(string number){
	string sum = "0";
	long long i =0;
	while(number[i]){
		sum = add(sum,number[i]);
		//cout<<sum<<endl;
		i++;
	}
	return sum ;
}
int main(){
	int t ;
	scanf("%d",&t);
	while(t--){
		string number ;
		cin>>number;
		string sum = getSum(number);
		while(sum.length()!=1){
			sum = getSum(sum);
		}
		cout<<sum<<endl;
	}
	
	return 0;
}

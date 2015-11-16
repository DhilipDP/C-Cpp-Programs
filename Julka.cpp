#include<iostream>
#include<algorithm>
using namespace std;


string addition(string s1,string s2){
	int carry = 0;
	string result;
	reverse(s1.begin(),s1.end());
	reverse(s2.begin(),s2.end());
	for(unsigned long long int i=0 ;s1[i] || s2[i] ; i++) {
		int d1 = s1.length() > i ? s1[i]-'0' :0; 
		int d2 = s2.length() > i ? s2[i]-'0' :0;
		int sum = (d1+d2+carry)%10;
		carry = (d1+d2+carry)/10;
		result.push_back(sum+'0');  
	}
	if(carry)
		result.push_back(carry+'0');
	reverse(result.begin(),result.end());
	return result;
}

string sub(string s1,string s2)
{
	string result;
//	int len=len1>len2?len1:len2;
	reverse(s1.begin(),s1.end());
	reverse(s2.begin(),s2.end());
	for(unsigned long long int i=0;s1[i] || s2[i];i++)
	{
	int d1=s1.length()>i?s1[i]-'0':0;
	int d2=s2.length()>i?s2[i]-'0':0;
	int ans = (d1-d2);
	if(ans < 0){
	 int j=i+1;
	 while((s1[j]-'0') == 0){
	  s1[j]= (9)+ '0';
	  j++;
	 }
	 s1[j]--;
	 d1 = d1 + 10;
	 ans = (d1-d2)%10;
	}
	result.push_back(ans+'0');
	}
	reverse(result.begin(),result.end());
	return result;
}

string ans ="";
string division(string s1){
	int quo = s1[0]-'0';
	for(unsigned long long int i = 1 ;s1[i] ; i++){
		int quo = quo / 2;
		int rem = s1[i]-'0' % 2;
		if(quo==0 && s[i+1])
			quo = quo*10 + s[i+1];
		else
		ans += division(quo);
			
		
	}
}
int main(){
	int i;
	string ans = sub("312","23");
	for( i=0 ; ans[i]-'0'==0 ; i++);
	cout<<ans.substr(i,ans.length()-i);
	for(int t=0 ;t<9 ; t++){
		string total;
		string diff;
		string sum = addition(total,diff);
	}
}

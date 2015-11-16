#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<stdlib.h>
using namespace std;


string addition(string s1,string s2)
{string result;
int len1=s1.length();
int len2=s2.length();
int carry=0;
int len=len1>len2?len1:len2;
reverse(s1.begin(),s1.end());
reverse(s2.begin(),s2.end());
for(int i=0;i<len;i++)
{
int d1,d2;
d1=len1>i?s1[i]-'0':0;
d2=len2>i?s2[i]-'0':0;
int ans=(d1+d2+carry)%10;
carry=(d1+d2+carry)/10;
result.push_back(ans+'0');
}
if(carry>0)
result.push_back(carry+'0');
reverse(result.begin(),result.end());
return result;
}
string sub(string s1,string s2)
{

string result;
int len1=s1.length();
int len2=s2.length();
int len=len1>len2?len1:len2;
reverse(s1.begin(),s1.end());
reverse(s2.begin(),s2.end());
for(int i=0;i<len;i++)
{
int d1=len1>i?s1[i]-'0':0;
int d2=len2>i?s2[i]-'0':0;
int ans = (d1-d2) % 10;
if(ans < 0){
 int j=i+1;
 while((s1[j]-'0') == 0){
  s1[j]= 9 + '0';
  j++;
 }
 s1[j]--;
 d1 = d1 + 10;
 ans = (d1-d2)%10;
}
result.push_back(ans+'0');
}
reverse(result.begin(),result.end());
int k=0;
for(int i=0 ; result[i] ; i++){
	if(result[i]-'0'==0)
		k++;
	else
		break;
}
if(k < result.length())
result = result.substr(k,result.length()-k);
return result;
}

string fibonacci(string number1)
{
	if(number1.length()==1 && number1[0]-'0'==0)
		return "0";
	if(number1.length()==1 && number1[0]-'0'==1)
		return "1";
	string n1 = sub(number1,"1");
	string n2 = sub(number1,"2");
	//cout<<n1<<" "<<n2;
	return addition(fibonacci(n1),fibonacci(n2));
}
int main()
{
//	cout<<sub("2","2");
	//cout<<sub("11","1");
	int tests;
	scanf("%d",&tests);
	while(tests--){
	string st1,st2;
	cin>>st1>>st2;
	string output="0";
	string  r =sub(st2,st1);
	long long int range = atol(r.c_str()); 
	for(long long int i=0 ; i<=range ; i++){
		string s;
		if(i!=0)
		{
		string val="";
		long long int temp = i;
		while(temp>0){
			val.push_back(temp%10 + '0');
			temp=temp/10;
		}
		reverse(val.begin(),val.end());
		 s =  fibonacci(addition(st1,val));
		}
		else{
		//	cout<<"hello: ";
			s = fibonacci(st1);
		}//cout<<s<<" ";
		output = addition(output,s);
	//	cout<<endl<<output<<" ";
	}
//	cout<<output<<endl;
//	cout<<sub("6","1")<<endl<<sub("6","2")<<endl<<addition("5","3");
	cout<<atol(output.c_str()) % 1000000007<<endl;
	}
	
}


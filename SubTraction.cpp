#include<iostream>
#include<algorithm>
using namespace std ;

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
  s1[j]=  9 + '0';
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

int main(){
	cout<<sub("32","42");
}

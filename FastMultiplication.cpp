#include<iostream>
#include<conio.h>
#include<string>
#include<math.h>
#include<string.h>
#include<algorithm>
using namespace std;
int myswitch(char c)
{
    if(c>='0'&&c<='9')
    return (c-'0');
    else
    return (c-'0'-7);
}
string add(string s1,string s2,int base)
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
if(base>10)
{
d1=len1>i?myswitch(s1[i]):0;
d2=len2>i?myswitch(s2[i]):0;
}
else
{
d1=len1>i?s1[i]-'0':0;
d2=len2>i?s2[i]-'0':0;
}
int ans=(d1+d2+carry)%base;
carry=(d1+d2+carry)/base;
result.push_back(ans+'0');
}
if(carry>0)
result.push_back(carry+'0');
reverse(result.begin(),result.end());
return result;
}
int makeEqualLength(string &str1, string &str2)
{
    int len1 = str1.size();
    int len2 = str2.size();
    if (len1 < len2)
    {
        for (int i = 0 ; i < len2 - len1 ; i++)
            str1 = '0' + str1;
        return len2;
    }
    else if (len1 > len2)
    {
        for (int i = 0 ; i < len1 - len2 ; i++)
            str2 = '0' + str2;
    }
    return len1; 
}
string generate(string s,int power)
{
      //  string answer="1";
       for(int i=0;i<power;i++)
       {
               s=s+'0';
       }
       return s;
}
string sub(string s1,string s2,int base)
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
int ans = (d1-d2) % base;
if(ans < 0){
 int j=i+1;
 while((s1[j]-'0') == 0){
  s1[j]= (base-1)+ '0';
  j++;
 }
 s1[j]--;
 d1 = d1 + base;
 ans = (d1-d2)%base;
}
result.push_back(ans+'0');
}
reverse(result.begin(),result.end());
return result;
}
int i=0;
string multiply(string s1,string s2)
{   		i++;
       string answer;
       if(s1=="1")
       		return s2;
       else if(s2=="1")
       		return s1;
       if(s1=="0"||s2=="0")
       {
       answer="0";
       return answer;
       }
       int maxlen=makeEqualLength(s1,s2);
       if(maxlen==0)
       {
                    return 0;
       }
	   if(maxlen==1)
       {
    		   int a=((s1[0]-'0')*(s2[0]-'0'));
    		   while(a>0)
   			 {
                int d=a%10;
              	answer.push_back(d+'0');
                a=a/10;
    		}		
    		reverse(answer.begin(),answer.end()); return answer;
       }
       int m1,m2;
       m1=maxlen/2;
       m2=maxlen-m1;
       string high1=s1.substr(0,m1);
       string low1=s1.substr(m1,m2);
       string high2=s2.substr(0,m1);
       string low2=s2.substr(m1,m2);
       string z0=multiply(low1,low2);
       string z1=multiply(add(low1,high1,10),add(low2,high2,10));
       string z2=multiply(high1,high2);
       string part1 = generate(z2,2*m2);
  	   string part2=generate(sub(sub(z1,z2,10),z0,10),m2);
       answer=add(add(part1,part2,10),z0,10);
       return answer;
}


int main()
{
	int tests;
	cin>>tests;
	while(tests--)
	{
   	 string s1,s2;
   	 for(int i=0;i<999;i++)
   	 {
   	 	s1+='1';
   	 	s2+='1';
    }
    // cin>>s1>>s2;
  	 string s3=multiply(s1,s2);
  	 int k;
  	 int i=0;
	while((s3[i]-'0')==0)
	i++;
	cout<<s3.substr(i,s3.length()-i);
	cout<<endl;
	}	
	return 0;
}

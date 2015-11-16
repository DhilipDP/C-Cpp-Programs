#include<stdio.h>
#include<conio.h>
#include<iostream>
#define ull unsigned long long int 
#define ll long long int 

using namespace std;
int main()
{
 int q=0;
 for(int i=100000;i<=999999;i++)
 {
  int temp=i;
  int one=temp%10;
  temp/=10;
  int two=temp%10;
  temp/=10;
  int three=temp%10;
  temp/=10;
  int four=temp%10;
  temp/=10;
  int five=temp%10;
  temp/=10;
  int six=temp%10;
  //cout<<six<<five<<four<<three<<two<<one<<endl;
  int r =  four*100+five*10+six;
  if(r != 0 && (one*100+two*10+three)%r==0)
  {  
   int a=(one*10 +two);
   int b=three*10+four;
   int c=five*10+six; 
   if(b!=0&& a % b== c)
   		cout<<i<<endl,q++;
 }
 }
 cout<<q<<endl;}
 
 

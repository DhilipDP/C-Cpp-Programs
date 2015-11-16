#include<iostream>
#include<string.h>

using namespace std;
int check(string str)
{    cout<<'\n'<<str;
    int cnt=0;
char arr[]={0,1,2,3,4,5,6,7,8,9,'A','B','C','D','E','F'};
for(int i=0;str[i]!='\0';i++)
{
for(int j=0;j<=15;j++)

{
if((str[i]-'0'==arr[j])||(str[i]==arr[j]))
 ++cnt;   
} 
} 
int length=str.length();
//cout<<'\n'<<length;
if(cnt==length)
  
  return 1;
  
  else
      return 0;
}

string htob(string ch)
{
string binary="";
for(int i=0;i<ch.length();i++)
{

switch(ch[i])
{
case '0':binary.append("0000");break;
case '1':binary.append("0001");break;
case '2':binary.append("0010");break;
case '3':binary.append("0011");break;
case '4':binary.append("0100");break;
case '5':binary.append("0101");break;
case '6':binary.append("0110");break;
case '7':binary.append("0111");break;
case '8':binary.append("1000");break;
case '9':binary.append("1001");break;
case 'A':binary.append("1010");break;
case 'B':binary.append("1011");break;
case 'C':binary.append("1100");break;
   case 'D':binary.append("1101");break;
   case 'E':binary.append("1110");break;
   case 'F':binary.append("1111");break;
}

} return binary;
}

void btoh(string calc)
{
string hex,chr;
chr=hex="";
int len=calc.length();
   for(int i=0;i<len;i+=4)
   {
   	chr=calc.substr(i,4);
   	if(chr=="0000")
   	    hex.append("0");
   	else if(chr=="0001")
   	    hex.append("1");
   	else if(chr=="0010")
   	    hex.append("2");
   	else if(chr=="0011")
   	    hex.append("3");
       else if(chr=="0100")
           hex.append("4");
       else if(chr=="0101")
           hex.append("5");
       else if(chr=="0110")
            hex.append("6");
       else if(chr=="0111")
           hex.append("7");
       else if(chr=="1000")
            hex.append("8");
       else if(chr=="1001")
            hex.append("9");
       else if(chr=="1010")
             hex.append("A");
       else if(chr=="1011")
             hex.append("B");
       else if(chr=="1100")
           hex.append("C");
       else if(chr=="1101")
            hex.append("D");
       else if(chr=="1110")
            hex.append("E");
       else
            hex.append("F");
   } cout<<"\nENCRYPTED VALUE IN HEXADECIMAL FORM:"<<hex;
}
void encrypt(string data,string pad)

{
string flag,temp,calc;
   calc="";
 	flag=htob(data);
 	cout<<"\nBINARY FORM OF DATA:"<<flag;
 	temp=htob(pad);
 	cout<<"\nBINARY FORM OF PAD:"<<temp;
 	int len=flag.length();
 	for(int j=0;j<len;j++)
 {
 	if(flag[j]==temp[j])
 	  calc.append("0");
 	else
 	    calc.append("1");
 }  	
  cout<<"\nENCRYPTED VALUE IN BINARY FORM:"<<calc;
  btoh(calc);

}





int main()
{
string data,pad;
int i;
cout<<"ENTER THE STRINGS";
cout<<"\n DATA STRING:";
cin>>data;
cout<<"\nPAD STRING:";
cin>>pad;
cout<<data<<'\n'<<pad;
int len=data.length();
int len1=pad.length();
if(len==len1)
{
for(i=0;data[i]!='\0';i++)
{
data[i]=toupper(data[i]);
pad[i]=toupper(pad[i]);
} 
 int i=check(data);
  cout<<"\n return value of data:"<<i;
 int j=check(pad);
  cout<<"\n return value of pad:"<<j;
  
    if(i&&j)
    {
    encrypt(data,pad);
    }
     

}
else
  cout<<"\n INVALID";
return 0; 
}

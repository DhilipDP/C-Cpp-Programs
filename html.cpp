#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;
int getwrongtags(string sent)
{  int i,tag,flag;
       tag=0;
	   flag=0;
    int len=sent.length();
    if(sent.empty())
    {
    	return -1;
    }
    else
    {
    
   for(i=0;i<len;i++)
   {    
       if(sent[i]=='<')
            ++tag;
       else if(sent[i]=='>'&&tag!=0)
            --tag;
       else if(tag==0 && sent[i]=='>')
             ++flag;
            
   }
} int tot=tag+flag;
 return tot;
     
   }
int main()
{
//	char sent[99];	cout<<"enter the string";
//	cin.getline(sent,98);
  int tag=getwrongtags("< Top < financial leaders, < faced >>>with > << the biggest crisis tohit the global economy in at least a decade, are pledging to strengthen theirregulation of banks in the United States will be a short one.");
   cout<<"WRONG TAGS:"<<tag;
	return 0;
}

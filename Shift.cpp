#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
 
int main() {
	// your code goes here
	int t,s,len,i,p;
	char arr[20000];
	cin>>t;
	while(t--)
	{
		cin>>arr;
		cin>>s;
		len = strlen(arr);
		for(i = 0;i<len;i++)
		{
			if('a'<=arr[i] && 'z'>=arr[i])
			{
				
				p = arr[i]-97;
				
				if(p+s<26)
				{
				
					printf("%c",'a'+p+s);
				}
				else
				{
					p = (p+s)-26;
					printf("%c",'A'+p);
				}
			}
			else
			{
				p = arr[i]-65;
				
				if(p+s<26)
				{
				
					printf("%c",'A'+p+s);
				}
				else
				{
					p = (p+s)-26;
					printf("%c",'a'+p);
				}
			}
			
		}
		cout<<"\n";
	}
	return 0;
} 

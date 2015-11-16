#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std; 
int main(){
    char s[100];
    while((fgets(s,100,stdin))!=NULL)
    {
    	int n=strlen(s);
    	int c=0;
    	for(int i=0;i<n;i++)
    	{
    		if(s[i]!='\0')
    		{
    			c++;
    		}
    	}
    	int m=c; 
    	int w=0;
    	for(int i=0;i<n;i++)
    	{
    		if(s[i] == ' ')
    		{
    			w++;
    		}
    	}
    //	cout<<w;
    	int res = c/w;
		//cout<<res<<"\n";
		if(res <= 3)
		{
			cout<<"250\n";
		}
		if((res == 4) || (res == 5))
		{
			cout<<"500\n";
		}
		if(res >= 6)
		{
			cout<<"1000\n";
		}
	}
}

#include<iostream>
using namespace std;
#include<string.h>
#include<stdio.h>
#define num 1000 

void stringrev(char arr[],int nu)
{  
	arr[strlen(arr)-1] = '\0';
    int i,j=strlen(arr);
	
    char tem[num][num];
    int k=0,m=0;
    for(int n=0;n<j;n+=m)
    { i=n;
      m=0;
       while(arr[i]!=' ' && arr[i]!='\0')
    {
    	tem[k][m++]=arr[i++];
    	
    }
	tem[k][m]=' ';
	m=m+1;
	k++;
    }
    int times;
    for(int t=k-1;t>=0;t--)
    {  strrev(tem[t]); //instead of this u can use the reverse in the previous pgm
    times=0;
    	while(times<nu)
    	{
    		
    		printf("%s",tem[t]);
    		times++;
		}
	}
}
int main()
{  int n;
  
	char arr[100];
	fgets(arr,100, stdin);
  	
	
	printf("\n enter the number of times to be repeated: ");
  scanf("%d",&n);
  	
  	cout<<arr<<endl;
  
    stringrev(arr,n);
	return 0;
}

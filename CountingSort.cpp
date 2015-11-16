#include<iostream>
#include<strings.h>
#include<stdlib.h>

using namespace std;


void CountSort(char str[]){
	int count[256],i;
	memset(count,0,sizeof(count));
	for(i=0 ; str[i] ; i++){
			count[str[i]]++;
	}
	for(i=1 ; i<=256 ; i++)
		count[i] += count[i-1];
	char output[strlen(str)];
	for(i=0 ; str[i] ; i++)
		{
			output[count[str[i]]-1]=str[i];
			count[str[i]]--;
		//	cout<<"Output["<<count[str[i]]<<"] =" <<str[i];//]
		}
	for(i=0 ; str[i] ; i++)
		str[i]=output[i];
	cout<<endl<<str;
		
}
int main()
{
	char str[100];
	cout<<"Emter a  string: ";
	cin>>str;
	CountSort(str);
	
}

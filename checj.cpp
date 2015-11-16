#include<stdio.h>
#include<iostream>

using namespace std;
int main()
{
	FILE *fp = fopen("out.txt","r");
	FILE *fp1 = fopen("op.txt","r");
	char a[10000],b[10000];
	int i=1;
	while((fscanf(fp,"%s",a))!=EOF){
		fscanf(fp1,"%s",b);
		string s1(a);
		string s2(b);
		
		if(s1 != s2){
			cout<<i<<" : ";
			cout<<"Wrong"<<endl;
			cout<<s1<<" "<<endl<<s2<<endl;
			break;
		}
	//	else
	//		cout<<"Right"<<endl;
	i++;
	}
}

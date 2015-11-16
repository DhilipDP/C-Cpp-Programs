#include<iostream>

using namespace std;

int main()
{
	int tests,j=0;
	cin>>tests;
	while(tests--){
	 j++;
		char  str[100];
		cin.getline(str,100);
		string vowel="",consonant="";
		int length = strlen(str);
		cout<<length;
		for(int i=0 ; str[i]!='\n' ; i++){
			if(str[i]!=' '){
				if(str[i]=='a' || str[i]=='A' || str[i]=='e' || str[i]=='E' ||str[i]=='i' ||str[i]=='I' ||str[i]=='o' ||str[i]=='O' ||str[i]=='u' ||str[i]=='U')
					vowel += str[i];
				else
					consonant += str[i];
			}
	    
		}
		cout<<"Case "<<j<<":"<<endl<<vowel<<endl<<consonant<<endl<<endl;
	
	}
}

#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std ;

int main(){
	int t;
	cin>>t;
	t++;
	int i=0;
	while(t--){
		char arr[1001];
		gets(arr);
		if(i==0)
			{
				i++;
				continue;
			}
		string s(arr);
	//	cout<<s<<endl;
		
		int n = s.length(),i;
		for(int i=0 ; i<n ; i++)
			if(isalpha(s[i]))
				s[i] += 3;
		reverse(s.begin(),s.end());
		int st = n%2 ? n/2 : n/2 + 1;
		for(i = n/2 ; i<n ; i++)
			s[i]--;
		cout<<s<<endl;
	}
}

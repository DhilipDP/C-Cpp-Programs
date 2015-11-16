#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	int ite;
	scanf("%d",&ite);
	char s[100002];
	while(ite--){
		int n;
		scanf("%d",&n);
		scanf("%s",s);
		//printf("%s\n",s);
		n/=2;
		for(int i=0;i<n;i++){
			if(s[i]>s[i+n]) swap(s[i],s[i+n]);
			int s1 = s[i+n]-s[i], s2= abs('z'-s[i+n] + s[i]-'a'+1);
			if(s2<=s1)
				cout<<"hey",s[i]=s[i+n]='a';
			else if(s[i]>s[i+n])
					cout<<"hie",s[i]=s[i+n];
				else
					cout<<"hi",s[i+n]=s[i];
		  cout<<s<<endl;
		}
		printf("%s\n",s);
	}
	return 0;
}

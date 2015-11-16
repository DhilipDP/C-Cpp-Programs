#include<iostream>
using namespace std ;



int getValue(string key, string code) {
	int hash[256]={-1};
	memset(hash,-1,sizeof(hash));
	int i;
	int res=0;
	for(i=0;i<key.length() ;i++)
		hash[key[i]]=(i+1)%10;
	for(i=0;i<code.length();i++){
		cout<<hash[code[i]]<<endl;
		if(hash[code[i]]!=-1)
			res = res*10 + hash[code[i]],cout<<i<<" "<<res<<endl;
		}
		
	return res;
}

int main()
{
	cout<<getValue("TRADINGFEW","LGXWEV");
}

#include<iostream>
#include<stdio.h>

using namespace std;

int main(){
	while(1){
		string number;
		cin>>number;
		if(number.length()==1 && number[0]-'0'==0)
			break;
		int len = number.length();
		long long table[len+1];
		table[0]=table[1]=1;
		for(int i=2 ; i<=len ;  i++){
			table[i]=0;
			int n1 = number[i-2]-'0',n2 = number[i-1]-'0';
			if(n1==1 || (n1==2 && n2<=6 ))
				table[i] += table[i-2];
			if(n2!=0)
				table[i] += table[i-1];
		}
		printf("%lld\n",table[len]);
	}
}

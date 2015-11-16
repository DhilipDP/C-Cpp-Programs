#include<iostream>
#include<stdio.h>

using namespace std;

int gcd(int a,int b){
	if(a<b)
		return gcd(b,a);
	if(b==0)
		return a;
	return gcd(b,a%b);
}


int findModulus(int a,string b){
	int m = b[0]-'0';
	int i=0,d;
	while(b[i]){
		d = m % a;
		if(b[i+1])
			m = (10*d) + (b[i+1]-'0');
		i++;
	}
	return d;
}
int main(){
	int tests;
	scanf("%d",&tests);
	while(tests--){
		int a;
		string b;
		scanf("%d",&a);
		cin>>b;
		if(a==0)
			cout<<b;
		else
//		cout<<findModulus(a,b)<<endl;
		printf("%d\n",gcd(a,findModulus(a,b)));
	}
}

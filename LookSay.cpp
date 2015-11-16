#include<iostream>
#include<stdio.h>
using namespace std;


string temp;

void insert(int count){
	if(count < 10)
		temp.push_back(count+'0');
	else{
		bool last = false;
		if(count%10==0)
			last = true;
		int t = count,rev=0;
		while(t>0){
			int rem = t % 10;
			rev = (10*rev)+ rem;
			t/=10;
		}
		while(rev > 0){
			int d= rev%10;
			temp.push_back(d+'0');
			rev/=10;
		}
		if(last)
			temp.push_back(0+'0');
}
}
int main(){
	int tests;
	scanf("%d",&tests);
	while(tests--){
		string s;

		string number;
		cin>>number;
		int count=0;
		int i;
		char c;
		for(i=0 ; number[i] ; i++){
			if(i==0){
				count=1;
				c=number[i];
			}
		    else	if(number[i]==c)
				count++;
			else{
				insert(count);
			//	cout<<temp<<endl;	
				temp.push_back(number[i-1]);
				//cout<<temp<<endl;
				count=1;
				c=number[i];
			}
		}
	//	cout<<endl<<count<<" ";
		insert(count);
		temp.push_back(number[i-1]);
			cout<<temp<<endl;
		temp="";
	
	}
}

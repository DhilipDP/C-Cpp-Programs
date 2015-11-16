#include<iostream>
#include<vector>
#include<stack>

using namespace std;

struct node{
	string s ;
	int p;
};

int main(){
	string str ;
	vector<node> code;
	stack<int>  add;
	int val;
	int i=0;
	while(true){
		cin>>str;
		if(str=="END")
			break;
		node n ;
		n.s = str;
		n.p=0;
		if(n.s=="LOOPBEGIN")
		{
			add.push(i);
		}
		if(n.s=="LOOPEND"){
			 int val = add.top();
			 code[val].p = i;
			 n.p = val;
			 add.pop();
		}
		code.push_back(n);
		i++;
		
	}
	int n = i;
	int stream[30003] ={0};
	int fc = 0;
	for(i=0 ; i<n ; i++){
		if(code[i].s=="MOVERIGHT")
			fc++;
		else if(code[i].s=="MOVELEFT")
			fc--;
		else if(code[i].s=="INC")
			stream[fc]++;
		else if(code[i].s=="DEC")
			stream[fc]--;
		else if(code[i].s=="OUTPUT")
			cout<<(char)stream[fc];
		else if(code[i].s=="LOOPBEGIN"){
			if(stream[fc]=='0')
				i = code[i].p ;
		}
		else if(code[i].s=="LOOPEND")
			if(stream[fc]!='0')
				i = code[i].p ;
	}
	
}

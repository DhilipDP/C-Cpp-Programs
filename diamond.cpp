#include<iostream>
#include<stack>
#include<bitset>
using namespace std ;


struct character{
	char c;
	int index ;
};
int main(){
	int t ;
	cin>>t ;
	while(t--){
		string diamond ;
		
		cin>>diamond ;
		int good=0,bad = 0;
		stack<character> s ;
		int n = diamond.length(),i ;
		if(n==0){
			cout<<"0 0"<<endl;
			continue ;
		}
		bitset<3000> correct;
		correct.reset() ;
		for(i=0 ; i<n ; i++){
			if(diamond[i]=='<'){
				character p ;
				p.c = '<' ;
				p.index = i;
				s.push(p);
			}
			else if(diamond[i]=='>'){
				if(!s.empty() && s.top().c == '<'){
					good++,correct[s.top().index]=1,correct[i]=1;
					s.pop();
				}
			}
		}
	//	for(i=0 ; i<n; i++)
	//		cout<<correct[i]<<" " ;
		for(i=0 ; i<n ; i++){
			if(!correct[i] && diamond[i]=='>') {
				if(i+1 < n && !correct[i+1] && diamond[i+1] == '<')
					bad++;
			}
		}
		cout<<good<<" "<<bad<<endl;
	}

}


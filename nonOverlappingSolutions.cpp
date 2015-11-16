#include<iostream>
#include<stack>
#include<algorithm>
using namespace std ;


struct Intervals{
	int start ;
	int end ;
};

bool comp(const Intervals &a,const Intervals &b ){
	return a.start < b.start ;	
}

int main(){
	int n = 5 ;
	Intervals intr[n] ;
	intr[0].start = 5 ;
	intr[0].end = 7 ;
	intr[1].start = 1 ;
	intr[1].end = 6 ;
	intr[2].start = 2 ;
	intr[2].end = 4 ;
	intr[3].start = 10;
	intr[3].end = 14 ;
	intr[4].start = 8 ;
	intr[4].end = 9 ;
	sort(intr,intr + n , comp);
	stack<Intervals> st ;
	st.push(intr[0]);
	for(int i=1 ; i<n ; i++){
		cout<<i<<endl;
		Intervals it = st.top();
		if(intr[i].start > intr[i-1].end){
		//	cout<<"\npushing: "<<intr[i].start<<" "<<intr[i].end<<endl;
			st.push(intr[i]);
		}
		else if(intr[i].end > it.end )
		{
			st.pop();
			it.end = intr[i].end ;
		//		cout<<"\npushing: "<<it.start<<" "<<it.end<<endl;
			st.push(it) ;
		}
	/*	cout<<"Stack\n";
			while(!st.empty()){
				cout<<st.top().start <<" "<<st.top().end<<endl;
				st.pop();
		}
		break ; */
	}
	cout<<"\nNon Overlapping Intervals:\n";
	while(!st.empty()){
		cout<<st.top().start <<" "<<st.top().end<<endl;
		st.pop();
	}
	
}

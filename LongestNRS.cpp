#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std ;


string findLongestNRS(string s){
	int len = s.size();
	int arr[s.size()+1];
	memset(arr,0,sizeof(arr));
	//arr[1]=0;
	int lastIndex[256];
	memset(lastIndex,-1,sizeof(lastIndex));
	int st,maxlen=1,curlen=1,pre_index;
	lastIndex[s[0]]=0;
	int last ;
	for(int i=1 ; i<s.size() ; i++){
	//	cout<<lastIndex['c'];
		pre_index = lastIndex[s[i]];
	//	cout<<pre_index<<endl;
		if(pre_index==-1 || i-curlen > pre_index)
				curlen++;
		else{
	//		cout<<i<<" "<<curlen<<endl;
			if(curlen > maxlen){
				maxlen  = curlen ;
			}
			arr[curlen] = i-curlen;
		//	cout<<"arr["<<curlen<<"] : "<<i-curlen<<endl;
			curlen =  i - pre_index ;
			
		//	cout<<"arr["<<curlen<<"] : "<<arr[curlen]<<endl;
			last = i;
		}
		lastIndex[s[i]] = i;
		
	}
	if(curlen > maxlen){
		maxlen = curlen ;
		if(arr[maxlen]==0)
		{
		
			arr[maxlen]=last;
	//		cout<<"hi";
		}
	}
	//cout<<maxlen<<" "<<arr[maxlen];
	return s.substr(arr[maxlen],maxlen);
	
}
int main(){
	int tests ;
	scanf("%d",&tests);
	while(tests--){
		string s;
		cin>>s;
		cout<<findLongestNRS(s)<<endl; 
	}
}

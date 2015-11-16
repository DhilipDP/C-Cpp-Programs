#include<iostream>
#include<vector>
#include<stdio.h>
#include<stack>
#include<vector>
#include<queue>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<limits.h>
#include<map>


#define ll long long
#define p(a) printf("%d\n",a)
#define s(a) scanf("%d",&a)
#define sl(a) scanf("%lld",&a)
#define sll(a) scanf("%ld",&a)
#define FOR(a,b) for(int i=a ; i<=b ; ++i)

using namespace std ;

struct node{
	int value ;
	struct node * children[26];
};

struct node * getNode(){
	struct node * t = new node() ;
	if(t){
		t->value = 0;
		for(int i=0 ; i<26 ; i++)
			t->children[i] = NULL;
	}
	return t;
}

struct node * insert(struct node * root,string s){
	
	struct node * tra = root ;
	int n = s.length() ;
	int i,index ;
	for(i=0 ; i<n ; i++){
		index = s[i]-65 ;
		if(tra->children[i]==NULL)
			tra->children[i] = getNode();
		tra = tra->children[i] ;
	}
	tra->value = 1 ;
//	cout<<"Inserted : "<<s<<endl;
	return root ;
}




bool search(struct node * root,string s,int &count){
	struct node * tra = root ;
	int len = s.length() ;
	int i,index ;
	
	for(i=0 ; i<len ; i++){
		index = s[i]-65 ;
		if(tra->children[i] == NULL){
			if(tra->value==1){
			//	cout<<"found : "<<s.substr(0,count);
				return true;
			}
			else
				return false ;
		}
		count++;
		tra = tra->children[i] ;
	}
		if(tra->value==1){
			//	cout<<"found : "<<s.substr(0,count);
				return true;
			}
	return false;
	
}
vector<int> findSubstring(string s,vector<string> L){
	vector<int> index ;
	if(L.size()==0)
		return index;
	int n = s.length() ;
	int hash[256]={0};
	struct node * root = getNode() ;
	vector<string> :: iterator  it ;
	map<string,int> mark; 
	
	for(it = L.begin() ; it!=L.end() ; it++){
		string st = *it;
		root = insert(root,st),mark[st]=0;
		for(int i=0 ; i<st.length() ; i++)
			hash[st[i]]=1;
	}
	int len = L.size() ;
	int ind = 0,temp=0;
	for(int i=0 ; i<n ; i++){
		if(hash[s[i]]!=0){
			//cout<<"start "<<s[i]<<endl;
			mark.clear() ;
			ind = i;
			temp = 0;
			while(true){
			int end = 0;
			if(search(root,s.substr(i,n-i),end)){
				//	cout<<s.substr(i,end)<<endl;
					if(mark[s.substr(i,end)]==0){
						temp++;
						mark[s.substr(i,i+end)]=1 ;
						i = i+end;
						if(temp==len){
							index.push_back(ind);
							break;
						}
					}
					else
						break;
			}
			else
				break;
			}
		}
	}
	return index ;
}
int main() {
	vector<string> L ;
	L.push_back("bar");
	L.push_back("foo");
	string s ="barfoothefoobarman";
	vector<int> v = findSubstring(s,L);
	for(vector<int> :: iterator it = v.begin() ; it!=v.end() ; it++)
		cout<<*it<<" ";
		
	return 0 ;
}

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
#include<algorithm>


#define ll long long
#define p(a) printf("%d\n",a)
#define s(a) scanf("%d",&a)
#define sll(a) scanf("%lld",&a)
#define sl(a) scanf("%ld",&a)
#define FOR(a,b) for(int i=a ; i<=b ; ++i)
#define ctoi(a) a-97

using namespace std ;


struct node{
	int val ;
	struct node * children[26];
};


struct node * getNode(){
	struct node * p = new node ;
	p->val = 0;
	for(int i=0 ; i<26 ; i++)
		p->children[i] = NULL ;
	return p;
}
struct node* insert(struct node *root,string s){
//	cout<<s<<endl;
	struct node * tra = root ;
	int len = s.length() ;
	FOR(0,len-1){
		int index = ctoi(s[i]);
	//	cout<<index<<endl;
		if(tra->children[index]==NULL)
			tra->children[index] = getNode();
		tra = tra->children[index] ;
	}
	tra->val=1;
	cout<<"Inserted "<<s<<" in "<<root<<endl;
	return root;
}


void generate(struct node * tra,string &ans){
	if(tra -> val==1)
		return ;
	for(int i=0 ;i<26 ;i++){
		if(tra->children[i]!=NULL){
			ans += ((i+97));
			cout<<ans<<endl;
			generate(tra->children[i],ans);
			break;
		}
	}
}


int search(struct node * root,string s,string &ans){
	cout<<"searching" <<s<<endl;
	struct node * tra = root ;
	int len = s.length();
	if(tra->children[ctoi(s[0])]==NULL)
		return -1;
	int i;
	for(i=0 ; i<=len-1 ; i++){
		int index = ctoi(s[i]);
		if(tra->children[index]==NULL){
			cout<<"index : "<<ans<<endl;
			generate(tra,ans);
			return i-1;
		}
		ans +=( (index+97) );
		tra = tra->children[index];
	}
	generate(tra,ans);
	return i;
}

int main() {
	int n ;
	s(n);
	struct node * org = getNode();
	struct node * rev = getNode();
	FOR(1,n)
	{
		string s ;
		cin>>s ;
		for(int j=0 ; j<s.length() ; j++)
			s[j] = tolower(s[j]);
		org = insert(org,s);
		reverse(s.begin(),s.end());
		rev = insert(rev,s);
	}
	cout<<"org";
	struct node * tra= org;
	for(int i=0 ;i<26 ; i++)
		if(tra->children[i] != NULL)
			cout<<(i)<<" "<<tra->children[i]<<endl;
    	cout<<"rev";
	tra= rev;
	for(int i=0 ;i<26 ; i++)
		if(tra->children[i] != NULL)
			cout<<(i)<<" " <<tra->children[i]<<endl;
	string fusion ;
	cin>>fusion ;
	FOR(0,fusion.length()-1)
		fusion[i] = tolower(fusion[i]);
	string ans = "";
	int first =  search(org,fusion,ans);
	if(first==-1)
		cout<<"No one Fused"<<endl;
	else{
		string ans2 = "";
		reverse(fusion.begin(),fusion.end());
		if((search(rev,fusion,ans2))!=-1){
			reverse(ans2.begin(),ans2.end());
			ans[0] = toupper(ans[0]);
			ans2[0] = toupper(ans2[0]);
			cout<<ans<<" "<<ans2<<endl;
		}
		else
			cout<<"No one Fused"<<endl;
	}
	return 0 ;
}

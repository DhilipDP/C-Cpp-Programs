#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct str{
      string  s;
      int index;
    };
    struct comp{
    bool operator()(const struct str &a,const struct str &b){
	    return (a.s < b.s);
    }
};
    vector<string> anagrams(vector<string> &strs) {
        int  n = strs.size();
        str st[n];
        vector<string> :: iterator it ;
        int i=0;
        for(it = strs.begin() ; it!=strs.end() ; it++)
        {
        	string t = *it;
            sort(t.begin(),t.end());
            st[i].s = t;
            st[i].index = i;
            i++;       
        }
        sort(st,st+n,comp());
        vector<string> v;
        for(i=0 ; i<n ; i++){
        	v.push_back(strs[st[i].index]);
		}
        return v;
    }
     
         

int main(){

	vector<string> v ;
	v.push_back("cat");
	v.push_back("dog");
	v.push_back("god");
	v.push_back("act");
	v = anagrams(v);
	vector<string> ::  iterator it ;
	for(it = v.begin() ; it!=v.end() ; it++)
		cout<<*it<<endl;
	
}

#include<iostream>
#include<vector>
using namespace std ;
  string phone[10] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
     
     void getCombination(string digits,int i,int n,string result,vector<string> &v){
     	//cout<<"hi";
        if(i==n){
            v.push_back(result);
            return;
        }
        string t = phone[digits[i]-'0'];
        int len = t.length();
        for(int j=0 ;j<len ; j++){
        	result[i] = t[j];
        	getCombination(digits,i+1,n,result,v);
		}
        
     }
    vector<string> letterCombinations(string digits) {
        vector<string> v ;
        int n = digits.length();
        char result[n+1];
        result[n] = '\0';
        getCombination(digits,0,n,result,v);
        return v;
    }
	       
int main(){
	//cout<<arr[0];
	vector<string> v ;
	v = letterCombinations("2");
	cout<<v.size();
	vector<string> ::  iterator it ;
	for(it=v.begin() ; it!=v.end() ; it++)
		cout<<*it<<endl;

}

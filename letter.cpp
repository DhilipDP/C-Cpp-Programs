#include<iostream>
#include<vector>
#include<algorithm>

using namespace std ;
string arr[]  = {"0" , "1" , "abc" ,"def" , "ghi" , "jkl" , "mno" , "pqrs" , "tuv" , "wxyz"};
int n ;
void combine(string A,int index,string str,vector<string> &s){
    if(index >= n)
    	return ;
	string temp = arr[A[index]-'0'] ;
    cout<<str<<" "<<index<<endl;
    if(index==n-1)
    {
        for(int i=0 ; i<temp.length() ; i++)
            s.push_back(str + temp[i]);
    
        return ;
    }
    for(int i=0 ; i<temp.length() ; i++){
         combine(A,index+1,str+temp[i],s);
    }
    
}
vector<string> letterCombinations(string A) {
    n = A.length() ;
    vector<string> res ;
    string s= "" ;
    combine(A,0,s,res);
    sort(res.begin(),res.end());
    return res ;
}


int main()
{
	vector<string> res = letterCombinations("23") ;
	for(vector<string> :: iterator it = res.begin() ; it != res.end() ; it++)
		cout<<*it<<endl;
}

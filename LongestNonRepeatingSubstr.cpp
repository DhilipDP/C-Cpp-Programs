#include<iostream>

using namespace std ;


int lengthOfLongestSubstring(string s)
{
	int n = s.length() ;
	if(n==0)
		return 0;
	int hash[256]  ;
	memset(hash,-1,sizeof(hash));
	int cur_len = 1,max_len = 1;
	hash[s[0]] = 0;
	string sub ;
	int start = 0;
	for(int i=1 ; i<n ; i++)
	{
	//	cout<<s[i]<< " ";
		int pre_index = hash[s[i]] ;
	//	cout<<pre_index<<endl;
		if(pre_index == -1 || i-cur_len > pre_index)
			cur_len ++;
		else{
			//cout<<cur_len<<endl;
			if(cur_len > max_len)
				max_len = cur_len,sub = s.substr(start,cur_len);
			cur_len = i-pre_index;
			start = pre_index+1;
		} 
		hash[s[i]] = i;
	}
	//cout<<sub<<endl;
	max_len = max(cur_len,max_len);
	return max_len ;
}

int main()
{
	string s = "dadbc" ;
	cout<<lengthOfLongestSubstring(s);
}

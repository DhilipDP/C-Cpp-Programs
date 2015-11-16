#include<iostream>
#include<vector>
using namespace std ;

vector<int> res ;


int solve(vector<int> num , vector<char> op ,  int ans,int index)
{
	if(index==num.size()-2)
		return (num[index] - num[index+1]);
	for(int i=index ; i<=num.size()-2 ; i++)
		res.push_back(num[i] - solve(num,op,num[i],index+1));
}

int main()
{
	vector<int> num ;
	num.push_back(2) ;
	num.push_back(1) ;
	num.push_back(1) ;
	vector<char> op ;
	op.push_back('-') ;
	op.push_back('-') ;
	solve(num,op,0,0);
	for(vector<int> :: iterator it = res.begin() ; it!= res.end() ; it++)
		cout<<*it<<endl;
}

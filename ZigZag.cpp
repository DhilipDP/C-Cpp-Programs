#include<iostream>
#include<vector>
using namespace std ;



string convert(string A,int B)
{
	vector<string> v (B);
	int mode = 1,cur = 0;
	for(int i=0 ; i<A.length() ; i++)
	{
		v[cur] += A[i] ;
		if(mode){
			cur++;
			if(cur==B)
			{
				cur = B-2 ;
				mode = 0  ;
			}
		}
		else{
			cur--;
			if(cur==-1)
			{
				mode = 1;
				cur= 1;
			}
		}
	}
	string res = "";
	for(int i=0;i<B ; i++)
		res += v[i] ;
	return res;
}


void fun(vector<int> v)
{
	v.erase(0,1);
}
int main()
{
	vector<int>  v ;
	fun(v) ;	
	cout<<convert("PAYPALISHIRING",3) ;
}

#include<iostream>
#include<algorithm>
using namespace std;

string  convert(int num){
	string ans = "";
	int quo=num,rem;
	while(quo){
		rem = quo % 2;
		quo /= 2;
	//	cout<<rem<<endl;
		ans.push_back(rem +  '0');
	}
	reverse(ans.begin(),ans.end());
	return ans;
}
int main(){
//	cout<<convert(32);
	for(int i=64 ; i<96 ; i++)
		cout<<i<<": "<<convert(i)<<endl;
}

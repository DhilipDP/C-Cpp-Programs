#include<iostream>
#include<vector>
#include<stdio.h>
#include<algorithm>

using namespace std ;


struct num{
	int val;
	int index;
};


struct comp{
	bool operator()(const num &a,const num &b){
		return a.val < b.val;
	}
};
vector<int> twoSum(vector<int> &numbers, int target) {
	vector<int> v;
	int no = numbers.size();
	if(no==0 || no==1)
		return v;
	num n[no];
	vector<int> :: iterator it;
	int i=0;
	for(it = numbers.begin() ; it!=numbers.end() ; it++,i++){
		n[i].val = *it;
		n[i].index = i;
	}
	sort(n,n+no,comp());
	int low = 0,high = no-1;
	while(low <= high){
		int sum = n[low].val + n[high].val;
		if(sum==target){
			v.push_back(n[low].index+1);
			v.push_back(n[high].index+1);
			break;	
		}
		else if(sum <  target)
			low++;
		else
			high--;
	}
	return v;
}

int main(){
	vector<int> numbers ;
	numbers.push_back(2);
	numbers.push_back(7);
	numbers.push_back(11);
	numbers.push_back(15);
	vector<int> v = twoSum(numbers,26);
	cout<<v[0]<<" "<<v[1]<<endl;
}

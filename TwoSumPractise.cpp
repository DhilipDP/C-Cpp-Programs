#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

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
		cout<<n[i].val<<" ";
	}
	cout<<endl;
	sort(n,n+no,comp());
	int low = 0,high = no-1;
	while(low < high){
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
	sort(v.begin(),v.end());
	return v;
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t;
    cin>>t;
    while(t--){
        int m,n;
        
        cin>>m>>n;
        vector<int> arr;
        for(int i=0 ; i<n ; i++)
            {
            int val;
            cin>>val;
            arr.push_back(val);
            
        }
        vector<int> v = twoSum(arr,m);
        vector<int> :: iterator it;
        for(it=v.begin() ; it!=v.end() ; it++)
            cout<<*it<<" ";
        cout<<endl;
    }
    return 0;
}


#include<iostream>
#include<vector>
#include<limits.h>
#include<map>
using namespace std ;

 int maximumGap(vector<int> &num) {
    
        int n = num.size() ;
        if(n<2)
         return 0;
        map<int ,int> m;
        int maxi = -1 ,mini=INT_MAX,i;
        for(i=0 ; i<n ; i++){
            maxi = max(maxi,num[i]);
            mini = min(mini,num[i]);
            m[num[i]] = 1;
        }
        int c=0,gap=0;
        for(i=mini+1 ; i<=maxi ; i++){
            if(m[i] != 0){
                gap = max(c,gap);
                c=0;
            }else
                c++;
        }
        return gap;
    }
    
    struct node{
    	int low;
    	int high;
    	node(int x) : low(INT_MAX),high(INT_MIN){};
	};
    
    int maxGap(vector<int> num){
    	int n = num.size() ;
    	if(num.size() < 2)
    		return 0;
		 int maxi = -1 ,mini=INT_MAX,i;
        for(i=0 ; i<n ; i++){
            maxi = max(maxi,num[i]);
            mini = min(mini,num[i]);
        }
        pair<int,int> p;
        p.first=INT_MAX;
        p.second=INT_MIN;
        int range = (maxi-mini)/n-1 ;
        int no = (maxi-mini)/range + 1;
        vector<node> v(no,n);
        for(i=0 ; i<n ; i++){
        	int loc = (num[i] - mini)/range;
        	buckets[loc][0] = min(buckets);
		}
	}
int main() {
	vector<int> num ;
	num.push_back(1);
	num.push_back(10000000);	
	cout<<maximumGap(num);
}



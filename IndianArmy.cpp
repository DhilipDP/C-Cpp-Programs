#include<stdio.h>
#include<algorithm>
#include<stack>
#include<vector>
#include<iostream>
using namespace std ;

struct Interval{
	long long int start;
	long long int end;
};
 struct compare{
         bool operator()(const Interval &i1, const Interval &i2)
        {  
    return (i1.start < i2.start);
            
        }
    };
   
 
// The main function that takes a set of intervals, merges
// overlapping intervals and prints the result
vector<Interval> merge(vector<Interval>& intervals)
{
    // Test if the given set has at least one interval
    vector<Interval> v;
    if (intervals.size() <= 0)
        return v;
 
    // Create an empty stack of intervals
    stack<Interval> s;
 
    // sort the intervals based on start time
    sort(intervals.begin(), intervals.end(), compare());
 
    // push the first interval to stack
    s.push(intervals[0]);
 
    // Start from the next interval and merge if necessary
    for (int i = 1 ; i < intervals.size(); i++)
    {
        // get interval from stack top
        Interval top = s.top();
 
        // if current interval is not overlapping with stack top,
        // push it to the stack
        if (top.end < intervals[i].start)
        {
            s.push( intervals[i] );
        }
        // Otherwise update the ending time of top if ending of current 
        // interval is more
        else if (top.end < intervals[i].end)
        {
            top.end = intervals[i].end;
            s.pop();
            s.push(top);
        }
    }
 
    // Print contents of stack
        while(!s.empty()){
            v.push_back(s.top());
            s.pop();
        }
        reverse(v.begin(),v.end());
        return v;
    }
int main(){
	int n;
	long long int s,e;
	scanf("%d%lld%lld",&n,&s,&e);
	int i;
	if(n==0){
		printf("%lld\n",s-e);
	}
	else	if(s==e){
		printf("0\n");
	}
	else{
	vector<Interval> v;
	for(i=0 ; i<n ; i++){
		long long int x,p;
		scanf("%lld%lld",&x,&p);
		Interval Int;
		Int.start = x-p;
		Int.end = x+p;
		if(Int.end < s || Int.start > e)
			v.push_back(Int);
	}
	v = merge(v);
	int no = v.size();
	long long int dif=0;
	if(v[0].start > s)
		dif += (v[0].start - s);
	for(int i=1 ; i<no ; i++ )
		dif += (v[i].start - v[i-1].end);
	if(e > v[no-1].end)
		dif += (e - v[no-1].end);
	
	printf("%lld\n",dif);
	}
}

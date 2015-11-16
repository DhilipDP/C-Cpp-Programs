#include<iostream>
#include<algorithm>
#include<vector>
#include<stdlib.h>
#include<string.h>
#include<utility>
using namespace std ;
struct node{
	int val;
	int index;
};


struct comp{
	bool operator()(const struct node &a,const struct node &b){
	//    if()
		return b.val < a.val;
	}
};

    string itoa(int n){
        string s;
        if(n==0)
            return "0";
        while(n > 0){
            int r = n%10;
            s += (r+'0');
            n/=10 ;
        }
        reverse(s.begin(),s.end());
        return s;
    }
    
    
    string largestNumber(vector<int> &num) {
        bool zero = true;
        
	string large = "";
	int n = num.size();
	if(n==0)
		return large ;
		int k;
    for(k= 0 ; k<n ; k++)
        if(num[k]!=0)
         break;
    if(k==n)
        return "0";
	int maxi = 0;
	for(int i =0 ; i<n ; i++)
	{
	string arr = itoa(num[i]);
		if(arr.size() > maxi)
			maxi = arr.size();
	}
	vector<node > temp ;
	for(int i=0; i<n ; i++)
	{
		
		string s = itoa(num[i]);
		if(s.length() < maxi){
			char a = s[0];
			int dif = maxi - s.length();
			while(dif--)
				s += a;
		}
		node pi;
		pi.val = atoi(s.c_str());
		pi.index = i;
		temp.push_back(pi);
	}
	sort(temp.begin(),temp.end(),comp());
	for(int i=0 ; i<n ; i++){
	    if(i+1 < n && temp[i].val == temp[i+1].val){
	       int a = num[temp[i+1].index];
	       int b = num[temp[i].index];
	       cout<<a<<" "<<b<<endl;
	       string n1 = itoa(a)+ itoa(b);
	       string n2 = itoa(b) + itoa(a);
	       large += (n1 > n2) ? n1 : n2 ;
	       
	        i++;
	    }
	   //	cout<<num[temp[i].index]<< " " <<num[temp[i+1].index]<<endl;
	   else{
		string s = itoa(num[temp[i].index]);//,arr,10);
		
		large += s;	
		}
	//	cout<<large<<endl;
	}
	return large;
        
    }
int main()

{
	vector<int> num ;
//	for(int i=0;i<10 ; i++)
//	num.push_back(i);
	num.push_back(8308);
	num.push_back(830);
//	num.push_back(121);
/*	num.push_back(34);
	num.push_back(3); */
	
	cout<<largestNumber(num);
}



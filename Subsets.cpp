
#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
using namespace std;





vector<vector<int> > subsets(vector<int> &S) {
		sort(S.begin(),S.end());
        vector<vector<int> > v;
        int n = S.size();
        int size = pow(2,n);
        int counter,i;
        for(counter = 0 ; counter < size ; counter++){
        	vector<int> temp;
        	cout<<"counter: "<<counter<<endl;
        	for(i=0 ; i<n ; i++){
        		cout<<(1<<i) <<" "<<counter<<" "<<(counter & (1<<i))<<endl;
        		if(counter & (1<<i)){
        			cout<<S[i]<<endl;
        			temp.push_back(S[i]);
        		}
			}
			v.push_back(temp);
		
		}
		return v;
    }
    void generateSub(  
      vector<int> &s,   
      int step,   
      vector<vector<int> > &result,  
      vector<int>& output)  
    {         
      for(int i = step;i<s.size(); i++ )  
      {  
        output.push_back(s[i]);  
        result.push_back(output);  
        if(i< s.size()-1)  
          generateSub(s, i+1, result, output);  
        output.pop_back();  
        while(i<s.size()-1 && s[i] == s[i+1])  
          i++;  
      }      
    }  
    
    
    bool check(vector<int> &v ,vector<vector<int> > &ans,int sum){
    	int s = v.size() ;
    	vector<vector<int> > :: iterator it;
		for(it = ans.begin()+1 ;  it!= ans.end() ; it++){
			vector<int> :: iterator i;
			vector<int> t = *it;
			if(t.size() == s ){
				int add = 0;
				for(i = t.begin() ; i!=t.end() ; i++)
					add += *i;
				if(add == sum)
					return false;
		
			}
	
    	}
    		return true;
	}
	
     vector<vector<int> > subsetsWithDup(vector<int> &S) {  
     // Start typing your C/C++ solution below    
      // DO NOT write int main() function  
   /*   vector<vector<int> > result;  
      vector<int> output;   
      if(S.size() ==0) return result;  
      result.push_back(output);  
      sort(S.begin(), S.end());  
      generateSub(S, 0, result, output);   */
      
      int n = S.size() ;
      vector<vector<int> > ans ;
      if(n==0)
      	return ans ;
     int s ;
     int size = 1<<n ;
   		for(s=0; s<size ; s++ ){
   			vector<int> temp ;
   			int sum = 0;
   			for(int i=0 ; i<n ; i++){
   				if(s & (1<<i))
   					temp.push_back(S[i]),sum += S[i];
			}
			if(temp.size()==0 || check(temp,ans,sum) )
		   		ans.push_back(temp);
		}
      return ans ;
    }  
    
    
    int main(){
    
		vector<int> s;
		s.push_back(1);
		s.push_back(2);
		s.push_back(2);
		vector<vector<int> > v = subsetsWithDup(s);
		vector<vector<int> > :: iterator it;
		for(it = v.begin() ;  it!= v.end() ; it++){
			vector<int> :: iterator i;
			vector<int> t = *it;
			for(i = t.begin() ; i!=t.end() ; i++)
				cout<<*i<<" ";
			cout<<endl;
		
		}
	
	}

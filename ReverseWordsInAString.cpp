

#include<iostream>
#include<vector>

using namespace std;


    void reverseWords(string &s) {
    	if(s=="")
    		return;
        vector<string> st;
        int i,len=s.length();
        
        for(i=len-1 ; s[i]==' ';len--,i--);
        for(i=0 ; s[i]==' ' ; i++);
        string temp="";
        for(; i<len ; i++){
            if(s[i]!=' ')
                temp += s[i];
            else{
                st.push_back(temp);
                temp ="";
            	int j=i;
                for(;j<len && s[j]==' ' ; j++);
                i = j-1;
            }
    	}	
    	if(temp!="")		
        st.push_back(temp);
        vector<string>  :: iterator it; 
        s = "";
        for(it = st.end()-1 ; it!=st.begin()-1 ; it--)
        {
        	string t = *it;
        	cout<<t<<endl;
        	for(int j=0 ; j<t.length() ; j++)
        		s += t[j];
        	if(it!=st.begin())
        		s+=  ' ';
        }
    }
    
    
    int main(){
    	string s ="a ";
    	reverseWords(s);
    	cout<<s.length();
    }

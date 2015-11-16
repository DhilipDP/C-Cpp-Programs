#include<iostream>
#include<vector>
using namespace std ;



vector<string> fullJustify(vector<string> &A, int B) {
     vector<string> res ;
    if(A.size() == 0)
        return res ;
    int i=0,cur_len=0,no_words=0,word_len=0;
    vector<string> w ;string temp ;
   while( i < A.size())
  	{
  		w.clear();
  		temp ="";
  		no_words=0;
  		word_len = 0;
  		cur_len = 0;
  		while(i<A.size() && cur_len + A[i].length()<= B)
  		{
  			w.push_back(A[i]);
			word_len += A[i].length();
  			no_words++;
  			cur_len += A[i].length() ;
  			cur_len++;
  			i++;
  		}
  		int dif = B-word_len ;
  		if(i==A.size())
  		{
  		
  			int j=0,l=0;
  			string tp ;
  			while(no_words--)
  			{
  				tp += w[j];
  				tp += " ";
  				l += w[j].length() ;
  				l ++ ;
  				j++;
  			}
  		//	cout<<tp<<endl;
  			dif = B - l;
  			while(dif--)
  				tp += " ";
  			res.push_back(tp) ;
  			break;
		}
  		if(no_words==1){
  		//	cout<<"h";
  			
  			string tp = w[0];
  			while(dif--)
  				tp += " ";
  			res.push_back(tp);
		  	continue;
		  }
		  int spac = dif/(no_words-1) ;
  		string sp;
  		for(int k=0 ; k<spac ; k++)
  			sp+=" ";
  		int rem = dif % (no_words-1) ;
  		string r;
  		for(int k=0 ;k<rem ; k++)
  			r+=" ";
  		int j=0;
  		while(no_words--)
  		{
  			temp += w[j];
  			
  			temp += sp;
  			if(j==0)
  				temp += r;
  			j++;
  		}
  		res.push_back(temp);
  	//	cout<<"pushing "<<temp<<endl;
	}
	return res;
}


int main()
{
	string b[] = {"kgyyrqh", "qrdqusnh", "zyu", "w", "ukzxyykeh", "zmfqafqle", "e", "ajq", "kagjss", "mihiqla", "qekf", "ipxbpz", "opsndtyu", "x", "ec", "cbd", "zz", "yzgx", "qbzaffgf", "i", "atstkrdph", "jgx", "qiy", "jeythmm", "qgqvyz", "dfagnfpwat", "sigxajhjt", "zx", "hwmcgss" };
	string arr[] = {"This","is","am","example","of","text","justification"};
	int n = sizeof(b)/sizeof(b[0]) ;
	vector<string> a(b,b+n) ;
	vector<string> r = fullJustify(a,178) ;
	for(int i=0 ; i<r.size() ; i++)
		cout<<r[i]<<endl;
}

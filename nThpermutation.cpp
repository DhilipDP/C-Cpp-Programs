#include<iostream>
#include<algorithm>
#include<vector>
#include<limits.h>



using namespace std ;





string to_string(int n)
{
	string s ="" ;
	 while(n > 0)
	 {
	 	s += (n%10) + '0' ;
	 	n /= 10;
	 }
	 reverse(s.begin() , s.end()) ;
	 return s;
}
/*

void permute(string s,int  st,int end,int &k,string &ans,int&c)
{
	static bool done = false ;
	if(done)
		return ;
	if(st == end)
	{
		cout<<s<<" "<<c+1<<endl;
		c++;
		if(c==k)
		{
			done = true ;
			ans = s;
		}
		return ;
	}
	for(int j=st ; j<=end ; j++)
	{
		
		swap(s[st],s[j]) ;
		permute(s,st+1,end,k,ans,c) ;
		swap(s[st],s[j]) ;	
	}
}



string getPermutation(int  n,int k)
{
	string s="" ;
	for(int i=1 ; i<=n ; i++)
		s += to_string(i) ;
	string ans="";
	int c=0;
	permute(s,0,s.length()-1,k,ans,c);
	return ans ;
}
*/
int factorial(int n) {
        if (n > 12) {
            // this overflows in int. So, its definitely greater than k
            // which is all we care about. So, we return INT_MAX which
            // is also greater than k.
            return INT_MAX;
        }
        // Can also store these values. But this is just < 12 iteration, so meh!
        int fact = 1;
        for (int i = 2; i <= n; i++) fact *= i;
        return fact;
    }

    string getPermutation(int k, vector<int> &candidateSet) {
    	
        int n = candidateSet.size();
        cout<<n<<endl;
		if (n == 0) {
        return "";
        }
        if (k > factorial(n)) return ""; // invalid. Should never reach here.

        int f = factorial(n - 1);
        int pos = k / f;
        k %= f;
        cout<<":"<<k<<" "<<f<<endl;
        string ch = to_string(candidateSet[pos]);
        // now remove the character ch from candidateSet. 
        candidateSet.erase(candidateSet.begin() + pos);
        return ch + getPermutation(k, candidateSet);
    }
    
    string getPermutation(int n, int k) {
        vector<int> candidateSet; 
        for (int i = 1; i <= n; i++) candidateSet.push_back(i);
        return getPermutation(k - 1, candidateSet);
    }
int main()
{
	cout<<getPermutation(3,6) ;
}

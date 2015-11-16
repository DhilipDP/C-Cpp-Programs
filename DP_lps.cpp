#include<iostream>
#include<algorithm>
using namespace std;


int LPS(string s){
	
	int m = s.length();
	int lps[m][m];
	int i,j,l;
	for(i=0 ; i<m  ;i++)
		lps[i][i] = 1;
	for(l=2 ; l<=m ; l++) {
		for(i=0 ; i<=m-l ; i++)
		{
			j = i+l-1;
			if(s[i] == s[j] && l==2)
				lps[i][j] = 2;
			else if(s[i]==s[j])
				lps[i][j] = lps[i+1][j-1] + 2;
			else
				lps[i][j] = max(lps[i][j-1],lps[i+1][j]);				
		}
	}
	i=0;
	j=m-1;
	string ans = "";
	while(i<m && j>=0){
		if(s[i]==s[j]){
			ans += s[i];
			i++,j--;
		}
		else if(lps[i][j-1] > lps[i+1][j])
			j--;
		else
			i++;
			
		
	
	}
	reverse(ans.begin(),ans.end());
	for(i=0 ; i<m ; i++){
		for(j=0 ; j<m ; j++)
			cout<<lps[i][j]<<" ";
		cout<<endl;
	}
	cout<<endl<<ans<<endl;
	return lps[0][m-1];
}

int main(){
	string s = "GEEKS FOR GEEKS";
	cout<<LPS(s);

}

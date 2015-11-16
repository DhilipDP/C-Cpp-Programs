#include<iostream>

using namespace std ;


int compareVersion(string version1, string version2) {
	
	
        int i=0,j=0;
        int n1=version1.length();
        int n2= version2.length();
        int first ,second ;
        while(i<n1 || j<n2){
			first = 0 ; 
			second = 0;
			for(; i < n1 && version1[i]!='.' ; i++)
				first = (first*10 +  version1[i]-'0');
			for(; j < n2 && version2[j]!='.' ; j++)
				second = (second*10 + version2[j]-'0');
			if(first > second)
				return 1;
			if(first < second)
				return -1;
			i++,j++;
        }
        return 0;
    }
int main(){
	cout<<compareVersion("1.1","1.01.0");

}

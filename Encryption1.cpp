#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    string s ;
    cin>>s ;
    int n = s.length() ;
    int row = floor(sqrt(n));
    int col = ceil(sqrt(n));
    if(row * col < n)
    	row++;
    char mat[row][col] ;
    for(int i=0 ;i<row ; i++)
    	for(int j=0 ; j<col ; j++)
    		mat[i][j] = '-';
    int k=0;
    for(int i=0 ; i<row ; i++){
        for(int j=0 ; j<col && k<s.length(); j++){
            mat[i][j] = s[k++];
        }
    }
    for(int i=0 ; i<col ; i++){
        string temp="";
        for(int j=0 ; j<row  && mat[j][i] != '-'; j++)
            temp += mat[j][i];
        cout<<temp<<" ";
    }
    return 0;
}


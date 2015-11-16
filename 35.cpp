#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
   int t,n,i,m=0;
   cin>>t;
   while(t--){
    m=0;
   	cin>>n;
   	int s=0;
   	for(i=1 ;i<n;i++)
   		if(i%3==0 || i%5==0 )
   			s += i;
	cout<<s<<endl;
   	int three = n/3 ;
    int five = n/5 ;
    int fifteen = n/15;
    if(n%3==0)
        three--;
    if(n%5==0)
        five--;
    if(n%15==0)
    	fifteen--;
    m+= 3*(three*(three+1)/2);
    m+= 5*(five*(five+1)/2);
    m -= 15*(fifteen*(fifteen+1)/2);
   	cout<<m<<"\n";
} 
}

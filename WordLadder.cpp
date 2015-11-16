#include<iostream>
#include<vector>
#include<stdio.h>
#include<stack>
#include<vector>
#include<queue>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<limits.h>

#define ll long long
#define p(a) printf("%d\n",a)
#define s(a) scanf("%d",&a)
#define sl(a) scanf("%lld",&a)
#define sll(a) scanf("%ld",&a)
#define FOR(a,b) for(int i=a ; i<=b ; ++i)

using namespace std ;



string dict[] = {"miss","dusk","kiss","musk","tusk","diss","disk","sang","ties","muss"};
int visited[] = {1,1,1,1,1,1,1,1,1,1};


int find(string s){
	for(int i=0 ; i<10 ; i++)
		if(dict[i] == s)
			return i;
	return -1;
}

int length(string &start, string &end, int len){
	int ind = find(start);
	if(ind!=-1 && visited[ind]!=0)
		visited[ind] = 0;
	cout<<start<< " " << end<< " "<<len<<endl;
	if(start==end)
		return len ;
	int mini = INT_MAX ;
	bool found = false ;
	   for(int i=0 ; i<start.length() ; i++){
	   		
        	for(char a = 'a' ;  a <= 'z' ; a++){
        		if(a==start[i])
        			continue ;
        		string temp = start ;
        		temp[i] = a ;
        		if(temp==end)
        			return len+1;
        	//	cout<<temp<<endl;
        		int index = find(temp) ;
        		if(index!=-1 && visited[index]!=0){
        		//	cout<<"e";
        			found = true ;
        			visited[index] = 0;
        		//	len++;
        			int q = length(temp,end,len+1);
        			if(	q!=0 && q < mini)
        				mini = q;
				}
			}
		
		}
		if(found)
			return mini ;
		else
			return 0;
	
}


 int ladderLength(string start, string end) {
 	
 	
 		return length(start,end,1);
 	
     
 }
int main() {
	
	cout<<ladderLength("kiss","tusk");
	
	return 0 ;
}

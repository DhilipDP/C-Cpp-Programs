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
#include<map>
#include<algorithm>


#define ll long long
#define p(a) printf("%d\n",a)
#define s(a) scanf("%d",&a)
#define sll(a) scanf("%lld",&a)
#define sl(a) scanf("%ld",&a)
#define FOR(a,b) for(int i=a ; i<=b ; ++i)

using namespace std ;


int triple(int n){

 char arr[10000];
 int count = 0;
 FOR(2,20){
 	itoa(n,arr,i);
 	string st(arr);
 	string rev = st;
 	reverse(rev.begin(),rev.end());
 	if(st==rev)
 	{
 		count++;
 		if(count==3)
 			return 1;
 	}
}
return 0;	
}
int main() {
//	cout<<triple(24);
	FILE *fp = fopen("palin.txt","w");
	string s = "int ans[]={";
	fputs(s.c_str(),fp);
	for(int i=1 ; i<=40000 ; i++){
	if(triple(i)==1)
	{
		char arr[100];
		itoa(i,arr,10);
		string st(arr);
		string t = st + ",";
		cout<<t<<endl;
		fputs(t.c_str(),fp);
	}
}
	return 0 ;

}

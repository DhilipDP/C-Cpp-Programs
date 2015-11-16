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


#define ll long long
#define p(a) printf("%d\n",a)
#define s(a) scanf("%d",&a)
#define sl(a) scanf("%lld",&a)
#define sll(a) scanf("%ld",&a)
#define FOR(a,b) for(int i=a ; i<=b ; ++i)

using namespace std ;

int main() {
	string home,away ;
	cin>>home>>away ;
	int n;
	s(n);
	int h[100]={0};
	int a[100]={0};
	while(n--){
		int t;
		s(t);
		char c;
		cin>>c;
		if(c=='h'){
			int num ;
			s(num);
			char card;
			cin>>card;
			if(h[num]!=-1 && card=='y')
				h[num]++;
			if(h[num]!=-1 && card=='r')
				h[num]+=2;
			if((h[num]>=2))
				cout<<home<<" "<<num<<" "<<t<<endl,h[num]=-1;
		}
		if(c=='a'){
			int num;
			s(num);
			char card;
			cin>>card;
			if(a[num]!=-1 && card=='y')
				a[num]++;
			if(a[num]!=-1 && card=='r')
				a[num]+=2;
			if(a[num]>=2)
			{
			cout<<away<<" "<<num<<" "<<t<<endl,a[num]=-1;
			}
		}
	}
	return 0 ;
}

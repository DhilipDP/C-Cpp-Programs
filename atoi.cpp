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
#include<set>

#define ll long long
#define p(a) printf("%d\n",a)
#define s(a) scanf("%d",&a)
#define sl(a) scanf("%lld",&a)
#define sll(a) scanf("%ld",&a)
#define FOR(a,b) for(int i=a ; i<=b ; ++i)

using namespace std ;

 int atoi(const char *str) {
        long long int num = 0;
        bool neg = false ;
        int st = 0;
        for(st= 0 ; str[st]==' ' ; st++ );
        if(str[st]=='-')
            neg = true ;
        for(int i=st ; i<strlen(str) ; i++){
            if(i==st && (str[i]=='+' || str[i]=='-'))
                continue ;
            if(isdigit(str[i]))
                num = (num * 10) + (str[i]-48);
            else
                break;
            if(num < 0){
            	if(!neg)
            		return INT_MAX ;
            
            		return INT_MIN ;
			}
			if(num > INT_MAX){
				if(neg && -num <= INT_MIN)
					return INT_MIN ;
					
				return INT_MAX;
          }
              cout<<num<<endl;  
        }
        if(neg){
            cout<<"ji";
			return -num ;
		}
        else
            return num ;
    }
int main() {
	cout<<atoi("-2147483648");
	return 0 ;
}

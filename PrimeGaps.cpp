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
#include<utility>


#define ll long long
#define p(a) printf("%d\n",a)
#define s(a) scanf("%d",&a)
#define sll(a) scanf("%lld",&a)
#define sl(a) scanf("%ld",&a)
#define FOR(a,b,it) for( it=a ; it<=b ; ++it)
#define pi pair<int,int> 
#define n 1000000
using namespace std ;


map<int , int > arr;

void markMultiples( int a)
{
	
    int i = 2, num;
    while ( (num = i*a) <= n )
    {
        arr[ num-1 ] = 1; // minus 1 because index starts from 0.
        ++i;
    }
}
 
// A function to print all prime numbers smaller than n
void SieveOfEratosthenes()
{
    // There are no prime numbers smaller than 2
    if (n >= 2)
    {
        // Create an array of size n and initialize all elements as 0

 
        /* Following property is maintained in the below for loop
           arr[i] == 0 means i + 1 is prime
           arr[i] == 1 means i + 1 is not prime */
        for (int i=1; i<=n; ++i)
        {
            if ( arr[i] == 0 )
            {
                markMultiples( i+1);
            }
        }
    }
}



int gval(int temp){
	int right =0;
	int left=0 ;
	int index = temp-1;
	int tindex = index;
	while(index >=0 && arr[index]!=0){
//		cout<<"hi"<<endl;
		left++;
		index--;
	}
	index = tindex;
	while(index <=n && arr[index]!=0){
//		cout<<"he"<<endl;
		right++;
		index++;
	}
	return min(left,right);
		
	

}

map<int ,int>  pr;
void loop(){
	for(int i=1 ; i<=100000 ; i++)
		pr[i] = gval(i);
}
	struct node{
			int val;
			int v;
	};

bool comp(const node &a,const node &b){
	return a.v < b.v;
}
int main() {
	SieveOfEratosthenes();
	loop();
	map<int,int> :: iterator it;
	int i=0;
//	for(it = arr.begin() ;i<20&&it!=arr.end() ; it++,i++)
	//	cout<<it->first<<" "<<it->second<<endl;
	int t;
	s(t);
	while(t--){
		int num ,temp;
		s(num);
		int i;
		node a[num];
		FOR(0,num-1,i){
			s(a[i].val);
			a[i].v = gval(a[i].val);
		//	cout<<a[i].v<<endl;
		}
		sort(a,a+num,comp);
		for(int i=0 ; i<num ; i++)
			cout<<a[i].val<<endl;
	}
	return 0 ;
}

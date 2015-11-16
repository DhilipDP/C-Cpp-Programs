#include<iostream>
#include<algorithm>
#include<stdio.h>
using namespace std;

struct data{
	int first;
	int last;
	int count;
};

int main(){
	while(1){
		int n,q;
		scanf("%d",&n);
		if(n==0)
			break;
		data arr[n];
		int i=0,max;
		scanf("%d",&q);
		int previous = -10000000;
		for(int j=1 ; j<=n ; j++){
			int val;
			scanf("%d",&val);
			if(val==previous){
				arr[i].count ++;
				if(j==n)
					arr[i].last = j;
			}
			else{
				if(j!=1)
					arr[i++].last=j-1;
				if(j==n)
				{
					arr[i].first=arr[i].last=j;
					arr[i].count=1;
				}
				else{
			
				arr[i].first = j;
				arr[i].count = 1;
				previous = val;
			}
			}
			
		}
	//	cout<<i<<endl;
		while(q--){
			int a,b,m,nn;
			scanf("%d%d",&a,&b);
			for(int j=0 ; j<=i ; j++){
				if(arr[j].first <= a && a<=arr[j].last){
					m=j;
					break;
				}
			}
			for(int j=0 ; j<=i ; j++){
				if(arr[j].first <= b && b<=arr[j].last){
					nn=j;
					break;
				}
			}
//			cout<<endl<<m<< " "<<n;
			if(m==nn)
				printf("%d\n",b-a+1);
			else if(a+1 ==b)
				printf("1\n");
			else{
				int m_count = arr[m].last - a + 1;
				int n_count = b - arr[nn].first + 1;
				 max = m_count > n_count ? m_count : n_count;
				for(int j=m+1 ; j<nn ; j++){
					if(arr[j].count > max)
						max = arr[j].count;
				}
				printf("%d\n",max);
			}
			
		}
	//	for(int j=0 ; j<=i ; j++){
	//		cout<<arr[j].first<<" "<<arr[j].last<<" "<<arr[j].count<<endl;
		}
	}


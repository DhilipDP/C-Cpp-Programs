#include<iostream>
#include<algorithm>
using namespace std;


int main(){
	int n;
	cin>>n;
	int a[n],b[n];
	int c1=n,c2=n;
	int i;
	for(i=0 ; i<n ; i++)
		cin>>a[i];
	for(i=0 ; i<n ; i++)
		cin>>b[i];
	sort(a,a+n);
	sort(b,b+n);
	int ai=0;
	int bi=0;
	while(c1!=0 && c2!=0){
		if(c1){
			int val = a[ai];
			ai++;
			c1--;
			if(ai < n && a[ai]==val+1)
				ai++,c1--;
		
		}
			if(c2){
			int val = b[bi];
			bi++;
			c2--;
			if(bi < n && b[bi]==val+1)
				bi++,c2--;
		
		}
	}
	if(c1==0 && c2==0)
		cout<<"N"<<endl;
	else if(c2==0)
		cout<<"A"<<endl;
	else
		cout<<"B"<<endl;
	

}


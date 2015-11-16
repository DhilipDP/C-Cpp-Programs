#include<iostream>
#include<algorithm>

using namespace std ;

struct val{
		long long a;
		long long b;
	};
struct comp{
	bool operator()(const val &x,const val &y){
		return x.a < y.a;
	}

};
int main(){
	int n;
	cin>>n;
	
	val v[n];
	for(int i=0 ; i<n ; i++)
		cin>>v[i].a>>v[i].b;
	sort(v,v+n,comp());
	
	int min_days=-1;
	for(int i=0 ; i<n ; i++){
		if(min_days==-1)
			min_days = v[i].b;
		else if(v[i].b >= min_days)
			min_days = v[i].b;
		else
			min_days = v[i].a;
	}
	cout<<min_days<<endl;
}

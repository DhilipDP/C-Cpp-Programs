#include<iostream>
#include<map>
	#include<vector>
using namespace std;


int no ;
vector<int> *v = new vector<int>[20000];

bool already(long long int n1,long long int n2){

	vector<int> :: iterator it ;
	for(int i=0 ; i<v->size() ; i++){
		for(it = v[i].begin() ; it!=v[i].end() ; it++)
			{
				if(*it==n1 && *(it+1)==n2)
					{
						return true;
					}
			}
	}
	v[v->size()].push_back(n1);
	v[v->size()].push_back(n2);
	return false;
	
}

void search(long long int m[],int n,long long int val){
	for(int i=0 ; i<n ; i++){
		if(m[i]+val >= -10000 && m[i]+val <= 10000 && already(m[i],val) )
			no++;
			
	}
}
int main(){
long long	int plus[100000];
long long	int minus[100000];

	int i;
	int p=0,m=0;
	for(i=1 ; i<=2 ; i++){
		int num;
		cin>>num;
		if(num > 0)
			plus[p++]=num;
		else
			minus[m++]=num;
		cout<<"hi";
	}
	int j;
	for(i=0 ; i<p ; i++){
		search(minus,m,plus[i]);
	}
	for(j=0 ; j<m ; j++)
		search(plus,p,minus[j]);
	cout<<endl<<no;
}

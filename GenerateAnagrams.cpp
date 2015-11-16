#include<iostream>
#include<algorithm>
using namespace std ;


struct string_index{
	string s ;
	int index ;
};


int comp(const void * a,const void * b){
	string_index * a1 = (string_index *)a;
	string_index * a2 = (string_index *)b;
	return (a1->s) > (a2->s);	
}

int main(){
	
	//printing all anagrams together
	string arr[] = {"nandu","andnu","dog","god","nijin"};
	int len = sizeof(arr)/sizeof(arr[0]);
	string_index temp[len];
	//sort all strings
	for(int i=0 ; i<len ; i++){
		temp[i].s = arr[i];
		temp[i].index =  i;
	}
	
	for(int i = 0 ; i<len ; i++)
		sort(temp[i].s.begin(),temp[i].s.end());
	qsort(temp,len,sizeof(temp[0]),comp);
	for(int i= 0 ;i<len ; i++)
	//	cout<<temp[i].s<<" "<<temp[i].index<<endl;
	{
		cout<<arr[temp[i].index]<<endl;
	}
}

#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std ;


vector<string> dictionary ;


bool present(string s){
	
	vector<string> ::  iterator it ; 
	for(it = dictionary.begin() ; it!=dictionary.end() ; it++){
		if(*it==s)
			return true ;
	}
	return false ;
}

bool break_string(string str,int arr[]){
	int i ;
	for(i=1 ; i<=str.size() ; i++){
	//	cout<<"hi";
		if(arr[i]==0 && present(str.substr(0,i)))
			arr[i]=1 ;
		if(arr[i]){
		//	if(i==str.size())
		//		return true ;
		//	cout<<"True:  "<<i<<endl;
			int j;
			for(j=i+1 ; j<=str.size() ; j++){
		//		cout<<"\n"<<arr[i]<<" "<<str.substr(i,j-i)<<endl;
				if(arr[j]==0 && present(str.substr(i,j-i)))
					arr[j]=1 ;
				if(j==str.size() && arr[j])
					return true ;
			}
		//	arr[i]=0;
		}
	}	
	return false ;
}
void segment(string str){
	int arr[str.size()+1 ];
	memset(arr,0,sizeof(arr));
	if(break_string(str,arr))
	{
		int i,j;
		string output = "";
		for(i=0 ; i<str.size() ; i++ ){
			if(i!=0 && arr[i]==1)
				output+=" ",output+=str[i];
				
			else
				output+=str[i];
		//	cout<<output<<endl;
		}
		cout<<endl<<output ;
	}	
	else
		cout<<"\nCannot be segmented\n";
}

int main(){
	FILE *fp ;
	fp =  fopen("dictionary.txt","r");
	char a[256];
	while((fscanf(fp,"%s",a))!=EOF){
		string s(a);
		dictionary.push_back(s);
	}
	//cout<<present("i");
	vector<string> ::  iterator it ; 
/*	for(it = dictionary.begin() ; it!= dictionary.end() ; it++)
		cout<<*it<<" "; */
	string str;
	cout<<"\nEnter  a sentence without spaces:\n";
	cin>>str ;
	segment(str);
}


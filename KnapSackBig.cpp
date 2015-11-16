#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<vector>
#define cap 10000
#define n  100
using namespace std ;


int maxi(int a,int b){
	return a>b ? a : b ;
}


void print(vector<int> *v){
	vector<int> :: iterator it ;
	
	for(int i=0 ; i<=cap ; i++)
	{
		it = v[i].end()-1 ;
		cout<<*it<<"  ";
	}
	cout<<endl ;
}

void swap(int &a,int &b){
	int temp = a ;
	a= b ;
	b = temp ;
}

void swap(float &a,float &b){
	float temp = a ;
	a = b ;
	b = temp;
}
int main(){
	vector<int> *arr =  new vector<int>[2000001];
		vector<int> *even =  new vector<int>[2000001];
			vector<int> *odd =  new vector<int>[2000001];
	int wei[n];
	int pro[n];
//	int arr[2][101];
	FILE *fp ;
	fp = fopen("knapsack.txt","r");
	char a[100];
	int i=1 ;
	int w=0 , p=0 ;
	while((fscanf(fp,"%s",a))!=EOF){
		string s(a);
	//	cout<<s<<endl;
		if(i % 2)
			pro[p++]=atoi(s.c_str());
		else
			wei[w++] = atoi(s.c_str());
		i++;
	}
	float ratio[n];
	int j;
	for(i=0 ; i<n ; i++)
		ratio[i] = (float)pro[i]/(float)wei[i];
	for(i=0 ; i<n ; i++){
		for(j=i+1 ; j<n ; j++){
			if(ratio[j] > ratio[i]){
				swap(ratio[i],ratio[j]);
				swap(pro[i],pro[j]);
				swap(wei[i],wei[j]);
			}
		}
	}
//	cout<<"hello";
//	even[0][0]=0;
	for(i=0 ; i<n ; i++){
		cout<<pro[i]<<" "<<wei[i]<<" "<<ratio[i]<<" "<<endl;
	} 
	int U = cap ;
	int sol=0 ;
	for(i=0 ; i<n ; i++){
		if(wei[i] <= U){
			sol += pro[i];
			U -= wei[i];
			cout<<sol<<" ";
		}
		else 
			break ;
	}
//	sol += pro[i]/wei[i];
	
	cout<<endl<<sol ;
/*
	for(i=0 ; i<=cap ; i++)
		arr[i].push_back(0);
	for(i=0 ; i<=cap ; i++)
		even[i].push_back(0);
	for(i=0 ; i<=cap ; i++)
		odd[i].push_back(0);
//	print(arr);
	for(i=1 ; i<=n ; i++){
		cout<<i<<" ";
		vector<int> :: iterator it,it1 ;
		vector<int> *cur = new vector<int>[2000001];
		*cur = *arr ;
	//	print(cur);
		int start = wei[i];
		for(j=start ; j<=cap ; j++){
				it = arr[j].end()-1 ;
				it1 = arr[j-wei[i]].end()-1 ;
				cur[j].push_back(max(*it,pro[i]+*it1));
		}
		it = arr[cap].end()-1 ;
		it1 = arr[cap-wei[i]].end()-1 ;
		cur[cap].push_back(max(*it,pro[i]+*it1));
		*arr = *cur ;
	}
	
	/*
	
		if(i%2){
			vector<int> :: iterator it,it1 ; 
			for(j=0 ; j<wei[i] ; j++)
				even[j].push_back(*(odd[j].end()-1));
			for(j= wei[i] ; j<=cap ; j++){
				it = odd[j].end()-1;
				it1 = odd[j-wei[i]].end()-1 ;
			    even[j].push_back(max(*it , pro[i] + *it1)) ;
			//	cout<<"even["<<j<<"] : "<<*it1<<endl;
				
			}
			//cout<<"hi";
		//	cout<<"odd["<<j<<"] : "<<even[j][0]<<endl;
		}
		else{
			vector<int> :: iterator it,it1 ; 
			
			for(j=0 ; j<wei[i] ; j++)
				odd[j].push_back(*(even[j].end()-1));
			for(j=wei[i] ; j<=cap ; j++){
				it = even[j].end()-1 ;
				it1 = even[j-wei[i]].end()-1;
				 odd[j].push_back(max(*it , pro[i] + *it1)) ;
//				 cout<<"odd["<<j<<"] : "<<*it1<<endl;
				
			}
//		cout<<"even["<<j<<"] : "<<odd[j][0]<<endl;
		}
		
	/*	for(j=0 ; j<=cap ; j++){
			cout<<i<<" "<<j<<endl;
			if(wei[i] > j)
				arr[i][j] = arr[i-1][j];
			else
				arr[i][j] = maxi(arr[i-1][j] , pro[i] + arr[i-1][j-wei[i]]);
			cout<<"arr["<<i<<"]["<<j<<"] : "<<arr[i][j]<<endl;
		//	break;
		}
	//	break; 
	} */


	/*
	if(n & 1)
		cout<<*(even[cap].end()-1);
	else
		cout<<*(odd[cap].end()-1); */
}
	

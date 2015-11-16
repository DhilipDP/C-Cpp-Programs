#include<iostream>
#include<algorithm>
#define N 0
#define E 1
using namespace std ;

int main(){
	string str ;
	cout<<"Enter long route:";
	cin>>str;
	int arr[2]={0};
	for(int i=0 ; str[i] ; i++){
		switch(str[i]){
			case 'N' : arr[N]++;
						break;
			case 'S' : arr[N]--;
						break;
			case 'E' : arr[E]++;
						break;
			case 'W' : arr[E]--;
						break;
		}
	}
	string min_route = "";
	if(arr[0] > 0){
		while(arr[0]--)
			min_route += "N";
	}
	else if(arr[0] < 0){
	//	cout<<"hi";
		while(arr[0]!=0){
			min_route += "S";
			arr[0]++;
		}
	}
	if(arr[1] > 0){
		while(arr[1]--)
			min_route +="E";
	}
	else if(arr[1] < 0){
		while(arr[1]!=0){
			min_route += "W";
			arr[1]++;
		}
	}
	sort(min_route.begin(),min_route.end());
	cout<<"\nShortest route : "<<min_route ;
	
}

#include<iostream>
#include<stdio.h>
using namespace std;

int main(){
	FILE *fp ;
	fp = fopen("rand.txt","r");
	char a[1024] ;
	int i= 0;bool first = true ;
	int from,to ;
	while(fgets(a,sizeof(a),fp) && i<2){
		string s(a);
	//	cout<<s[2];
		int l=0;
		int i,last;
		string f,t;
		for(i=0 ; s[i]!= '        '; i++){
			f+=s[i];
			last = i;
			break;
		}
		int j,k;
		for(j=last ; s[j] ; j+=2){
			for(k=j ; s[k]!= '        ' ; k++){
				
			}
		}
		cout<<f;
	//	cout<<i;
		int j ,k;
		//cout<<f<<endl;
		break;
		string t ;
		for(j=i ; s[j] ; j++){
			for(k=1 ; k<=6 ; k++);
			j=k;
			for(j=k ; s[j] && s[j]!=' ' ; j++){
				t+=s[j];
			}
			cout<<to<<endl;
		}
		break;
	}
}

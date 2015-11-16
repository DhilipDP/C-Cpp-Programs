#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std ;

int main(){
	int t;
	t = (rand()%10) + 1;
	t = 10;
	FILE *fp = fopen("C:\\Users\\Nandu Vinodan\\Desktop\\dbg3\\i3.txt","w");
	char buf[10];
	itoa(t,buf,10);
	fprintf(fp,buf);
	cout<<t<<endl;
	fprintf(fp,"\n");
	while(t--){
		int n = (rand() % 100000000) + 1;
		cout<<n<<endl;
		char b[100];
		itoa(n,b,10);
		fprintf(fp,b);
		fprintf(fp,"\n");
		while(n--){
			int v = (rand() % 10000000) + 1 ;
			cout<<v<<" ";
			char s[100];
	  	itoa(v,s,10);
		fprintf(fp,s);
		fprintf(fp," ");
			
		}
		cout<<endl;
		fprintf(fp,"\n");
	}
}

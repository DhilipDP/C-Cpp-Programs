#include<iostream>
#include<string.h>
using namespace std;



bool isInterleaving(char *a,char *b,char *c){
	if(!(*a || *b || *c))
		return true ;
	if(*c == '\0')
		return false ;
	return (*c==*a && isInterleaving(a+1,b,c+1)) || (*c==*b && isInterleaving(a,b+1,c+1));
}


bool interleaving(char *a,char *b,char *c){
	int m = strlen(a);
	int n = strlen(b);
	if(m+n != strlen(c))
		return false ;
	int i,j ;
	bool tab[m+1][n+1] ;
	memset(tab,false,sizeof(tab));
	 tab[0][0] = true ;
	for(i=1 ; i<=n ; i++){
		if(c[i-1]==b[i-1])
			tab[0][i] = tab[0][i-1] ; 
	}
	for(i=1 ; i<=m ; i++)
	{
		if(c[i-1] == a[i-1])
			tab[i][0] = tab[i-1][0] ; 
	}
	for(i=1 ; i<=m ; i++){
		for(j=1 ; j<=n ; j++){
			if(c[i+j-1] == a[i-1] && c[i+j-1] != b[j-1])
				tab[i][j] = tab[i-1][j];
			if(c[i+j-1] == b[j-1] && c[i+j-1] != a[i-1])
				tab[i][j] = tab[i][j-1] ;
			if(c[i+j-1]==a[i-1] && c[i+j-1] == b[j-1])
				tab[i][j] = tab[i-1][j] || tab[i][j-1] ;
				
		}
	}
	
	for(i=0 ; i<=m ; i++){
		for(j=0 ; j<=n ; j++)
			cout<<tab[i][j]<<" ";
		cout<<endl;
	}
	return tab[m][n];

}

int main(){
	char  *a ="AB";
	char  *b = "CD";
	char  *c = "ACBD";
	cout<<interleaving(a,b,c);
	
}

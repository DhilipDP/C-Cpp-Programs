#include <bits/stdc++.h>
using namespace std;

int ar[10000][10000];
char s[10007];

void build(){
	int ks = strlen(s);
	for(int i=0;i<ks;i++)
		ar[i][0]=ar[0][i]=ar[i][i]=0;
	for(int i=ks-2;i>=0;i--){
		ar[i][i+1]=(s[i]==s[i+1]?0:1);
		for(int j=i+2;j<ks;j++){
			ar[i][j]=ar[i+1][j-1]+(s[i]==s[j]?0:1);
		}
	}
}

int main() {
	scanf("%s",s);
	build();
	int ite;
	scanf("%d",&ite);
	
	while(ite--){
		int n,m;
		scanf("%d%d",&n,&m);
		printf("%d\n",ar[n][m]);
	}

	return 0;
}


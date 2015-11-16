#include<iostream>
#include<vector>
#include<stdio.h>
#include<stack>
#include<vector>
#include<queue>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<limits.h>
#include<map>
#include<algorithm>


#define ll long long
#define p(a) printf("%d\n",a)
#define s(a) scanf("%d",&a)
#define sll(a) scanf("%lld",&a)
#define sl(a) scanf("%ld",&a)
#define FOR(a,b) for(int i=a ; i<=b ; ++i)

using namespace std ;

int main() {
	int t;
	s(t);
	while(t--){
		int row,col;
		s(row);
		col = row ;
		int mat[row][col];
		int n=1,i;
		int fr = 0,fc =0,lr=row-1,lc=col-1 ;
		while(fr <= lr && fc<=lc ){
			for(i=fr ; i<=lr ; i++)
				cout<<"["<<i<<"]["<<fc<<"]"<<n,mat[i][fc] = n++;
			cout<<endl;
			fc++;
			for(i=fc ; i<=lc ; i++)
				cout<<"["<<lr<<"]["<<i<<"]"<<n,mat[lr][i] = n++;
			cout<<endl;
			lr--;
			for(i=lr ; i>=fr ; i--)
				cout<<"["<<i<<"]["<<lc<<"]"<<n,mat[i][lc] = n++;
			cout<<endl;
			lc--;
			for(i=lc ; i>=fc ; i--)
				cout<<"["<<fr<<"]["<<i<<"]"<<n,mat[fr][i] = n++;
			cout<<endl;
					fr++;
		}
		for(i=0 ; i<row ; i++){
			for(int j=0 ; j<col ; j++)
				cout<<mat[i][j]<<" ";
			cout<<endl;
		}
		cout<<endl;
	}
	return 0 ;
}


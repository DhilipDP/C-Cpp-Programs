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


#define ll long long
#define p(a) printf("%d\n",a)
#define s(a) scanf("%d",&a)
#define sl(a) scanf("%lld",&a)
#define sll(a) scanf("%ld",&a)
#define FOR(a,b) for(int i=a ; i<=b ; ++i)

using namespace std ;


 vector<int> spiralOrder(vector<vector<int> > &matrix) {
 		vector<int> v ;
 		int m = matrix.size() ;
 		if(m==0)
 			return v ;
		int n = matrix[0].size() ;     
		cout<<m<<" "<<n<<endl;
		int fr=0,lr=m-1,fc=0,lc=n-1 ;
		int i,j;
		while(fr <=lr && fc<=lc){
			//first row
			cout<<fr<<" "<<lr<<" "<<fc<<" "<<lc<<endl;
			for(i=fc ; i<=lc ; i++)
				v.push_back(matrix[fr][i]);
			
			fr++;
			
			//last col
			
			for(i=fr ; i<=lr ; i++)
				v.push_back(matrix[i][lc]);
			lc--;
			
			//last row
			if(lr >= fr){
			for(i = lc ; i>=fc ; i--)
				v.push_back(matrix[lr][i]);
				
			lr--;
			}
			
			//first col
			if(lc >= fc){
			for(i=lr ; i>=fr ; i--)
				v.push_back(matrix[i][fc]);
			fc++;
			}
		}
		return v;
  }
int main() {
	
	vector<vector<int> > matrix ;
	vector<int> row ;
	row.push_back(1) ;
	row.push_back(2) ;
	row.push_back(3) ;
//		row.push_back(4) ;
	matrix.push_back(row) ;
	row.clear() ;
	
	row.push_back(5) ;
	row.push_back(6) ;
	row.push_back(7) ;
//	row.push_back(8) ;
	matrix.push_back(row) ;
/*	row.clear() ;
	
	row.push_back(9) ;
		row.push_back(10) ;
	row.push_back(11) ;
		row.push_back(12) ;
	matrix.push_back(row) ;
	row.clear() ;
	
		row.push_back(13) ;
	row.push_back(14) ;
		row.push_back(15) ;
	row.push_back(16) ;
	
		matrix.push_back(row) ;*/
	vector<int> v = spiralOrder(matrix);
	
	vector<int> :: iterator it ;
	for(it = v.begin() ; it!=v.end() ; it++)
		cout<<*it<<" " ;
	cout<<endl;
	return 0 ; 
}

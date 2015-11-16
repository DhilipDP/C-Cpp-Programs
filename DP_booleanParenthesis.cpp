#include<iostream>
using namespace std ;


int countParen(string symbol,string op){

	int n =  symbol.length() ;
	int T[n][n] , F[n][n] ;
	int i,gap,j,k,g ;
	for(i=0 ; i<n ; i++)
	{
		T[i][i] = (symbol[i]=='T') ? 1 : 0 ;
		F[i][i] = (symbol[i]=='F') ? 1 : 0 ;
	}
	for(gap = 1 ; gap < n ; gap++){
		for(i=0,j=gap ; j<n ; i++,j++){
			T[i][j] = F[i][j] = 0;
			cout<<"i:" <<i<<" j: "<<j<<endl;
			for(g=0 ; g<gap ; g++){
				
				
				k = i+g;
				
				cout<<i<<" "<<j<<" "<<k<<" : ";
				int tik = T[i][k] + F[i][k] ;
				int tkj = T[k+1][j] + F[k+1][j] ;
				cout<<tik<<" "<<tkj<<" ";
				if(op[k]=='&'){
					cout<<"and ";
					T[i][j] += (T[i][k] * T[k+1][j]);
					F[i][j] += tik*tkj - T[i][k]*T[k+1][j];
				}
				else if(op[k]=='^'){
					cout<<"xor ";
					T[i][j] += T[i][k]*F[k+1][j] + F[i][k]*T[k+1][j];
					F[i][j] += T[i][k]*T[k+1][j] + F[i][k]*F[k+1][j];
				}
				else if(op[k]=='|'){
					cout<<"or ";
					T[i][j] += tik*tkj - F[i][k]*F[k+1][j];
					F[i][j] += F[i][k]*F[k+1][j]; 
				
				}
			}	
			cout<<"T["<<i<<"]["<<j<<"] : " <<T[i][j]<<endl ;
		}
	}
	cout<<"Hello\n";
	int tr[n][n] ,fa[n][n];
	for(i=0 ; i<n ; i++){
		tr[i][i] = (symbol[i]=='T') ? 1 : 0 ;
		fa[i][i] = (symbol[i]=='F') ? 1 : 0;
		cout<<tr[i][i] <<" "<<fa[i][i]<<endl;
	}
	cout<<"start"<<endl;
	for(int l=1 ; l<=n ; l++){
		for(i=0 ; i<=n-l ; i++){
			j = i+l-1 ;
			if(i!=j)
			tr[i][j] = fa[i][j] = 0;
			cout<<"i:" <<i<<" j: "<<j<<endl;
			for(k=i ; k<j ; k++){
				cout<<i<<" "<<j<<" "<<k<<" : ";
				int tik = tr[i][k] + fa[i][k] ;
				int tkj = tr[k+1][j] + fa[k+1][j] ;
				cout<<tik<<" "<<tkj<<" ";
				if(op[k]=='&'){
					cout<<"and ";
					tr[i][j] += (tr[i][k] * tr[k+1][j]) ;
					fa[i][j] += (tik*tkj - tr[i][k]*tr[k+1][j]) ;
				}
				else if( op[k]=='|' ){
					cout<<"or ";
					tr[i][j] += (tik*tkj - fa[i][k]*fa[k+1][j]) ;
					fa[i][j] += (fa[i][k] * fa[k+1][j]) ;
				}
				else if(op[k]=='^'){
					cout<<"xor ";
					tr[i][j] += (tr[i][k]*fa[k+1][j] + fa[i][k] * tr[k+1][j]) ;
					fa[i][j] +=	(tr[i][k]*tr[k+1][j] + fa[i][k] *  fa[k+1][j] );			
				}
			}
				cout<<"T["<<i<<"]["<<j<<"] : " <<tr[i][j]<<endl ;
		}
	}
	cout<<tr[0][n-1] <<endl;
	return T[0][n-1] ;
}

int main(){

	string symbols = "TTFT" ;
	string op = "|&^";
	cout<<countParen(symbols,op);
}

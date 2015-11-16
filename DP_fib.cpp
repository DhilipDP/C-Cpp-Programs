#include<iostream>
using namespace std;





int _memo(int n,int *tab){

	if(tab[n]==-1){
		if(n<=1)
			tab[n] = n;
		else
		tab[n] = _memo(n-1,tab) + _memo(n-2,tab);			
	}
	return tab[n];

}


int memorisation(int n){

	int tab[n+1];
	memset(tab,-1,sizeof(tab));
	return _memo(n,tab);

}


int tabulation(int n){

	int fib[n+1];
	fib[0]=0 ; fib[1] =1;
	for(int i=2 ; i<=n ; i++)
		fib[i] = fib[i-1] + fib[i-2];
	return fib[n];
}
int main(){
	
		
		int n=10,fib;
		fib = memorisation(n);
		cout<<fib<<endl;
		fib = tabulation(n);
		cout<<fib<<endl;

}

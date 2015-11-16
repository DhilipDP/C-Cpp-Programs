#include<iostream>

using namespace std ;

int f[10000]={-1};

int fib(int n,int k,int *tab,int &c){
//	int arr[n][n] ;
	cout<<n<<endl;
	if(n==k)
			c++;
	if(tab[n]==-1){
	//	cout<<n<<endl;
		
		if(n<=1)
			tab[n] = n;
		else
			tab[n] =  fib(n-1,k,tab,c) + fib(n-2,k,tab,c);
	}
	return tab[n] ;
}


int main(){
	
	int t ;
	cin>>t ;
	while(t--){
		int n,k ;
		cin>>n>>k;
		int tab[10001] ;
		memset(tab,-1,sizeof(tab));
		int c=0;
		fib(n,k,tab,c);
		cout<<c<<endl;
	}

//	cout<<fib(5)<<endl;
	
//	for(int i=0 ; i<10 ; i++)
//		cout<<arr[i]<<" ";
	cout<<endl;
}

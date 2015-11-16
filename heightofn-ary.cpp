#include<iostream>
#include<math.h>


using namespace std ;


/*
	#nodes(n) = k^(h+1)-1 / (k-1) 
	
	so.. n(k-1)+1 = k^(h+1)
	
	 h  =  log (n) + log(k-1) -1
*/ 
int main(){
	int n,k;
	cout<<"<--N-ary tree-->\n";
	cout<<"\nEnter degree: ";
	cin>>k;
	cout<<"\nNumber of nodes: ";
	cin>>n;
	int height ;
	
	if(n==1 && k == 2)
		height = 0;
	
	else
		height =  (ceil((log10(k-1)/log10(k)) + (log10(n)/log10(k))-1)) ;
	cout<<height<<endl;
}

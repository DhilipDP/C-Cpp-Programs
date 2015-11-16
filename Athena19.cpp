#include<iostream>
#include<map>
using namespace std ;

//map<int,int> t;
map<int,int> p;



int isPrime(long long int number) {
    if (number <= 1) return 0; // zero and one are not prime
    long long int i;
    for (i=2; i*i<=number; i++) {
        if (number % i == 0) return 0;
    }
    return 1;
}
int main(){
	int i=1;
	for(i=0 ; i<=1000 ; i++)
		p[i*(i+1)]=1;
	int no =0;
	for(int n=999999 ; n>=100000 ; n--){
		
		int c =0;
		for(int i=2 ; i*i <= n ; i++){
			if(n%i==0){
				if(p[i]==1)
					c++;
				if(n/i != i && p[n/i]==1)
					c++;
			}			
		}
	//	cout<<c<<endl;
		if(isPrime(c))
			no++,cout<<n<<endl;
		if(no==10)
			break;
		
	
	}
}

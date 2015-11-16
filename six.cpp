#include<iostream>

using namespace std ;


int isPrime(long long int number) {
    if (number <= 1) return 0; // zero and one are not prime
    long long int i;
    for (i=2; i*i<=number; i++) {
        if (number % i == 0) return 0;
    }
    return 1;
}
int main(){
 int  n ;
	int no = 1;
	for(n=100000 ; n<=999999 ; n++){
		//cout<<n<<":"<<endl;
		int arr[6] ;
		int temp = n;
		int k=5;
		while(temp > 0){
			arr[k--] = temp%10;
			temp /= 10;
		}
	//	for(int i=0 ; i<6 ; i++)
	//		cout<<arr[i]<<" ";
		
		if(isPrime(arr[2]*10 + arr[3])  &&  (arr[0]*10 + arr[5] == arr[4]*arr[4]) && (arr[2]!=0 && arr[1]%arr[2]==0))
			cout<<no++<<": "<<n<<endl;
		if(no==38)
			break;
	
	}

}

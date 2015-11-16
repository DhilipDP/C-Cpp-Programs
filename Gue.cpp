#include<iostream>

using namespace std;
long long int gcd(long long int a, long long int b)
{
    if (a<b)
        return gcd(b,a);

    if (b==0)
        return a;

    else 
            return gcd (b,a%b);
}

long long int findlcm(long long int a,long long int b){
	return (a*b)/(gcd(a,b));
}

int main(){
	while(1){
		string s;
		long long int lcm = 1,j=0;
		long long int no[50];
		long long int count = 0;
		cin>>s;
		if(s=="*")
			break;
		for(long long int i=0 ; s[i]  ; i++)
		{
			count++;
			if(s[i]=='Y'){
				lcm = findlcm(lcm,count);
				//cout<<lcm;
			}
			else{
				no[j++]=count;
//				cout<<no[j-1];
			}
		}
		for(long long int i=0 ; i<j ; i++)
		{
			if(lcm % no[i] == 0){
				lcm = -1;
				break;
			}
		}
		cout<<lcm<<endl;
	}
}


#include<stdio.h>
#include<algorithm>
#include<iostream>
using namespace std;


string convert(long long int num){
	string binary="";
	long long int quo=num,rem;
	while(quo!=0){
		rem = quo % 2;
		quo /= 2;
		binary.push_back(rem+'0');
	}
	reverse(binary.begin(),binary.end());
	return binary;
}

long long int find(string str){
//	cout<<endl<<str;
	long long int i,a_count = 0,b_count=0;
	 for( i=0 ; i<str.length() ; i++){
					if(str[i]-'0' == 1){
						if(i%2==0)
							b_count++;
						else
							a_count++;
					}
	}

		return abs(a_count - b_count);
}
int main(){
//	cout<<find(convert(19));
	int tests;
	scanf("%d",&tests);
	while(tests--){
		long long int m,n;
		int k,count=0;
		scanf("%lld%lld%d",&m,&n,&k);
		for(long long int i=m ; i<=n ;i++){
			string number = convert(i);
		//	cout<<number<<endl;
			long long int dif = find(number);
			if(dif==k)
				count++;
		}
		printf("%d\n",count);
	}
}

/*#include<iostream>

using namespace std;
long long int find_gcd(long long int num,long long int den)
{
//	cout<<"gcd";
	if(num < den)
		return find_gcd(den,num);
	if(den==0 || den==1)
		return num;
	return (den,num%den);
}

long long int findlcm(long long int a,long long int b){
//	cout<<find_gcd(a,b);
	return (a*b)/(find_gcd(a,b));
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
				cout<<lcm;
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
*/
#include<stdio.h>

long long int gcd(long long int a, long long int b)
{
    if (a<b)
        return gcd(b,a);

    if (b==0)
        return a;

    else 
            return gcd (b,a%b);
}

long long int lcm(long long int a,long long int b)
{
    return (a*b)/gcd(a,b);
}    

int main()
{
    char c;
    long long int count, k, i ,j;
    
    while(1)
    {
        count=0;
        k=1;
        i = 0;
        int toCheck[21];
        scanf("%c",&c);
        while(c!='\n' && c!='*')
        
        {
            count++;
                    
            if (c=='Y')
            {
                k= lcm(k,count);
            }
            else if(c=='N')
            {
                toCheck[i++]  = count;        
            }    
            scanf("%c",&c);
                
        }
        
        for(j = 0 ; j< i ; j++)
        {
            if(k%toCheck[j]==0)
                {
                    k=-1;
                    break;
                }
        }
        if(c=='*')
            break;
        printf("%lld\n",k);
        
    }
    return 0;
}

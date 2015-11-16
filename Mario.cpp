#include<bits/stdc++.h>

#define ll long long
#define p(a) printf("%d\n",a)
#define s(a) scanf("%d",&a)
#define sll(a) scanf("%lld",&a)
#define sl(a) scanf("%ld",&a)
#define rep(a,b,c) for(int c=a ; c<=b ; ++c)
#define pii pair<int , int>
#define vi vector<int>
#define vs vector<string>
#define vi_it vector<int> :: iterator
#define vs_it vector<string> :: iterator
#define mp(a,b) make_pair(a,b)

using namespace std ;

int n = 10000;
vector<bool> arr(n+1,0);
vector<int> S(n+1);


int fun(int num)
{
	int sum  = 0;
	while(num > 0)
	{
		sum += (num % 10) ;
		num /=10;
	}
	return sum;
}
void sum()
{
		S[0] = S[1] = 0;
		rep(2,n,i)
		{
			S[i] = S[i-1];
			if(!arr[i])
			{
			
				S[i] += fun(i);
				
			}
			}
}

void markMultiples( int a, int n)
{
    int i = 2, num;
    while ( (num = i*a) <= n )
    {
        arr[ num ] = 1; // minus 1 because index starts from 0.
        ++i;
    }
}

void seive()
{


// A function to print all prime numbers smaller than n
    // There are no prime numbers smaller than 2
        // Create an array of size n and initialize all elements as 0
     

        /* Following property is maintained in the below for loop
           arr[i] == 0 means i + 1 is prime
           arr[i] == 1 means i + 1 is not prime */
        for (int i=2; i<sqrt(n); ++i)
        {
            if ( arr[i] == 0 )
            {
            
                //(i+1) is prime, print it and mark its multiples
                markMultiples( i, n);
            }
        }
    }


int main() {
	ios :: sync_with_stdio(false);
	seive();
	//cout<<"S";
	sum();
	int t ; s(t) ;
	while(t--)
	{
		int a,b ;s(a);s(b);
	//	p(S[b]) ;
	//	p(S[a-1]);
		p(S[b]-S[a-1]);
	}
	return 0;
}

#include<bits/stdc++.h>

#define ll long long
#define p(a) printf("%d\n",a)
#define pll(a) printf("%lld\n",a)
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
#define MOD 1000000007


using namespace std ;

int n  = 10004;

vi v(80000);
map<int ,bool > arr;
int  c;
// marks all mutiples of 'a' ( greater than 'a' but less than equal to 'n') as 1.
void markMultiples( int a, int n)
{
    int i = 2, num;
    while ( (num = i*a) <= n )
    {
        arr[ num-1 ] = true; // minus 1 because index starts from 0.
        ++i;
    }
}

// A function to print all prime numbers smaller than n
void sieve(int n)
{
    // There are no prime numbers smaller than 2
    if (n >= 2)
    {
        // Create an array of size n and initialize all elements as 0
     

        /* Following property is maintained in the below for loop
           arr[i] == 0 means i + 1 is prime
           arr[i] == 1 means i + 1 is not prime */
        for (int i=1; i<n; ++i)
        {
            if ( arr[i] == false )
            {
                //(i+1) is prime, print it and mark its multiples
                v[c] = i+1;
//                printf("%d ", i+1);
                c++;
                markMultiples( i+1, n);
            }
        }
    }
}


int cost = 1000;
int dp[1000];


int getMinCoins(vector<int> & denom, int amount)
{
	int * counts = new int[ amount + 1 ];
	int coins = 0;
	counts[0] = 0;
	
	int i, j;
	for( i = 1; i <= amount; i++ )
	{
		coins = INT_MAX;
		
		for( j = 0; j < denom.size(); j++ )
		{
			if( denom[j] <= i )//coin value should not exceed the amount itself
			{
				coins = min( coins, counts[i-denom[j]] );
			}
			else
				break;
		}	
		
		if( coins < INT_MAX )
			counts[i] = coins + 1;
		else
			counts[i] = INT_MAX;
	}
	
	coins = counts[amount];
	delete[] counts;
	return coins;
}



int main() {
	ios :: sync_with_stdio(false);
	
	sieve(n);
	//cout<<"done";
//	minCoins();
	//cout<<"pk";
	
	
	int t ; s(t) ;
	while( t-- )
	{
		int num ; s(num) ;
		p(getMinCoins(v,num));
	}
	return 0;
}


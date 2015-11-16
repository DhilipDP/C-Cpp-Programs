#include <stdio.h>
#include <string.h>
#include<map>
using namespace std;

map<int ,int > arr;
int  c;
// marks all mutiples of 'a' ( greater than 'a' but less than equal to 'n') as 1.
void markMultiples( int a, int n)
{
    int i = 2, num;
    while ( (num = i*a) <= n )
    {
        arr[ num-1 ] = 1; // minus 1 because index starts from 0.
        ++i;
    }
}

// A function to print all prime numbers smaller than n
void SieveOfEratosthenes(int n)
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
            if ( arr[i] == 0 )
            {
                //(i+1) is prime, print it and mark its multiples
                printf("%d ", i+1);
                c++;
                markMultiples( i+1, n);
            }
        }
    }
}

// Driver Program to test above function
int main()
{
    int n = 100000;
    printf("Following are the prime numbers below %d\n", n);

    SieveOfEratosthenes(1000000);
        printf("\n%d\n",c);
    return 0;
}

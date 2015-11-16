/**
calculate mean and variance of a list of integers
*/

#include <cstdlib>
#include <cstdio>

using namespace std;

#define PAUSE {printf("Press Enter to continue...\n"); fflush(stdin); getchar(); fflush(stdin);}


/**
 * calculate the mean of the provided list values, containing n values.
 */
float mean(float values[], int n)
{
    float sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += values[i];
    }
    return sum / (float)n;
}


/**
 * calculate the variance of the provided list values, containing n values.
 */
float var(float values[], int n)
{
    float valuesMean = mean(values, n);
     float sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += (values[i] - valuesMean) * (values[i] - valuesMean);
    }
    return sum / (n-1);
}


int main()
{
   
    float values[] = {2.1, 2.3, 5.5, 6.9, 9.1, 9.4, 10.1, 11.7, 12.3, 15.2, 15.6, 16.1, 16.3, 17.6, 18.2, 21.1, 21.5, 22.7, 22.9, 23.1, 25.3, 27.1, 27.1, 27.5, 27.8, 30.4, 33.3, 36.1, 39.1, 39.5, 40.6, 40.9, 42.4, 43.8, 43.9, 44.1, 44.6, 45.8, 46.5, 48.8, 48.9, 49.4, 50.5, 50.7, 50.9, 52.9, 53.7, 54.2, 54.5, 54.9, 55.6, 55.7, 55.8, 58.5, 58.7, 59.1, 61.7, 62.8, 63.1, 64.6, 64.7, 64.9, 65.2, 65.2, 66.3, 66.5, 67.8, 68.1, 69.6, 70.1, 70.5, 70.7, 72.6, 73.1, 74.7, 74.8, 75.3, 77.4, 78.4, 78.8, 79.1, 79.3, 79.3, 80.4, 80.5, 81.5, 83.7, 85.7, 87.6, 89.1, 89.5, 91.1, 91.2, 91.2, 91.4, 91.7, 92.4, 94.2, 98.7, 100.7};
    int valuesNum = sizeof(values)/sizeof(values[0]); 
    int valuesMean = mean(values, valuesNum);
    printf("mean=%f \n", valuesMean);     // mean=8

    int valuesVar = var(values, valuesNum);
    printf("var=%f \n", valuesVar);            // var=26
    
    PAUSE;
    return EXIT_SUCCESS;
}



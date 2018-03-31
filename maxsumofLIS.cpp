/* implementation of Maximum Sum Increasing
Subsequence (MSIS) problem */

#include <iostream>
using namespace std;

/* maxSumIS() returns the maximum sum of increasing subsequence
    in arr[] of size n */
int maxSumIS( int arr[], int n )
{
    int i, j, max = 0;
    int maxsum[n];

    /* Initialize msis values for all indexes */
    for ( i = 0; i < n; i++ )
        maxsum[i] = 1;

    /* Compute maximum sum values in bottom up manner */
    for ( i = 1; i < n; i++ ){
         for ( j = 0; j < i; j++ ){
                if (( arr[i] > arr[j]) && (maxsum[i] < maxsum[j] + arr[i]))  {
                             maxsum[i] = maxsum[j] + arr[i];
                }                             //


    }

         }


    /* Pick maximum of all msis values */
    for ( i = 0; i < n; i++ )
        if ( max < maxsum[i] )
            max = maxsum[i];

    return max;
}


int main()
{
    int arr[] = {1,3,2,5,4};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"Sum of maximum sum increasing subsequence is "<<
           maxSumIS( arr, n );
    return 0;
}

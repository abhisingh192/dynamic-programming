/* implementation of Longest Increasing Subsequence problem */

#include<stdio.h>
#include<stdlib.h>

/* lis() returns the length of the longest increasing
  subsequence in arr[] of size n */

int lis( int arr[], int n )
{
    int *lis, i, j, max = 0;
    lis = (int*) malloc ( sizeof( int ) * n );

    /* Initialize LIS values for all indexes to 1 as each longest subsequence will be as large as itself */
    for (i = 0; i < n; i++ )
        lis[i] = 1;

    /* Compute optimized LIS values in bottom up manner */
    for (i = 1; i < n; i++ )                               // initialize i to 1
        for (j = 0; j < i; j++ )                            //initialize j to 0
            if ( arr[i] > arr[j] && lis[i] < lis[j] + 1)
                lis[i] = lis[j] + 1;

    /* Pick maximum of all LIS values */
    for (i = 0; i < n; i++ )
        if (max < lis[i])
            max = lis[i];

    /* Free memory to avoid memory leak */
    free(lis);

    return max;
}

/* Driver program to test above function */
int main()
{
    int n;
    scanf("%d",&n);
    int arr[n];

    int i;
    for(i=0;i<n;i++)
    scanf("%d",&arr[i]);

    printf("Length of lis is %dn", lis( arr, n ) );
    return 0;
}

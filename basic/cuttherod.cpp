// A Dynamic Programming solution for Rod cutting problem (maximize the profit)

#include<stdio.h>
#include<limits.h>

// A utility function to get the maximum of two integers
int max(int a, int b) { return (a > b)? a : b;}

/* Returns the best obtainable price for a rod of length n and
   price[] as prices of different pieces */
int cutRod(int price[], int n)
{
   int val[n+1];
   val[0] = 0;
   int i, j;

   // Build the table val[] in bottom up manner and return the last entry
   // from the table
   for (i = 1; i<=n; i++)
   {
       int max_val = INT_MIN;
       for (j = 0; j < i; j++)
         max_val = max(max_val, price[j] + val[i-j-1]);
       val[i] = max_val;
   }

   return val[n];
}


int main()
{
    int n; scanf("%d",&n);
    int arr[n] ;
    int i;

    for(i=0;i<n;i++)
    scanf("%d",&arr[i]);

    printf("Maximum Obtainable Value is %d", cutRod(arr, n));
    getchar();
    return 0;
}

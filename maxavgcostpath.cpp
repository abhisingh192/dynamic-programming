//    C/C++ program to find maximum average cost path where you can only move right or down
// slight variation of the maximum sum path, just calculate the maximum sum and take the average

#include <bits/stdc++.h>
using namespace std;

// Maximum number of rows and/or columns
const int M = 100;

// method returns maximum average of all path of
// cost matrix
double maxAverageOfPath(int cost[M][M], int N)
{
    int dp[N+1][N+1];
    dp[0][0] = cost[0][0];

    /* Initialize first column of total cost(dp) array */
    for (int i = 1; i < N; i++)
        dp[i][0] = dp[i-1][0] + cost[i][0];

    /* Initialize first row of dp array */
    for (int j = 1; j < N; j++)
        dp[0][j] = dp[0][j-1] + cost[0][j];

    /* Construct rest of the dp array */
    for (int i = 1; i < N; i++)
        for (int j = 1; j <= N; j++)
            dp[i][j] = max(dp[i-1][j],
                          dp[i][j-1]) + cost[i][j];

    // divide maximum sum by constant path
    // length : (2N - 1) for getting average
    return (double)dp[N-1][N-1] / (2*N-1);
}

/* Driver program to test above functions */
int main()
{
    int cost[M][M] = { {1, 2, 3},
        {6, 5, 4},
        {7, 3, 9}
    };
    printf("%f", maxAverageOfPath(cost, 3));
    return 0;
}

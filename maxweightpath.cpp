// C++ program to find the path having the
// maximum weight in matrix
#include<bits/stdc++.h>
using namespace std;
const int MAX = 1000;

/* Function which return the maximum weight
   path sum */
int maxCost(int mat[][MAX], int N)
{
    // creat 2D matrix to store the sum of the path
    int dp[N][N];
    memset(dp, 0, sizeof(dp));

    dp[0][0] = mat[0][0];

    // Initialize first column of total weight
    // array (dp[i to N][0])
    for (int i=1; i<N; i++)
        dp[i][0] = mat[i][0] + dp[i-1][0];

    // Calculate rest paht sum of weight matrix
    for (int i=1; i<N; i++)
       for (int j=1; j<i+1&&j<N; j++)
          dp[i][j] = mat[i][j] +
                    max(dp[i-1][j-1], dp[i-1][j]);

    // find the max weight path sum to rech
    // the last row
    int result = 0;
    for (int i=0; i<N; i++)
        if (result < dp[N-1][i])
            result = dp[N-1][i];

    // return maximum weight path sum
    return result;
}

// Driver program
int main()
{
    int mat[MAX][MAX] = {  { 4, 1 ,5 ,6 , 1 },
        { 2 ,9 ,2 ,11 ,10 },
        { 15,1 ,3 ,15, 2 },
        { 16, 92, 41,4,3},
        { 8, 142, 6, 4, 8 }
    };
    int N = 5;
    cout << "Maximum Path Sum : "
        << maxCost(mat, N)<<endl;
    return 0;
}

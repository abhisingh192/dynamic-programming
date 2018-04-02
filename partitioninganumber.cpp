// A Dynamic programming based C++ program
// to find maximum sum by recursively breaking
// a number in 3 parts.

#include<bits/stdc++.h>
#define MAX 1000000
using namespace std;

int breakSum(int n)
{
    int dp[n+1];

    // base conditions
    dp[0] = 0, dp[1] = 1;

    // Fill in bottom-up manner using recursive
    // formula.
    for (int i=2; i<=n; i++)
       dp[i] = max(dp[i/2] + dp[i/3] + dp[i/4], i);

    return dp[n];
}

// Driver program to run the case
int main()
{
    int n = 24;
    cout << breakSum(n);
    return 0;
}

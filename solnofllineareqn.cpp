/* find number of "Non-Negative" solutions for a given linear equation where coeff matric represents the coefficients of the terms x,y,z(in order).
if coeff matrix contains only 2 terms it means equation has only 2 variables.Here 'n' tells about the number of variables.
and rhs is the right hand side of the equation */

// this problem is a variation of the coin changing problem in which we are asked to find how many ways we can change a given sum
// eg : sum is 5 and we have {2,2,5} coins(means we have two 2rs coins and 1 5rs coin). solutions are (1,1,0),(2,0,0),(0,2,0)

#include<bits/stdc++.h>
using namespace std;

// Returns counr of solutions for given rhs and coefficients
// coeff[0..n-1]
int countSol(int coeff[], int n, int rhs)
{
    // Create and initialize a table to store results of
    // subproblems
    int dp[rhs+1];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;

    // Fill table in bottom up manner
    for (int i=0; i<n; i++)
      for (int j=coeff[i]; j<=rhs; j++)
         dp[j] += dp[j-coeff[i]];

    return dp[rhs];
}


int main()
{
    int n;
    cout<<"enter the number of variables"<<endl;
    cin>>n;
    int coeff[n] ;

    int i;
    cout<<"enter the variables in order"<<endl;
    for(i=0;i<n;i++)
    cin>>coeff[i];

    int rhs;
    cout<<"enter the rhs"<<endl;
    cin>>rhs;

    cout << countSol(coeff, n, rhs);
    return 0;
}

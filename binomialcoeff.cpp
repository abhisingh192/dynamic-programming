// A Dynamic Programming based solution that uses table C[][] to calculate the Binomial Coefficient
// Makes use of the fact that C(i,j) =  C(i-1,j-1) + C(i-1,j)  and C(i,0) = 1 = C(i,i)


#include<iostream>
using namespace std;

// A utility function to return minimum of two integers
int min(int a, int b)
{
    return (a<b)? a: b;
}

// Returns value of Binomial Coefficient C(n, k)
int binomialCoeff(int n, int k)
{
    int C[n+1][k+1];
    int i, j;

    // Caculate value of Binomial Coefficient in bottom up manner
    for (i = 0; i <= n; i++)
    {
        for (j = 0; j <= min(i, k); j++)
        {
            // Base Cases
            if (j == 0 || j == i)
                C[i][j] = 1;

            // Calculate value using previously stored values
            else
                C[i][j] = C[i-1][j-1] + C[i-1][j];
        }
    }

    return C[n][k];
}





int main()
{
    cout<<"Enter two numbers (first greater than or equal to the first)"<<endl;
    int n , k;  cin>>n>>k;
    int ans = binomialCoeff(n, k);
    cout<<ans;
    return 0;
}

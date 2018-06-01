//m*n grid traversal (only right and down moves allowed)

#include <iostream>
using namespace std;

// Returns count of possible paths to reach cell at row number m and column
// number n from the topmost leftmost cell (cell at 1, 1)
int numberOfPaths(int m, int n)
{
    // Create a 2D table to store results of subproblems
    int count[m][n];

    // Count of paths to reach any cell in first row is 1
    for (int i = 0; i < m; i++)
        count[i][0] = 1;

    // Count of paths to reach any cell in first column is 1
    for (int j = 0; j < n; j++)
        count[0][j] = 1;

    // Calculate count of paths for other cells in bottom-up manner using
    // the recursive solution
    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)

            count[i][j] = count[i-1][j] + count[i][j-1];

    }
    return count[m-1][n-1];
}

// Driver program to test above functions
int main()
{
    int m,n;
    cout<<"enter the rows and columns respectively"<<endl;
    cin>>m>>n;
    cout << numberOfPaths(m,n);
    return 0;
}

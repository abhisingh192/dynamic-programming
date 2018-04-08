// C++ program to print maximum sum
// in a right triangle of numbers
#include<bits/stdc++.h>
using namespace std;

// function to find maximum sum path
int maxSum(int tri[][3], int n)
{
    // Adding the element of row 1 to both the
    // elements of row 2 to reduce a step from
    // the loop
    if (n > 1)
        tri[1][1] = tri[1][1] + tri[0][0];
        tri[1][0] = tri[1][0] + tri[0][0];

    // Traverse remaining rows
    for(int i = 2; i < n; i++) {
        tri[i][0] = tri[i][0] + tri[i-1][0];
        tri[i][i] = tri[i][i] + tri[i-1][i-1];

        //Loop to traverse columns
        for (int j = 1; j < i; j++){

            // Checking the two conditions,
            // directly below and below right.
            // Considering the greater one

            // tri[i] would store the possible
            // combinations of sum of the paths
            if (tri[i][j] + tri[i-1][j-1] >=
                            tri[i][j] + tri[i-1][j])

                tri[i][j] = tri[i][j] + tri[i-1][j-1];
            else
                tri[i][j] = tri[i][j]+tri[i-1][j];
        }
    }

    // array at n-1 index (tri[i]) stores
    // all possible adding combination, finding
    // the maximum one out of them
    int max=tri[n-1][0];

    for(int i=1;i<n;i++)
    {
        if(max<tri[n-1][i])
            max=tri[n-1][i];
    }

    return max;
}

// driver program
int main(){

    int tri[3][3] = {{1}, {2,1}, {3,3,2}};

    cout<<maxSum(tri, 3);

    return 0;
}

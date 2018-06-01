// subset sum problem
// given a set and a sum, find whether that sum can be obtained using the subsets of the given set or not

#include<iostream>
#include <cstdio>
using namespace std;

// Returns true if there is a subset of set[] with sun equal to given sum
bool isSubsetSum(int set[], int n, int sum)
{
    // The value of subset[i][j] will be true if there is a
    // subset of set[0..j-1] with sum equal to i
    bool subset[n+1][sum+1];

    // If sum is 0, then answer is true
    for (int i = 0; i <= n; i++)
      subset[i][0] = true;

    // If sum is not 0 and set is empty, then answer is false
    for (int i = 1; i <= sum; i++)
      subset[0][i] = false;

     // Fill the subset table in botton up manner
     for (int i = 1; i <= n; i++)
     {
       for (int j = 1; j <= sum; j++)
       {
         if(j<set[i-1])
         subset[i][j] = subset[i-1][j];
         if (j >= set[i-1])
           subset[i][j] = subset[i-1][j] ||
                                 subset[i - 1][j-set[i-1]];
       }
     }



     return subset[n][sum];
}

// Driver program to test above function
int main()
{
  int n;
  cout<<"enter the number of elements in the set"<<endl;
  cin>>n;
  int set[n];
  int i;
  cout<<"enter the elements"<<endl;
  for(i=0;i<n;i++)
    cin>>set[i];
  int sum;
  cout<<"enter the sum"<<endl;
  cin>>sum;

  if (isSubsetSum(set, n, sum) == true)
     printf("Found a subset with given sum");
  else
     printf("No subset with given sum");
  return 0;
}

// C++ program to print largest contiguous array sum using Kadane's algorithm

#include<iostream>
#include<climits>
#include<algorithm>
using namespace std;

/*Simple idea of the Kadane's algorithm is to look for all positive contiguous segments of the array (max_ending_here is used for this). And keep track of maximum sum contiguous segment among all positive segments (max_so_far is used for this).
Each time we get a positive sum compare it with max_so_far and update max_so_far if it is greater than max_so_far */

int maxSubArraySum(int a[], int size)
{
   int flag = 0;                           // for the case when all the entries are negative
   int max_so_far = 0, max_current = 0;
   for (int i = 0; i < size; i++)
   {
       max_current = max_current + a[i];
       if (max_current < 0)
           max_current = 0;

       /* Do not compare for all elements. Compare only
          when  max_ending_here > 0 */
         else if (max_so_far < max_current){
            max_so_far = max_current;
            flag = 1;
         }

   }
   sort(a,a+size);                           /* all entries are negative, returning the last element(that is the biggest as we have sorted the arra */
   if(!flag)
    max_so_far = a[size - 1];

   return max_so_far;
}

/*Driver program to test maxSubArraySum*/
int main()
{
    int n;  cin>>n;      // 'n' is the size of the  array
    int a[n] ;
    int i;

    for(i=0;i<n;i++)
        cin>>a[i];

    int max_sum = maxSubArraySum(a, n);
    cout << "Maximum contiguous sum is " << max_sum;
    return 0;
}

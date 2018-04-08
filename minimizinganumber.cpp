//Minimum steps to minimize n as per given condition

/* Given a number n, count minimum steps to minimize it to 1 according to the following criteria:
If n is divisible by 2 then we may reduce n to n/2.
If n is divisible by 3 then you may reduce n to n/3.
Decrement n by 1.   */

// this is same as the coin change problem

#include<iostream>
#include<limits.h>

using namespace std;

int coin_change( int denominations[], int n, int value )
{
    if(value<0||n<=0)
    return 0;
    int total_coin[value+1][n];
    int i,j,x,y;
    for (i = 1; i <=value; i++)
    {
        for (j = 0; j <= n-1; j++)
        {
            total_coin[i][j]=9999999;
        }
    }

    //If sum is 0 , you can always make change of nothing
    for (i=0; i<n; i++){
        total_coin[denominations[i]][i]=1;
    }

    for (i = 1; i <=value; i++)
    {
        for (j = 0; j <= n-1; j++)
        {
            x=y= 9999999;
            //Include the jth denomination
            if(i-denominations[j] >= 0){
                if(i-denominations[j] == 0)
                x =1;
                else if(i-denominations[j] > 0)
                x = total_coin[i - denominations[j]][j]+1;
            }
            //Exclude the denomination
            if(j >= 1){
                y = total_coin[i][j-1];
            }
            total_coin[i][j] = min(x,y);
        }
    }
    return total_coin[value][n-1];
}


// Driver program to test above function
int main()
{
    int arr[] = {1,2,3};
    int m = sizeof(arr)/sizeof(arr[0]);
    int n;
    cout<<"enter the number you want to minimize "<<endl;
    cin>>n;
    cout<< coin_change(arr, m, n);
    return 0;
}

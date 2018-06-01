//Fibonacci Series using Dynamic Programming

#include<iostream>
using namespace std;

int fib(int n)
{

  int f[n+1];            /* Declare an array to store Fibonacci numbers. */
  int i;


  f[0] = 0;              /* 0th and 1st number of the series are 0 and 1*/
  f[1] = 1;

  for (i = 2; i <= n; i++)
  {
      f[i] = f[i-1] + f[i-2];   /* Add the previous 2 numbers in the series
                                  and store it */
  }

  return f[n];
}

int main ()
{
  cout<<"Enter a number"<<endl;
  int n;  cin>>n;
  int ans = fib(n);
  cout<<ans;

  return 0;
}

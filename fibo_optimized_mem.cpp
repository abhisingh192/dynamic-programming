// Fibonacci Series using Space Optimized Method

#include<iostream>
using namespace std;

int fib(int n)
{
  int last = 0, current = 1, next, i;        // "last" denotes F(0)=0, "current" denotes F(1)=1, "next" will store the next fibonacci number
  if( n == 0)
    return last;
  for (i = 2; i <= n; i++)
  {
     next = last + current;                 //  suppose we want to calculate F(3), so we first calculate F(2)=F(1)+F(0)
     last = current;                        //  for F(2), last = F(0) and current = F(1)
                                            //  after calculating F(2), we will store the value of 'current' in 'last' and value of 'next' in 'current'
     current = next;                        //  for F(3), last will be F(1) and current will be F(2) */
  }
  return current;
}

int main ()
{
  cout<<"Enter a number"<<endl;
  int n;  cin>>n;
  int ans = fib(n);
  cout<<ans;

  return 0;
}

// tiling problem

/* Given a “2 x n” board and tiles of size “2 x 1”, count the number of ways to tile the given board using the 2 x 1 tiles.
 A tile can either be placed horizontally i.e., as a 1 x 2 tile or vertically i.e., as 2 x 1 tile. */

/* Let “count(n)” be the count of ways to place tiles on a “2 x n” grid, we have following two ways to place first tile.
1) If we place first tile vertically, the problem reduces to “count(n-1)”
2) If we place first tile horizontally, we have to place second tile also horizontally. So the problem reduces to “count(n-2)”

Therefore, count(n) can be written as below.
   count(n) = n if n = 1 or n = 2
   count(n) = count(n-1) + count(n-2)
    it is fibonacci series
   */

   #include<iostream>
using namespace std;

int fib(int n)
{

  int f[n+1];            /* Declare an array to store Fibonacci numbers. */
  int i;


                        /*  1st and 2nd number of the series are 1 and 2 respectively */
  f[1] = 1;
  f[2] = 2;

  for (i = 3; i <= n; i++)
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

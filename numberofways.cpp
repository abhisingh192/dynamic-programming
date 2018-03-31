// A C program to count number of possible ways to a given score can be reached in a game where a move can earn 3 or 5 or 10.
// Here (3,5,5) or (5,5,3) is counted as one
// for example if n = 20, the ways are (10,10), (10,5,5), (5,5,5,5), (3,3,3,3,3,5)
#include <iostream>
#include<string.h>             // for the memset function
using namespace std;


// Returns number of ways to reach score n
int count(int n)
{
    // table[i] will store count of solutions for
    // value i.
    int table[n+1], i;

    // Initialize all table values as 0
    memset(table, 0, sizeof(table));

    // Base case (If given value is 0)
    table[0] = 1;

    // One by one consider given 3 moves and update the table[]
    // values after the index greater than or equal to the
    // value of the picked move
    for (i=3; i<=n; i++)
       table[i] += table[i-3];
    for (i=5; i<=n; i++)
       table[i] += table[i-5];
    for (i=10; i<=n; i++)
       table[i] += table[i-10];

    return table[n];
}



int main()
{
    int n;
    cout<<"enter a number"<<endl;
    cin>>n;
    cout<<"the number of ways are"<<" "<<count(n);


    return 0;
}

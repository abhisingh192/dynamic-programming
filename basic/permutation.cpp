//Permutation Coefficient

// A O(n) solution that uses table  fact[] to
// calculate the Permutation Coefficient

#include<iostream>
using namespace std;



int permutationCoeff(int n, int k)                    // Returns value of Permutation Coefficient P(n, k)
{
    int fact[n+1];

    // base case
    fact[0] = 1;

    // Caculate value factorials up to n
    for (int i=1; i<=n; i++)
        fact[i] = i*fact[i-1];

    // P(n,k)= n!/(n-k)!
    return fact[n]/fact[n-k];
}


int main()
{
    int n,k;
    cout<<"enter the value of n"<<endl;
    cin>>n;
    cout<<"enter the value of k"<<endl;
    cin>>k;
    cout<<"value of permutation is "<<permutationCoeff(n,k)<<endl;
    return 0;
}

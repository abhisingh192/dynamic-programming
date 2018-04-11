// max sum of a subsequence such that no two elements are adjacent
// return 0 as output if max sum is negative

#include<iostream>
using namespace std;
int main()
{
    cout<<"enter the elements"<<endl;
    int n;  cin>>n;
    int arr[n];
    int i;
    int sumeven,sumodd;
    sumeven=sumodd=0;
    for(i=0;i<n;i++)
        cin>>arr[i];
    int flag1,flag2;
    flag1=flag2=0;

    for(i=0;i<n;i+=2){
        if(arr[i]>0){
            sumeven+=arr[i];
            flag1 =1;
        }

    }
    for(i=1;i<n;i+=2){
        if(arr[i]>0){
            sumodd+=arr[i];
            flag2 =1;
        }

    }

    if(!flag1 && !flag2)
        cout<<0;
    else{
        if(sumeven>sumodd)
            cout<<sumeven;
        else
            cout<<sumodd;
    }

    }

#include<iostream>
#include<algorithm>
using namespace std;

int main() {
int n;
cout<<"enter the number of elements"<<endl;
cin>>n;

int arr[n];
int i;

for(i=0;i<n;i++)
cin>>arr[i];

int arr1[n];

for(i=0;i<n;i++)
arr1[i]=1;

int j;

for(i=1;i<n;i++){
        cout<<i<<"iteration"<<endl;
  for(j=i-1;j>=0;j--){
    if(arr[i]-arr[j]==1 || arr[i]-arr[j]==-1){
        arr1[i]=arr1[i]+arr1[j];
        break;
    }

     //  for(i=0;i<n;i++)
     //  cout<<arr1[i]<<" ";
     //  cout<<endl;
  }
}

for(i=0;i<n;i++)
cout<<arr1[i]<<" ";
cout<<endl;
sort(arr1,arr1+n);
cout<<arr1[n-1];
}

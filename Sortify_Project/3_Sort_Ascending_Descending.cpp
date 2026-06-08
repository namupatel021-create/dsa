#include <iostream>
using namespace std;
int main(){
    int n; cin>>n; int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    for(int i=0;i<n-1;i++)
        for(int j=0;j<n-i-1;j++)
            if(arr[j]>arr[j+1]) swap(arr[j],arr[j+1]);
    cout<<"Ascending: ";
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
    cout<<"\nDescending: ";
    for(int i=n-1;i>=0;i--) cout<<arr[i]<<" ";
    return 0;
}
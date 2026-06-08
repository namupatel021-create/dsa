#include <iostream>
using namespace std;
int main(){
    int n; cin>>n; int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    for(int i=0;i<n;i++){
        bool dup=false;
        for(int j=0;j<i;j++) if(arr[i]==arr[j]) dup=true;
        if(!dup) cout<<arr[i]<<" ";
    }
    return 0;
}
#include <iostream>
using namespace std;
int main(){
    int n,pos=0,neg=0; cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    for(int i=0;i<n;i++){
        if(arr[i]>0) pos++;
        else if(arr[i]<0) neg++;
    }
    cout<<"Positive Numbers = "<<pos<<"\n";
    cout<<"Negative Numbers = "<<neg;
    return 0;
}
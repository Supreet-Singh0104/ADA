#include<iostream>

using namespace std;

int main() {
    // code here
    cout<<"Enter the size of the array";
    int n; cin>>n;
    int arr[n];
    cout<<"Enter the elements of the array";
    for(int i=0;i<n;i++) cin>>arr[i];

     cout<<"Enter the Key to be Found";
    int key; cin>>key;
    int low=0;
    int high =n-1;
    int flag=0;
    while(low<=high){
        int mid=low + (high-low)/2;

        if(arr[mid]==key){
            cout<<"The element is at position "<< mid+1<<endl;
            flag=1;
            break;
        }else if(arr[mid]>key){
            high=mid-1;
        }else{
            low=mid+1;
        }
    }
    if(flag==0) cout<<"Element Not Found"<<endl;

    return 0;
}
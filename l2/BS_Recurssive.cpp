#include<iostream>

using namespace std;

int search (int arr[],int k,int n){
    int low=0;
    int high=n-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(arr[mid]==k) return mid;
        else if(arr[mid]>k) high=mid-1;
        else low=mid+1;
    }
    return -1;
}

int main() {
    // code here
    cout<<"Enter the size of the array";
    int n; cin>>n;
    int arr[n];
    cout<<"Enter the elements of the array";
    for(int i=0;i<n;i++) cin>>arr[i];

     cout<<"Enter the Key to be Found";
    int k; cin>>k;
    int pos=search(arr,k,n);
    if(pos==-1){
        cout<<"element not found";
    }else{
        cout<<"element is found at position "<<pos+1;
    }
    return 0;
}
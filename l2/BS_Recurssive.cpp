#include<iostream>

using namespace std;

int search (int arr[],int k, int low,int high){
    if(low==high){
        if(arr[low]==arr[high]) return low;
        else return -1;
    }

    int mid=low+(high-low)/2;
    if(arr[mid]==k) return mid;
    else if(arr[mid]>k) return search(arr,k,low,mid-1);
    else return search(arr,k,mid+1,high);
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
    int pos=search(arr,k,0,n-1);
    if(pos==-1){
        cout<<"element not found";
    }else{
        cout<<"element is found at position "<<pos+1;
    }
    return 0;
}
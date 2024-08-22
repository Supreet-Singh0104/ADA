#include<iostream>

using namespace std;

int partition(int arr[],int si,int ei){
    int i=si-1,pivot=arr[ei];
    for(int j=si;j<ei;j++){
        if(arr[j]<=pivot)
        {
            i++;
            swap(arr[i],arr[j]);
        }
    }
    i++;
    swap(arr[i],arr[ei]);
    return i;
}

void QiuckSort(int arr[],int si,int ei){
    if(si>=ei) return ;

    int partition_idx=partition(arr,si,ei);
    QiuckSort(arr,si,partition_idx-1);
    QiuckSort(arr,partition_idx+1,ei);
    
}

void Print(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main() {
    // code here
    cout<<"Enter the no of elements in the array"<<endl;
    int n; cin>>n;
    
    int arr[n];
    cout<<"Enter the elements"<<endl;
    for(int i=0;i<n;i++) cin>>arr[i];
    QiuckSort(arr,0,n-1);
    Print(arr,n);
    return 0;
}
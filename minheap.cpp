#include<bits/stdc++.h>
using namespace std;

void heapify(int arr[],int n,int i){
    int smallest=i;
    int left=2*i+1;
    int right=2*i+2;
    if(left<n && arr[left] < arr[smallest]){
        smallest=left;
    }
    if(right<n && arr[right] < arr[smallest]){
        smallest=right;
    }
    if(smallest!=i){
        swap(arr[i],arr[smallest]);
        heapify(arr,n,smallest);
    }
}

void heap(int arr[],int n)
{
    for(int i=n/2-1;i>=0;i--){ //Build max heap
        heapify(arr,n,i);
    }
    //heap sorting
    for(int i=n-1;i>=0;i--){
        swap(arr[i],arr[0]);
        heapify(arr,i,0);
    }


}


int main(){
    int n;
    cin>>n;
    int arr[n];
    srand(time(0));
    for(int i=0;i<n;i++){
        arr[i]=rand()%100;
    }
    cout<<"Before the heap sort"<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    heap(arr,n);

    cout<<endl<<"After the heap sort"<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
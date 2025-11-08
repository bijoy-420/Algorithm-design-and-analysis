#include<bits/stdc++.h>
#include<time.h>
using namespace std;
void heapify(int arr[],int n,int i){
    int largest=i;
    int left=2*i+1;
    int right=2*i+2;

    if(left<n && arr[left]>arr[largest])
        largest=left;

    if(right<n && arr[right]>arr[largest])
        largest=right;

    if(largest!=i){
        swap(arr[i],arr[largest]);
        heapify(arr,n,largest);
    }
}

void heapsort(int arr[], int n){
    for(int i=(n/2)-1;i>=0;i--){    //Build max heap
        heapify(arr,n,i);
    }
    for(int i=n-1;i>=0;i--){        //max heap sorting 
        swap(arr[0],arr[i]);
        heapify(arr,i,0);
    }
}
int main(){
    int n;
    cout<<"Enter your heap element "<<endl;
    cin>>n;
    int myarr[n];

    //take the data randomly
    srand(time(0));
    for(int i=0;i<n;i++){
        myarr[i]=rand()%1000;
    }

    //Increasing Order ,greater<>()
    sort(myarr,myarr+n ,greater<>() ); 
    cout<<"Before heap sort"<<endl;
    for(int i=0;i<n;i++){
        cout<<myarr[i]<<" ";
    }
   clock_t begin=clock();
    heapsort(myarr,n);
    clock_t end=clock();
    double execution_time=(double(end-begin)/CLOCKS_PER_SEC)*1000;
    cout<<endl<<"After the heap sort"<<endl;
    for(int i=0;i<n;i++){
        cout<<myarr[i]<<" ";
    }
    cout<<endl<<"the time required:"<<execution_time<<endl;
    
    
   
   


}

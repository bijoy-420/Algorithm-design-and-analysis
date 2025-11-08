#include<bits/stdc++.h>
#include<time.h>
using namespace std;

//merge array
void merge(int arrr[],int l,int m,int r){
    int i=l;
    int j=m+1;
    int k=l,n;
    int temp[n];
    
  
    while(i<=m && j<=r){
        if(arrr[i]<=arrr[j]){     //compare two array and insert to new array
            temp[k]=arrr[i];
            i++;
            k++;
        }
            
        else{
        temp[k]=arrr[j];
            j++;
            k++;
        }
    }
    while(i<=m){
        temp[k]=arrr[i];  //copying all elements from left sub array
        i++;
        k++;
    }
    while(j<=r){        //copying all elements from right sub array
        temp[k]=arrr[j];
        j++;
        k++;
    }
    for(int s=l;s<=r;s++){
        arrr[s]=temp[s];
    }
    
}

//merge Sorting
void mergesort(int arrr[],int l,int r){
    if(l<r){
        
        int m=(l+r)/2;//Middle of the  array
        mergesort(arrr,l,m);//left array 
        mergesort(arrr,m+1,r);//Right Array
        merge( arrr, l, m, r);
    }
}


int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int l=arr[0];
    int r=arr[n-1];
    // srand(time(0));
    // for(int i=0;i<n;i++){
    //     arr[i]=(rand()%10)+1;
    // }
    //Before merge sort
    cout<<"Before the merge sort"<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    //mergeSorting 
    mergesort(arr,l,r);
    cout<<endl;
    //After the merge sort
    cout<<"After the merge sort"<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
   
}
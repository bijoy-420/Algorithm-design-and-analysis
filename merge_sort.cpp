#include<bits/stdc++.h>
using namespace std;

int n;
void merge(int arr[],int l,int m,int r){
    int i=l,j=m+1,k=l;
    int temp[n];
    while(i<=m && j<=r){
        if(arr[i]<=arr[j]){
           temp[k]=arr[i];
            i++;
            k++;
        }
            
        else{
            temp[k]=arr[j];
            j++;
            k++;

        }
    }
    while(i<=m){
       temp[k]=arr[i];
        i++;
        k++;
    }
    while(j<=r){
     temp[k]=arr[j];
        j++;
        k++;
    }
    for(int s=l;s<=r;s++){
        arr[s]=temp[s];
    }
}

void mergesort(int arr[],int l,int r){
    if(l<r){
        int m=(l+r)/2;
        mergesort(arr,l,m);
        mergesort(arr,m+1,r);
        merge(arr,l,m,r);
    }
}
int main(){
    cout<<"Enter your number:" ;
 
    cin>>n;
    int myarr[n];
    srand(time(0));

    for(int i=0;i<n;i++){       //random input number
        myarr[i]=rand()%1000;
    }
    
    cout<<"Before the merge sort"<<endl;
    for(int i=0;i<n;i++)        //insert random number in array
    {
        cout<<myarr[i]<<" ";
    }

    clock_t begin=clock();
    mergesort(myarr,0,n-1);         //call mergesort function
    clock_t end=clock();
    double execution_time=(double(end-begin)/CLOCKS_PER_SEC)*1000;
    

    cout<<endl<<"After the merge sort"<<endl;
    for(int i=0;i<n;i++){       //Output of the merge sort
        cout<<myarr[i]<<" ";
    }
   
    cout<<endl<<"The time Requird merge Sort:"<<execution_time<<endl;



}
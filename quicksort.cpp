#include<bits/stdc++.h>
using namespace std;
int n;
void swap(int arr[],int i,int j){
    int temp=arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
}
int partition(int arr[],int l,int r)
{
    //int randompivot=l+rand()%(r-l+1);
    //swap(arr[r],arr[randompivot]);
    int pivot=arr[r];
    int i=l-1;
    for(int j=l;j<r;j++)
    {
        if(arr[j]<pivot)
        {
            i++;
            swap(arr,i,j);
        }
       
    }
    swap(arr,i+1,r);
    return i+1;
}
//randomized quick sort
int randpartition(int arr[],int l,int r)
{
    int randompivot=l+rand()%(r-l+1);
    swap(arr[r],arr[randompivot]);

    int pivot=arr[r];
    int i=l-1;
    for(int j=l;j<r;j++)
    {
        if(arr[j]<pivot)
        {
            i++;
            swap(arr,i,j);
        }
    }
    swap(arr,i+1,r);
    return i+1;
}
void quicksort(int arr[],int l,int r){
    if(l<r){
        int pi=partition(arr,l,r);
        
        quicksort(arr,l,pi-1);
        quicksort(arr,pi+1,r);


    }
}
void randquicksort(int arr[],int l,int r){
    if(l<r){
    
        int pi=randpartition(arr,l,r);
        quicksort(arr,l,pi-1);
        quicksort(arr,pi+1,r);


    }
}
int main()
{
    cout<<"uniform order input"<<endl;
   cout<<"Enter the No Of element:";
    cin>>n;
    int arr[n];
    //increasing order input
    // for(int i=0;i<n;i++)
    // {
    //     cin>>arr[i];
    // }

    //Decreasing order input
    //  for(int i=n-1;i<=0;i--)
    // {
    //     cin>>arr[i];
    // }

    //input for uniform number
    for(int i=0;i<n;i++)
    {
        arr[i]=5;
    }


   //Randomized input
    // srand(time(0));
    // for(int i=0;i<n;i++)
    // {
    //     arr[i]=rand()%10;
    // }
   
    //  cout<<"Before Quick sort"<<endl;
    //  for(int i=0;i<n;i++){
    //     cout<<arr[i]<<" ";
    //  }
    double begin=clock();
    quicksort(arr,0,n-1);
    double end=clock();
    double execution_time=(double(end-begin)/CLOCKS_PER_SEC)*1000;

    double start=clock();
    randquicksort(arr,0,n-1);
    double ends=clock();
    double execution_time1=(double(ends-start)/CLOCKS_PER_SEC)*1000;

    // cout<<endl<<"After the quick sort"<<endl;
    // for(int i=0;i<n;i++)
    // {
    //     cout<<arr[i]<<" ";
    // }
    cout<<endl<<"the time required Quick Sort:"<<execution_time<<endl;
    cout<<endl<<"the time required Quick Sort:"<<execution_time1<<endl;
}
#include<bits/stdc++.h>
using namespace std;
int n;

void swap(int arr[],int i,int j)
{
    int temp=arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
}

int partition(int arr[],int l,int r)
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


void R_quicksort(int arr[],int l,int r)
{
    if (l<r)
    {
        int pi=partition(arr,l,r);
        R_quicksort(arr,l,pi-1);
        R_quicksort(arr,pi+1,r);
    }
}

int main()
{
    cout<<"Enter the Size of Array:";
    cin>>n;
    int arr[n];

    srand(time(0));
    for(int i=0;i<n;i++)
    {
        arr[i]=rand()%10;
    }
    cout<<"Before the quick sort"<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    double start=clock();
    R_quicksort(arr,0,n-1);
    double end=clock();
    double execution_time=(double(end-start)/CLOCKS_PER_SEC)*1000;

    cout<<endl<<"After the quick sort"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }

    cout<<endl<<"Execution time is:"<<execution_time<<endl;
}
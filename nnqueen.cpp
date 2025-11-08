#include<bits/stdc++.h>
using namespace std;
int n;
int cnt=0;
bool safe(int arr[],int k,int i)
{
    for(int j=1;j<k;j++){
        if(arr[j]==i || abs(arr[j]-i)==abs(j-k))
            return false;
    }
    return true;
}
void nqueen(int arr[],int k,int n)
{
    for(int i=1;i<=n;i++)
    {
        if(safe(arr,k,i))
        {   
            arr[k]=i;
            if(k==n)
            {   
                cnt++;
                for(int j=1;j<=n;j++){
                    cout<<arr[j]<<" ";
                }
                cout<<endl;
            }
            else {
            nqueen(arr,k+1,n);
            }
        }
        
    }
}
int main()
{
    int n;
    cout<<"Enter the no of Queen:";
    cin>>n;
    int arr[n];
    double start=clock();
    nqueen(arr,1,n);
    double end=clock();
    double execution_time=(double(end-start)/CLOCKS_PER_SEC)*1000;
    cout<<endl<<"Execution time is:"<<execution_time<<endl;
    cout<<"Number of Solution="<<cnt<<endl;

}
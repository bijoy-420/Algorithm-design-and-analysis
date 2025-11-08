#include<bits/stdc++.h>
using namespace std;
int main()
{   int n=5;
    int arr[n][n]={
        {0,3,8,10000,-4},
        {10000,0,10000,1,7},
        {10000,4,0,10000,10000},
        {2,10000,-5,0,10000},
        {10000,10000,10000,6,0}
    };
    cout<<"Shortest path= "<<endl;
    for(int k=0; k<n; k++)
    {
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                arr[i][j]=min(arr[i][j],(arr[i][k]+arr[k][j]));

            }
        }
    }
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;}
}

#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>result;
int n;
int cnt=0;
void sumofsubsets(int sets[],int target,int curr_sum,int sum,vector<int>&curr_set,int start,int n)
{
    if(target==curr_sum)
    
    {
        cnt++;
        result.push_back(curr_set);
    }
    if(sum<target)
        return;
    for(int i=start;i<n;i++)
    {
        curr_set.push_back(sets[i]);
        sum-=sets[i];
        sumofsubsets(sets,target,curr_sum+sets[i],sum,curr_set,i+1,n);
        curr_set.pop_back();
    }
}
int main()
{
    //vector<int>sets={5,7,10,12,15,18,20};
    cout<<"Enter the size of array:";
    cin>>n;
    int sets[n];
    srand(time(0));
    for(int i=0;i<n;i++)
    {
        sets[i]=rand()%100;
    }
    cout<<endl<<"random number"<<endl;
    for(int i=0;i<n;i++){
        cout<<sets[i]<<" ";
    }
    int s=0;
    for(int j=0;j<(int) (n/1.5);j++)
    {
        s+=sets[j];
    }
    int target=s;
    cout<<endl<<"target value:"<<target<<endl;
    vector<int>curr_set;
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=sets[i];
    }
    double begin=clock();
    sumofsubsets(sets,target,0,sum,curr_set,0,n);
    double end=clock();
    double execution_time=(double(end-begin)/CLOCKS_PER_SEC)*1000;

    cout<<endl<<"sumofsubset"<<endl;
    for(auto sets:result)
       {
           for(int elemnet:sets)
                cout<<elemnet<<' ';
            cout<<endl;
       }
       cout<<endl<<"execution time:"<<execution_time<<endl;
       cout<<"the number of subsets="<<cnt<<endl;

}
#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>result;

void sumofsubsets(vector<int>& sets,int target,int curr_sum,int sum,vector<int>& curr_set,int s)
{
    if(target==curr_sum)
    {
        result.push_back(curr_set);
    }
    if(sum<target)
    {
        return;
    }
    for(int i=s;i<sets.size();i++)
    { 
        curr_set.push_back(sets[i]);
        sum-=sets[i];
        sumofsubsets(sets,target,curr_sum+sets[i],sum,curr_set,i+1);
        curr_set.pop_back();
    }
}
int main()
{
    vector<int>sets={5,7,10,12,15,18,20};
    int sum=0;
    vector<int>curr_set;
    int target=35;
    for(int i=0;i<sets.size();i++)
    {
        sum+=sets[i];
    }

    sumofsubsets( sets, target,0,sum,curr_set,0);
    for(auto sets:result){
        for(int element:sets)
        {
            cout<<element<<" ";
        }
        cout<<endl;

    }
}
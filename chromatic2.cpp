#include<bits/stdc++.h>
using namespace std;
int m,n;
vector<vector<int>>graph;
vector<int>x;
void next_value(int k){
    do{
        x[k]=(x[k]+1)%(m+1);
        if(x[k]==0){
            return;
        }
        for(int j=0;j<n;j++){
            if(graph[k][j]!=0 && x[k]==x[j]){
                break;
            }
            if(j==n+1){
                return;
            }
        }
    }while(true);
}
bool mColoring(int k)
{
    do{
        next_value(k);
        if(x[k]==0)
        {
            return false;
        }
        if(k==n){
            return true;
        }
        else{
            if(mColoring(k+1)){
                return true;
            }
        }
    }while(true);
}


int main()
{
    
    n=7;
    graph.resize(n+1,vector<int>(n+1,0));
    x.resize(n+1,0);
     graph = {
        {0, 1, 0, 0, 1,1,1},
        {1, 0, 1, 1, 0,0,0},
        {0, 1, 0, 1, 0,0,1},
        {0, 1, 1, 0, 1,0,0},
        {1,0, 0, 1, 0,1,1},
        {1,0,0,0,1,0,1},
        {1,0,1,01,1,0}
    };
    m=1;
    while(true){
        x.resize(n+1,0);
        if(mColoring(1)){
            cout<<"Minimum Required color:"<<m<<endl;
            break;

        }
        m++;
    }



}
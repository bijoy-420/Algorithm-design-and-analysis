#include<bits/stdc++.h>
using namespace std;

void DFS_VISIT(int u, unordered_map<int,list<int>> &G,int v, vector<string>&colour,vector<int> &d,vector<int> &f,vector<int> &pi, int &time, list<int>&li)
{
    cout<<u<<endl;
    colour[u]="gray";
    time++;
    d[u]=time;
    for(auto adj : G[u])
    {
        if (colour[adj] == "white")
        {
            pi[adj]=u;
            DFS_VISIT(adj,G,v,colour,d,f,pi,time,li);
        }
    }
    colour[u]="black";
    li.push_front(u);
    time++;
    f[u]=time;
}


list<int> DFS(unordered_map<int,list<int>> &G, int v)
{
    vector<string>colour(v,"white");
    vector<int> d(v,INT_MAX);
    vector<int> f(v,INT_MAX);
    vector<int> pi(v,-1);
    int time=0;
    list<int>li;
    for( int i=0 ; i<v ; i++)
    {
        if(colour[i] == "white")
        {
            DFS_VISIT(i,G,v,colour,d,f,pi,time,li);
        }
    }
    return li;
}

 
int main() 
{
    int v=8;
    unordered_map<int,list<int>> G;
    G[0].push_back(1);
    G[0].push_back(2);
    G[0].push_back(3);
    G[0].push_back(4);
    G[1].push_back(5);
    G[2].push_back(5);
    G[3].push_back(6);
    G[4].push_back(6);
    G[5].push_back(7);
    G[6].push_back(7);
    
    list<int>li;
    li=DFS(G,v);

    for(auto i: li)
    {
        cout<<i<<" ";
    }cout<<endl;

   

    return 0;
}
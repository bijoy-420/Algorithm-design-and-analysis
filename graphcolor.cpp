#include<bits/stdc++.h>
using namespace std;
int m,n;
vector<vector<int>>G;
vector<int>x;

void nextValue(int k){
    do{
        x[k]=(x[k]+1) %(m+1);
        if(x[k] == 0) return ;
        int j;
        for(j=1 ; j<=n ; j++)
        {
            if(G[k][j] != 0  and x[j] == x[k]) break;
        }
        if(j == n+1)
        {
            return;
        }

    }while(true);
}

void mColoring(int k)
{
    do{
        nextValue(k);
        if(x[k] == 0) return;
        if(k == n)
        {
            for(int i=1 ;i<=n ; i++)
            {
                cout<<x[i]<<" ";
            }cout<<endl;
        }
        else{
            mColoring(k+1);
        }

    }while(true);
}

int main() {
    n=4;
    m=2;
    G.resize(n+1,vector<int>(n+1));
    x.resize(n+1);
    G={{0,1,0,1},
       {1,0,1,0},
       {0,1,0,1},
       {1,0,1,0}
      };
    mColoring(1);

    return 0;
}
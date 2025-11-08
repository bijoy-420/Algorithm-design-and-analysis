#include<bits/stdc++.h>
using namespace std;
# define n 15
class sttack
{
    int *arr;
    int top;
    public:
    sttack(){
        arr=new int[n];
        top=-1;
    }
    void push(int x)
    {
        if(top==n-1)
        {
            cout<<"the  stack is overflow";
            return;
        }
        top++;
        arr[top]=x;
    }
    void pop()
    {
        if(top==-1)
        {
            cout<<"stack is underflow";
            return;
        }
        top--;
    }

    int tops()
        {
            if(top==-1)
            {
                cout<<"stack is overflow";
                return -1;
            }
            return arr[top];    
        }
    

    void display()
    {
        for(int i=0;i<=top;i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }

    void display1()

    {
        for(int i=top;i>=0;i--)

        {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }


};
int main()
{
    sttack t;
    t.push(1);
    t.push(2);
    t.push(3);
    t.push(4);
    t.push(5);
    t.display();
    t.display1();
    t.pop();
    t.pop();
    t.display();
    cout<<t.tops();
   
}
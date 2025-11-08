#include<bits/stdc++.h>
using namespace std;
#define n 10

class staaack
{
    private:
        int*arr;
        int top;

    public:
        staaack()
        {
            arr=new int  [n];
            top=-1;
        }

    void push(int x)
    {
        if(top==n-1)
        {
            cout<<"stack is overflow"<<endl;
            return;
        }
        top++;
        arr[top]=x;
    }  
    void pop()
    {
        if(top==-1)
        {
            cout<<"stack is underflow"<<endl;
            return;
        }
        top--;
    }
    void display()
    {
        for(int i=0;i<=arr[top]+1;i++)
        {
            cout<<arr[i]<< " ";
        }
        cout<<endl;
    }
    int Top()
    {
        if(top==-1)
        {
            cout<<"stack is underflow"<<endl;
            return -1;
        }
        return arr[top];
    }


};
int main()
{
    staaack s;
    /*s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.display();
    s.pop();
    s.pop();*/
    s.display();
    cout<<s.Top();

}
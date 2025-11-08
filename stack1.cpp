#include<bits/stdc++.h>
using namespace std;
#define n 10  
class stack1
{
    int *arr;
    int top;
    public:
        stack1()
        {
            arr=new int[n];
            top=-1;
        }
    //insert iteam
    void push(int val)
    {
        if(top==n-1)
        {
            cout<<"stack is overflow";
            return;
        }
        top++;
        arr[top]=val;
    }
    //delete item
    void pop()
    {
        if(top==-1)
        {
            cout<<"stack is empty"<<endl;
        }
        top--;
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
    stack1 s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.display();
    s.pop();
    s.display();
    s.display1();

}
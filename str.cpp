#include<bits/stdc++.h>
using namespace std;
#define n 10
class stack
{
    int *arr;
    int top;
    public:
    stack(){
        arr=new int[n];
        top=-1;
    }
    void push(string x)
    {
        for(int i=1;i<=7;i++)
        {
            push(arr[i]);
        }
    }
    void display()
    {
        for(int i=0;i<=top;i++)
        {
            cout<<arr[i]<< " ";
        }
        cout<<endl;
    }

};
int main()
{
    stack s;
    s.push(sabbir);
    s.display();
}
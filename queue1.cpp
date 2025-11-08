#include<bits/stdc++.h>
using namespace std;
#define n 20

class Queue
{
    int *arr;
    int front;
    int rear;
    public:
    Queue()
    {
        arr=new int[n];
        front=-1;
        rear=-1;
    }
    void enqueue(int x)
    {
        if(rear==n-1){
            cout<<"the queue is full\n";
            return;
        }
        rear++;
        arr[rear]=x;
        if(front ==-1)
        {
            front++;
        }
    }

    void Dequeue ()
    {
        if(rear==-1 || front>rear)
        {
            cout<<"the queue is empty\n";
            return;
        }
        front++;
    }

    void display()
    {
        for(int i=front;i<=rear;i++)

        {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};

int main()

{
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.display();
    q.Dequeue();
    q.display();
    q.Dequeue();
    q.display();

}
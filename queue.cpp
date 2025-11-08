#include<bits/stdc++.h>
using namespace std;
#define n 20
class Queue
{
    private:
        int*arr;
        int front;
        int rear;
    public:
        Queue()
        {
            arr=new int[n];
            front=-1;
            rear=-1;

        }

        void enqueue(int val)
        {
            if(rear==n-1)
            {
                cout<<"Queue is overflow"<<endl;
                return;
            }
            rear++;
            arr[rear]=val;
            if(front==-1)
            {
                front++;
            }
        }

        void Dequeue()
        {
            if(front==-1 || front>rear)
            {
                cout<<"No Element in Queue"<<endl;
                return;
            }
           
            front++;
        }
         int sum()
        {
            int summ=0;
            for(int i=front;i<=rear;i++)
            {
                summ=summ+arr[i];
            }
            return summ;
        }

        int peek()
        {
            if(front==-1 || front>rear)

            {
                cout<<"No Element in Queue"<<endl;
                return -1;
            }
            return arr[front];

        }
        //summation of Queue Element 
       

        void display()
        {
            int sum=0;

            for(int i=front;i<=rear+1;i++)
            {
                
                cout<<arr[i]<<" ";
                sum+=i;
            }
            cout<<endl;
            cout<<"sum="<<sum<<endl;
        }
        void display1()
        {
            for(int i=rear;i>=front;i--)
            {
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }

};

int main()
{
    Queue m;
    m.enqueue(1);
    m.enqueue(2);
    m.enqueue(3);
    m.enqueue(4);
    m.enqueue(5);
    m.display();
    m.display1();
    m.sum();
    cout<<m.peek()<<endl;
    m.Dequeue();
    m.Dequeue();
    m.Dequeue();
    m.display();

     

     

    
   
    
}

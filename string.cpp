#include<bits/stdc++.h>
using namespace std;
#define n 10


class Queue
{
    char *stack;
    char *reverse;
   
    int front;
    int rear;
    public:
        Queue()
        {
            stack=new char[n];
            reverse=new char[n];

           
            front=-1;
            rear=-1;
        }
        void enque(char s)
        {
            if(rear==n-1)
            {
                cout<<"the queue is overflow";
                return;
            }
            
            rear++;
            stack[rear]=s;
            
            
            if(front==-1)
            {
                front++;
            }
        }
        void display()
        {
            for(int i=front;i<=rear;i++)
            {
                cout<<stack[i]<<"";
            }
            cout<<endl;
        }
};
int main()
{
   char str[n];
   cout<<"array:";
   gets(str);
   for(int i=0;i<=strlen(str);i++)
   {
    enque(str[i]);
   }

}
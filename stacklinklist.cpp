#include<bits/stdc++.h>
using namespace std;
class node
{
    public:
        int data;
        node*next;
        node(int val)
        {
            data=val;
            next=NULL;
        }
};
class stack11
{
    private:
        node*head;
    public:
        stack11()
        {
            head=NULL;
        }
        void push(int val)
        {
            node* newnode=new node(val);
            if(head==NULL)
            {
                head=newnode;
                return;
            }
            node*top=head;
            while(top->next!=NULL)
            {
                top=top->next;
            }
            top->next=newnode;
        }

        void pop()
        {
            node*top=head;
            node*prev=head;
            while(top->next!=NULL)
            {
                prev=top;
                top=top->next;

            }
            prev->next=NULL;
            delete top;
        }


        void display()
        {
            node*temp=head;
            while(temp!=NULL)
            {
                cout<<temp->data<<"-> ";
                temp=temp->next;
            }
            cout<<"NULL"<<endl;
        }
};

int main()
{
    stack11 s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.display();
    s.pop();
    s.display();
}
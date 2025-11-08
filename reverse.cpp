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

class linklist
{
    private:
        node*head;
    public:
        linklist()
        {
            head=NULL;
        }
    void insertatlast(int val)
    {
        node*newnode=new node(val);
        node*temp=head;
        while (temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newnode;
        
    }

    void reverse()
    {
        node* pre=NULL;
        node* curr=head;
        node* next;
        while(curr!=NULL)
        {
            next=curr->next;
            curr->next=pre;
            pre=curr;
            curr=next;
        }
        head=pre;
    }


     void add()
    {
        int sum=0;
        node* temp=head;
        while(temp!=NULL)
        {
            sum=sum+temp->data;
            temp=temp->next;
        }
        cout<<"sum="<<sum<<endl;
    }
    void display()
    {
        node*temp=head;
        while(temp!=NULL)
        {
            cout<<temp->data<<"->";
            temp=temp->next;
        }
        cout<<"NULL"<<endl;

    }
};

int main()
{
    linklist list;
    list.insertatlast(10);
    list.insertatlast(20);
    list.insertatlast(30);
    list.insertatlast(40);
    list.display();
}
    
        
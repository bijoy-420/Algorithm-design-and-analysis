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
class linkedlist
{
    private:
        node*head;
    public:    
        linkedlist()
        {
            head=NULL;
        }


        //insert at first
        void insertatfirst(int val)
        {
            node*newnode=new node(val);
            newnode->next=head;
            head=newnode;

        }

        //insert at last
        void insertatlast(int val)
        {
            node*temp=head;
            node*newnode =new node(val);
            while(temp->next!=NULL)
            {
                temp=temp->next;
            }
            temp->next=newnode;
        }

        //insert at any position
        void insertatposition(int pos,int val)
        {
            node*temp=head;
            node* newnode=new node(val);
            for(int i=0;i<pos;i++)
            {
                temp=temp->next;
            }
            newnode->next=temp->next;
            temp->next=newnode;
        }

        //reverse a link list
        void reverse(){ 
        node*pre=NULL;
        node*curr=head;
        node*next;
        while(curr!=NULL){

        
        next=curr->next;
        curr->next=pre;
        pre=curr;
        curr=next;
        }
        head=pre;

        }

        //Delete at last node
        void deleteatlast()
        {
            node*curr=head;
            node*pre=head;
            while(curr->next!=NULL)
            {
                pre=curr;
                curr=curr->next;
            }
            pre->next=NULL;
            delete curr;
        }

        //Delete at first
        void deteleatfirst()
        {
            node*temp=head;
            head=temp->next;
            delete temp;
        }


        //delete at any position
        void deleteposition(int pos)
        {
            node*curr=head;
            node*pre=head;
            for(int i=1;i<pos;i++)
            {
                pre=curr;
                curr=curr->next;
            }
            pre->next=curr->next;
            delete curr;
            
        }

        //Display the list
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
    linkedlist list;
    list. insertatfirst(10);
    list.insertatfirst(20);
    list.insertatfirst(30);
    list.insertatfirst(40);
    list.insertatfirst(50);
    list.insertatfirst(60);
    list.display();
    cout<<endl;
    list.insertatlast(10);
    list.insertatlast(20);
    list.insertatlast(30);
    list.insertatlast(40);
    list.insertatlast(50);
    list.display();
    list.insertatposition(3,90);
    list.display();
    list.reverse();
    list.display();
    list.deleteatlast();
    list.display();
    list.deteleatfirst();
    list.display();
    list.deleteposition(2);
    list.display();
}
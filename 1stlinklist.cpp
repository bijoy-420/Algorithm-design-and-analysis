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
    /*insert at head*/
    void insertatfirst(int val)
    {
        node* newnode=new node(val);
        newnode->next=head;
        head=newnode;
    }
     /*insert at last*/

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

    /*insert at any position*/
    void insertatposition(int pos,int val)
    {
        if(pos==1)
        {
            insertatfirst(val);
            return;
        }
        node* newnode=new node(val);
        node*temp=head;
        for(int i=1;i<pos-1;i++)
        {
            temp=temp->next;
        }
        newnode->next=temp->next;
        temp->next=newnode;
    }

    /*delete at last element in list*/

    void deleteatlast()
    {
        node* curr=head;
        node* prev=head;
        while(curr->next!=NULL)
        {
            prev=curr;
            curr=curr->next;
        }
        prev->next=NULL;
        delete curr;
    }

    /*delete at first*/
    void deleteatfirst()
    {
        node* temp=head;
        head=temp->next;
        delete temp;
    }
    /*delete at any position*/
    void deleteatposition(int pos)
    {
        node* curr=head;
        node* prev=head;
        for(int i=1;i<pos;i++)
        {
            prev=curr;
            curr=curr->next;
        }
        prev->next=curr->next;
        delete curr;
    }
    void reverse()
    {
       node* pre=NULL;
       node* curr=head;
       node*next;
       while(curr!=NULL)
       {
        next=curr->next;
        curr->next=pre;
        pre=curr;

        curr=next;

       }
       head=pre;
    }

    /*adding all the element in a list*/
    int add()
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

     void display1()
    {
        node*temp=head;
        while(temp!=NULL)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;

    }
};


int main()
{
    linklist list;
    list.insertatfirst(40);
    list.insertatfirst(30);
    list.insertatfirst(20);
    list.insertatfirst(10);
    list.display();
    list.reverse();
    list.display();
    list.add();
    /*
    list.insertatlast(10);
    list.insertatlast(20);
    list.insertatlast(30);
    list.insertatlast(40);
    list.display();
    
    list.insertatposition(1,90);
    list.display();
    list.deleteatlast();
    list.display();
    list.deleteatlast();
    list.display();
    list.deleteatfirst();
    list.display();
    list.deleteatfirst();
    list.display();
    list.deleteatposition(2);
    list.display();
    

    list.reverse();
    list.display();
    
    list.reverse();
    list.display1();
    

    list.add();
    */
 
}
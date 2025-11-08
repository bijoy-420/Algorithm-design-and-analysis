#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int priority;
    string task;
    string hour;
    Node* next;
    Node (string task, int priority, string hour):task(task), priority(priority), hour(hour){}
};

class LinkedList
{
    private:
        Node*head;
    public:
        LinkedList()
        {
            head=NULL;
        }
/*insert element*/
    void insertathead(string task,int priority,string hour)
    {
        Node* newnode=new Node(task,priority,hour);
        newnode->next=head;
        head=newnode;
    }
    
/*traverse element*/
/*
    void traverseing()
    {
        Node* temp=head;
        while(temp!=NULL)
        {
            cout<<temp->task<<" "<<temp->priority<<" "<<temp->hour<<endl;
            temp=temp->next;
        }
    }*/
/*sorting element*/
    void sorting()
    {
        Node* start=head;
        Node* end=head;
        for(start=head;start->next!=NULL;start=start->next)
        {
            for(end=start->next;end!=NULL;end=end->next)
            {
                if(end->priority<start->priority)
                {
                    swap(start->task,end->task);
                    swap(start->priority,end->priority);
                    swap(start->hour,end->hour);

                }
            }
        }

    }
/*show the list*/
    void display()
    {
        Node* temp=head;
        while(temp!=NULL)
        {
            cout<<"Task: "<<temp->task<<" Priority: "<<temp->priority<<" Duration:"<<temp->hour<<endl;
            temp=temp->next;
        }
    }

};

/*main function*/
int main()
{
    LinkedList list;
    list.insertathead("task 1",4,"0.5");
    list.insertathead("task 2",3,"1.00");
    list.insertathead("task 3",1,"2.00");
    list.insertathead("task 4",5,"2.00");
    list.insertathead("task 5",2,"3.00");
    cout<<"brfore sorting\n";
    list.display();
    cout<<"after sorting\n";
    list.sorting();
    list.display();
}
    
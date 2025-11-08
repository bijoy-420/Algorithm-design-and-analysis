#include <bits/stdc++.h>
using namespace std;

class node {
    public:
        int data;
        node* next;
        node(int val) {
            data = val;
            next = NULL;
        }
};

class queue3 {
    private:
        node* head;
    public:
        queue3() {
            head = NULL;
        }   
        // Insert at the last
        void insertatlast(int val) {
            node* newnode = new node(val);
            if (head == NULL) {
                head = newnode;
                return;
            }
            node* rear = head;
            while (rear->next != NULL) {
                rear = rear->next;
            }
            rear->next = newnode;
        } 

        //dequeue operation
        void dequeue()
        {
            node* front=head;
            head=front->next;
            delete front;
        }
       
        // Display the list
        void display() {
            node* temp = head;
            while (temp != NULL) {
                cout << temp->data << "->";
                temp = temp->next;
            }
            cout << "NULL" << endl;
        }    
};

int main() {
    queue3 q;
    q.insertatlast(1);
    q.insertatlast(2);
    q.insertatlast(3);
    q.insertatlast(4);
    q.insertatlast(5);
    q.display();
    q.dequeue();
    q.display();
     q.dequeue();
    q.display();
    
    return 0;
}

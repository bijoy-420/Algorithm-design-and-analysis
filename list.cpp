#include <iostream>
using namespace std;

class Node {
public:
    int priority;
    string task;
    string hour;
    Node* next;

    Node(string task, int priority, string hour) {
        this->priority = priority;
        this->task = task;
        this->hour = hour;
        this->next = nullptr;
    }
    Node() {}
};

class LinkedList {
public:
    void insertHead(Node*& head, string task, int priority, string hour) {
        Node* n1 = new Node(task, priority, hour);
        n1->next = head;
        head = n1;
    }

    void traversing(Node*& head) {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->task << " " << temp->priority << " " << temp->hour;
            temp = temp->next;
            cout << "\n";
        }
    }

    void sorting(Node*& head) {
        Node* start = nullptr, * end = nullptr;

        for (start = head; start->next != nullptr; start = start->next) {
            for (end = start->next; end != nullptr; end = end->next) {
                if (start->priority < end->priority) {
                    swap(start->task, end->task);
                    swap(start->priority, end->priority);
                    swap(start->hour, end->hour);
                }
                cout<<" ";
            }
        }
    }

};

int main() {
    Node* head = nullptr; // Initialize the head
    LinkedList l1;

    l1.insertHead(head, "Task-01", 5, "1.00");
    l1.insertHead(head, "Task-02", 7, "2.00");
    l1.insertHead(head, "Task-03", 1, "1.00");
    l1.insertHead(head, "Task-05", 2, "5.00");
    l1.insertHead(head, "Task-04", 8, "3.00");

    cout << "Before Sorting:\n";
    l1.traversing(head);
    cout << "\n";

    cout << "After Sorting:\n";
    l1.sorting(head);

    l1.traversing(head);
    cout << "\n";

    return 0;
}

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

class SinglyCircularList {
    Node* head;
    Node* tail;

public:

    SinglyCircularList() {
        head = NULL;
        tail = NULL;
    }

    void insertAtHead(int val) {
        Node* newnode = new Node(val);

        if (tail == NULL) {
            head = tail = newnode;
            tail->next = head;
        }
        else {
            newnode->next = head;
            tail->next = newnode;
            head = newnode;
        }

        display();
    }

    void insertAtTail(int val) {
        Node* newnode = new Node(val);

        if (tail == NULL) {
            head = tail = newnode;
            tail->next = head;
        }
        else {
            newnode->next = head;
            tail->next = newnode;
            tail = newnode;
        }

        display();
    }

    void deleteValue(int val) {
        if (head == NULL) {
            cout << "List is empty!" << endl;
            return;
        }

        Node* temp = head;
        Node* prev = tail;

        do {
            if (temp->data == val) {

                if (head == tail) {
                    head = tail = NULL;
                }
                else {
                    prev->next = temp->next;

                    if (temp == head) {
                        head = temp->next;
                        tail->next = head;
                    }

                    if (temp == tail) {
                        tail = prev;
                    }
                }

                delete temp;
                display();
                return;
            }

            prev = temp;
            temp = temp->next;

        } while (temp != head);

        cout << "Value not found!" << endl;
    }

    void display() {
        if (head == NULL) {
            cout << "List is empty!" << endl;
            return;
        }

        Node* temp = head;

        cout << "LIST: ";

        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);

        cout << endl;
    }
};


class Node2 {
public:
    int data;
    Node2* next;
    Node2* prev;

    Node2(int val) {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

class list {
    Node2* head;
    Node2* tail;

public:

    list() {
        head = NULL;
        tail = NULL;
    }

    void insertAtHead(int val) {
        Node2* newnode = new Node2(val);

        if (tail == NULL) {
            head = tail = newnode;
            head->next = head;
            head->prev = head;
        }
        else {
            newnode->next = head;
            newnode->prev = tail;

            head->prev = newnode;
            tail->next = newnode;

            head = newnode;
        }

        display();
    }

    void insertAtTail(int val) {
        Node2* newnode = new Node2(val);

        if (tail == NULL) {
            head = tail = newnode;
            head->next = head;
            head->prev = head;
        }
        else {
            newnode->next = head;
            newnode->prev = tail;

            tail->next = newnode;
            head->prev = newnode;

            tail = newnode;
        }

        display();
    }

    void deleteValue(int val) {
        if (head == NULL) {
            cout << "List is empty!" << endl;
            return;
        }

        Node2* temp = head;

        do {
            if (temp->data == val) {

                if (head == tail) {
                    head = tail = NULL;
                }
                else {
                    temp->prev->next = temp->next;
                    temp->next->prev = temp->prev;

                    if (temp == head) {
                        head = temp->next;
                    }

                    if (temp == tail) {
                        tail = temp->prev;
                    }
                }

                delete temp;
                display();
                return;
            }

            temp = temp->next;

        } while (temp != head);

        cout << "Value not found!" << endl;
    }

    void display() {
        if (head == NULL) {
            cout << "List is empty!" << endl;
            return;
        }

        Node2* temp = head;

        cout << "LIST: ";

        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);

        cout << endl;
    }
};

int main() {

    cout << "Singly Circular Linked List" << endl;

    SinglyCircularList l1;

    l1.insertAtHead(10);
    l1.insertAtHead(20);
    l1.insertAtTail(30);
    l1.insertAtTail(40);

    l1.deleteValue(20);
    l1.deleteValue(40);


    cout << endl;

    cout << "Doubly Circular Linked List" << endl;

    list l2;

    l2.insertAtHead(10);
    l2.insertAtHead(20);
    l2.insertAtTail(30);
    l2.insertAtTail(40);

    l2.deleteValue(20);
    l2.deleteValue(40);

    return 0;
}
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

class list {
    Node* head;
    Node* tail;

    // Reverse printing using recursion
    void reverse(Node* temp) {
        if (temp == NULL) {
            return;
        }

        reverse(temp->next);
        cout << temp->data << " ";
    }

public:

    list() {
        head = NULL;
        tail = NULL;
    }

    // Insert at end
    void back(int val) {

        Node* newnode = new Node(val);

        if (head == NULL) {
            head = tail = newnode;
            return;
        }
        else {
            tail->next = newnode;
            tail = newnode;
        }

        display();
    }

    // Delete by value
    void deleteValue(int val) {

        if (head == NULL) {
            cout << "Queue is empty!\n";
            return;
        }

        // Delete first node
        if (head->data == val) {

            Node* temp = head;
            head = head->next;

            delete temp;

            // If list becomes empty
            if (head == NULL) {
                tail = NULL;
            }

            return;
        }

        Node* temp = head;

        // Find previous node
        while (temp->next != NULL &&
               temp->next->data != val) {

            temp = temp->next;
        }

        // Value not found
        if (temp->next == NULL) {
            cout << "Patient not found!\n";
            return;
        }

        Node* deletenode = temp->next;

        temp->next = deletenode->next;

        // If deleting last node
        if (deletenode == tail) {
            tail = temp;
        }

        delete deletenode;
    }

    // Forward traversal
    void display() {

        Node* temp = head;

        cout << "Front to Back: ";

        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
    }

    // Reverse printing
    void displayReverse() {

        cout << "Last to First: ";

        reverse(head);

        cout << endl;
    }
};

int main() {

    list l1;

    l1.back(101);
    l1.back(102);
    l1.back(103);
    l1.back(104);
    l1.back(105);

    cout << "\nOriginal queue:\n";
    l1.display();

    l1.deleteValue(103);

    cout << "\nAfter deletion:\n";
    l1.display();

    cout << "\nReverse printing:\n";
    l1.displayReverse();

    return 0;
}
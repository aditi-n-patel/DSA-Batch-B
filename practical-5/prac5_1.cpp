#include <iostream>
using namespace std;

class Node {
public:
    string song;
    Node* prev;
    Node* next;

    Node(string s) {
        song = s;
        next = NULL;
        prev = NULL;
    }
};

class playlist {
private:
    Node* head;
    Node* tail;

public:
    playlist() {
        head = NULL;
        tail = NULL;
    }

    void front(string song) {
        Node* newnode = new Node(song);

        if (head == NULL) {
            head = tail = newnode;
            display();
            return;
        }
        else {
            newnode->next = head;
            head->prev = newnode;
            head = newnode;
        }

        display();
    }

    void back(string song) {
        Node* newnode = new Node(song);

        if (head == NULL) {
            head = tail = newnode;
            display();
            return;
        }
        else {
            tail->next = newnode;
            newnode->prev = tail;
            tail = newnode;
        }

        display();
    }

    void insert(string target, string song) {
        Node* temp = head;

        while (temp != NULL && temp->song != target) {
            temp = temp->next;
        }

        if (temp == NULL) {
            cout << "Song not found!" << endl;
            return;
        }

        Node* newnode = new Node(song);

        newnode->next = temp->next;
        newnode->prev = temp;

        if (temp->next != NULL) {
            temp->next->prev = newnode;
        }
        else {
            tail = newnode;
        }

        temp->next = newnode;

        display();
    }

    void remove() {
        if (head == NULL) {
            cout << "Playlist is empty!" << endl;
            return;
        }

        Node* temp = head;
        head = head->next;

        if (head != NULL) {
            head->prev = NULL;
        }
        else {
            tail = NULL;
        }

        delete temp;
        display();
    }

    void counts() {
        Node* temp = head;
        int count = 0;

        while (temp != NULL) {
            count++;
            temp = temp->next;
        }

        cout << "Number of songs: " << count << endl;
        display();
    }

    void display() {
        Node* temp = head;

        cout << "Playlist: ";

        while (temp != NULL) {
            cout << temp->song << " ";
            temp = temp->next;
        }

        cout << endl;
    }
};

int main() {
    playlist p;

    p.front("Song1");
    p.back("Song2");
    p.back("Song3");
    p.insert("Song2", "SongX");
    p.remove();
    p.counts();

    return 0;
}
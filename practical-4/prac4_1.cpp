#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int val){
        data=val;
        next=NULL;
    }

};
class list{
    Node* head;
    Node* tail;
    public:
    list(){
        head=NULL;
        tail=NULL;

    }

    void front(int val){

        Node* newnode=new Node(val);

        if(head==NULL){
            head=tail=newnode;
            display();
            return;
        }
        else{
            newnode->next=head;
            head=newnode;

        }
        display();

    }

    void back(int val){
        Node* newnode=new Node(val);
         if(head==NULL){
            head=tail=newnode;
            display();
            return;
        }
        else{
            tail->next=newnode;
            tail=newnode;

        }
            display();
    }
    void insert(int val, int pos){
        if(pos<1){
            cout<<"invalid position! \n";
            return;

        }
        if(pos==1){
            front(val);
            return;
        }
        Node* temp=head;
        for(int i=1;i<pos-1;i++){
            if(temp==NULL){
                cout<<"Invalid pos! \n";
                return;
            }
            temp=temp->next;

        }
        Node* newnode=new Node(val);
        newnode ->next=temp ->next;
        temp->next=newnode;

          if (newnode->next == nullptr) {
            tail = newnode;
        }

        display();
    }
    void display(){
        Node* temp=head;
cout<<"LIST:\n";
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
};

int main(){
    list l1;
    l1.front(5);
    l1.front(4);
    l1.back(6);
    l1.back(7);
    l1.insert(3,1);

    return 0;
}
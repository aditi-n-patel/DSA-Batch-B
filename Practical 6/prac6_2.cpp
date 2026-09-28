#include<iostream>
using namespace std;


class Node{
    public:
    Node *next;
    string p;

    Node(string page){
        p=page;
        next=NULL;

    }
};

class stack{
public:
Node *top;

stack(){
    top=NULL;
}
 bool IsEmpty(){
    return top==NULL;

 }

 void push( string p){
    Node *newnode=new Node(p);
    if(IsEmpty()){
        top=newnode;
        return;
        
    }
    newnode->next=top;
    top=newnode;
    
}

void pop(){
    if(IsEmpty()){
        cout<<"Stack is empty!\n";
        return;
    }
    Node *temp=top;
    top= top ->next;
    delete temp;
    
}
 string peek() {
        if (IsEmpty()) {
            return "No Page";
        }

        return top->p;
    }

};

int main() {
    stack history;

    int n;
    cout<<"Enter no of opeations:";
    cin >> n;

    string operation;
    string p;
cout<<"Enter  operations:";
    for (int i = 0; i < n; i++) {
        cin >> operation;

        if (operation == "VISIT") {
            cin >> p;
             
            history.push(p);
            cout<<"Top of the stack is:" <<history.peek()<<endl;
        }
        else if (operation == "BACK") {
            history.pop();
        }

        cout<<" After pop top of stack is:" << history.peek() << endl;
    }

    return 0;
}

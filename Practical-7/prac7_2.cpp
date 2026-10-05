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

class queue{
  public:

  Node* front;

Node * rear;

queue(){
    front=rear=NULL;
}

bool isEmpty(){
    return front==NULL;
}

void arrive(int val){
 Node* newnode=new Node(val); 

 if(isEmpty()){

    front=rear=newnode;
 }

 else{
 rear->next=newnode;
 rear=newnode;
 }

 cout<<"\n New patient added :"<<val<<"  First patient is:"<<front->data<<endl;

}

void attempt(){

     int val=front->data;

    if(isEmpty()){
        cout<<"No patient remain!! \n";
        return;
    }

    else{
        Node *temp=front;

       

        front=front->next;

        delete temp;
    }

    if(front==NULL){
        rear=NULL;

        cout << "\nAfter attend patient " << val << ", no patient remains.";
    }
    else{

   cout << "\nAfter attnd patient " << val
                 << ", next patient is: " << front->data;
    }
}




};

int main(){
       queue q;

       q.arrive(2);
       q.arrive(3);
       q.arrive(4);
       q.arrive(5);
       q.attempt();
       q.attempt();


}
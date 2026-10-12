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

int main(){


    Node* self[10];
    for(int i=0;i<10;i++){
        self[i]=NULL;
    }

    int n;
    cout<<"\n Enter no of books:";
    cin>>n;

    cout<<"\n Enter book codes:\n";
    for(int i=0;i<n;i++){
    
        int code;
       cin>>code;

   int index= code % 10;
   Node* newnode=new Node(code);

   if(self[index]==NULL){
    self[index]=newnode;
   }
   else{
     Node * temp=self[index];
       
     while(temp->next !=NULL){
        temp=temp->next;

     }

     temp->next=newnode;
 }

}
cout<<"\nFinal shelves:\n";

for(int i=0;i<10;i++){

    cout<<i<<" : ";

    Node* temp=self[i];

    while(temp!=NULL)
{

    cout<<temp->data<< " ";
    temp=temp->next;
}
cout<<endl;

}



}
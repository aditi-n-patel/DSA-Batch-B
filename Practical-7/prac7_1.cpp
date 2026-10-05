#include<iostream>
using namespace std;

class queue{
public:

int *arr;
int n;

int front,rear;

queue(int size){
   

    front=rear=-1;

    n=size;

     arr=new int[n];
}
bool isEmpty(){
    return front==-1;
}

bool isFull(){

    return rear== n-1;
}

void  join(int x){
  

if(isFull()){
    cout<<"Queue is full!! \n";
    return;
}

 if( isEmpty()){
    
        front =rear=0;
        arr[0]=x;
}
else{
rear++;
arr[rear]=x;
}


cout << "Added token: " << x << endl;

}


void serve(){
    if(isEmpty()){
        cout<<"Queue is empty!! \n";
        return;
    }

    if(front==rear){
        front=rear=-1;
    }

    else{
    front++;
    }
cout<<"\n After serve:\n";

    display();


}
int display(){
     if(isEmpty()){
        cout<<"Queue is empty!! \n";
        return 0;
    }

    cout<<" \n Front token is:"<<arr[front]<<endl;

    
}


};

int main(){

    queue q(3);

    q.join(2);
    q.join(3);
    q.join(4);
    q.serve();
    q.join(5);
}
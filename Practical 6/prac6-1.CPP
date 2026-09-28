#include <iostream>
using namespace std;
class stack{
  int *arr;
  int size;
  int top;

  public:

  stack(int n){
    size=n;
    arr=new int[n];
    top=-1;
  }


  bool IsFull(){
    return top==size-1;
  }
 bool IsEmpty(){
    return top==-1;
  }

  void push(int tray){
    if(IsFull()){
        cout<<"Stack is full \n ";
        return;

    }
    
        top++;
        arr[top]=tray;
        cout<<"Pushesd tray  top is :"<<arr[top];
    
  }

  void pop (){
if(IsEmpty()){
    cout<<"Stack is empty \n";
    return;
}

top--;
if(top==-1){
    cout<<"Now stack is empty!!";
   }
   else{
    cout<<"Tray poped now top tray is:"<<arr[top];
   }
}
};

int main(){

    int size;
    cout<<"Enter size of stack:";
    cin>>size;

    stack s(size);
    
    int m;
    cout<<"Enter number of operations you want to perform:";
    cin>>m;

    for(int i=0;i<m;i++){
        char operation;
        cout<<"Enter operation: 'p' for push tray and 'r' for remove tray:";
        cin>>operation;
        if(operation=='p'){
            int tray;
            cout<<"Enter tray:";
            cin>>tray;
            s.push(tray);

        }
        else if(operation=='r'){
            s.pop();
        }
        else{
            cout<<"Enter valid operation \n";
        }
    }
return 0;

}
#include<iostream>
#include<stack>
using namespace std;

int priority(int op){

    if(op=='+'|| op=='-')
    return 1;

     if(op=='*'|| op=='/')
     return 2;

     if(op=='^')
     return 3;

     return 0;

}

string infixToPost(string exp){
  stack<char>s;

  string result="";

  for(int i=0;i<exp.length();i++){
    char ch=exp[i];

    if(isalnum(ch)){
            result+=ch;
        }

        else if(ch=='('){
           s.push(ch);
        }

        else if(ch==')'){
            while(!s.empty()&& s.top() !='('){
                result+=s.top();
                s.pop();
            }
                 if(!s.empty()){
                    s.pop();
                 }
            }

            else{
            while(!s.empty() && s.top()!='(' &&
                  priority(s.top())>=priority(ch)){
                result+=s.top();
                s.pop();
            }

            s.push(ch);
        }
    }

    while(!s.empty()){
        result+=s.top();
        s.pop();
    }

    return result;

  }
int main(){
    string exp;

    cout<<"Enter infix expression: ";
    cin>>exp;

    cout<<"Postfix expression: "<<infixToPost(exp)<<endl;

    return 0;
}
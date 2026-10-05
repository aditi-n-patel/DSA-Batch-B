#include<iostream>
using namespace std;
class Node{
public:

int data;
Node *left;
Node* right;

Node(int val){
    data=val;
    left=right=NULL;

}
};

class tree{
    public:

    Node * insert(Node*root,int val){
        if(!root)
       return new Node(val);

        if(val < root->data)
        root->left=insert(root->left,val);

        if(val > root->data){
            root->right=insert(root->right,val);
        }

        return root;
    }

    void inorder(Node *root){
 if(!root)
        return;

        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);

}

};
int main(){

Node *root=NULL;
tree t;

root=t.insert( root,20 );

root=t.insert( root, 30);
root=t.insert( root,40 );
root=t.insert( root,50 );
root=t.insert( root, 60);

cout<<"INORDER:\n";
    t.inorder(root);
    cout<<endl;


}


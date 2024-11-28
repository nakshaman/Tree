#include <iostream>
using namespace std;
class Node{
    public:
    int data;
    Node * left;
    Node * right;
    Node(int data){
        this->data=data;
        left=NULL;
        right=NULL;
    }
    Node(int data,Node * left,Node * right){
        this->data=data;
        this->left=left;
        this->right=right;
    }
};
void preorder(Node * root){
    if(root==NULL){
        return ;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
void inorder(Node * root){
    if(root==NULL){
        return ;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void postorder(Node * root){
    if(root==NULL){
        return ;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}
int main (){

    Node * root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    root->left->right->left=new Node(6);

    root->right->left=new Node (7);
    root->right->right=new Node(8);

    root->right->right->left=new Node(9);
    root->right->right->right=new Node(10);

    // preorder(root);
    // inorder(root);
    postorder(root);
     
    return 0;
}
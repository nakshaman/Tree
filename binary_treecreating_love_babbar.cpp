#include <iostream>
#include <queue>
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
};
Node * buildTree(Node * root){
    int data;
    cout<<"Enter the data"<<endl;
    cin>>data;
    root=new Node(data);
    if(data==-1){
        return NULL;
    }
    cout<<"Enter data for inserting in left of "<<data<<endl;
    root->left=buildTree(root->left);
    cout<<"Enter the data for inserting in right of "<<data<<endl;
    root->right=buildTree(root->right);
    return root;
}

void preorder(Node * root){
    if(root==NULL){
        return ;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
void levelOrder(Node * root){
    queue<Node *> q;
    q.push(root);
    while(!q.empty()){
        Node * temp=q.front();
        cout<<temp->data<<" ";
        q.pop();
        if(temp->left){
            q.push(temp->left);
        }
        if(temp->right){
            q.push(temp->right);
        }
    }
}
int main (){
    Node * root=NULL;
    root=buildTree(root);
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1 
    // preorder(root);
    levelOrder(root);
    return 0;
}
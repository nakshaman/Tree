#include <iostream>
using namespace std;
class Node{
    public:
    int data;
    Node *next;
    Node * prev;
    Node(int data){
        this->data=data;
        next=NULL;
        prev=NULL;
    }
};
Node * createDL(int arr[],int n){
    Node * head=new Node (arr[0]);
    Node * temp=head;
    for(int i=1;i<n;i++){
        Node * newNode=new Node (arr[i]);
        newNode->prev=head;
        temp->next=newNode;
        temp=newNode;
    }
    return head;
}
void display(Node * head){
    Node * temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
int main (){
    int n=8;
    int arr[]={1,2,3,4,5,6,7,8};
    Node * head=createDL(arr,n);
    display(head);
    return 0;
}
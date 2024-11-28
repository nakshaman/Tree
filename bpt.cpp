#include <iostream>
using namespace std;
class Node{
    public:
    int data;
    Node * next;
    Node(int x){
        data=x;
        next=NULL;
    }
};

Node * convert (int arr[],int n){
    Node * head=new Node(arr[0]);
    Node * temp=head;
    for(int i=1;i<n;i++){
        Node * newNode=new Node(arr[i]);
        temp->next=newNode;
        temp=newNode;
    }
    return head;
}
void traverse (Node *head){
    Node * temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
void search(Node * head,int x){
    Node *temp=head;
    while(temp!=NULL){
        if(temp->data==x){
            cout<<"Found"<<endl;
            return ;
        }
        temp=temp->next;
    }
    cout<<"Not found "<<endl;
}

Node * deleteHead(Node * head){
    Node *temp=head;
    temp=temp->next;
    delete head;
    return temp;
}

Node * deleteLast(Node * head){
    Node * temp=head;
    while(temp->next->next!=NULL){
        temp=temp->next;
    }
    delete temp->next;
    temp->next=NULL;
    return head;
}


Node * deleteIndex(Node * head,int k){
    if(k==1){
        return deleteHead(head);
    }
    if(head==NULL){
        return NULL;
    }
    Node * temp=head;
    int count=0;
    while(temp!=NULL){
        count++;
        if(count==k-1){
            Node * front =temp->next->next;
            delete temp->next;
            temp->next=front;
        }
        temp=temp->next;
    }
    return head;
}
Node * insertHead(Node * head,int x){
    Node * temp=new Node(x);
    temp->next=head;
    return temp;
}
Node *insertLast(Node * head,int x){
    Node *temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    Node* newNode=new Node(x);
    temp->next=newNode;
    return head;
}
Node *insertIndex(Node* head,int x,int k){
    if(k==1){
        return insertHead(head,x);
    }
    if(head==NULL){
        return new Node(x);
    }
    Node * temp=head;
    int count=0;
    while(temp!=NULL){
        count++;
        if(count==k-1){
            Node * front=temp->next;
            Node * newNode=new Node (x);
            temp->next=newNode;
            newNode->next=front;
        }
        temp=temp->next;
    }
    return head;
}
int main (){
    int n=8;
    int arr[]={1,2,3,4,5,6,7,8};
    Node *head=convert(arr,n);
    traverse(head);
    search(head,10);
    // head=deleteHead(head);
    // traverse(head);
    // head=deleteLast(head);
    // traverse(head);
    // head=deleteIndex(head,8);
    // traverse(head);
    // head=insertHead(head,100);
    // traverse(head);
    // head=insertLast(head,100);
    // traverse(head);
    head=insertIndex(head,100,5);
    traverse(head);
    return 0;
}















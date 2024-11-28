#include <iostream>
#include <vector>

using namespace std;

class Node {
    public:
    int data;
    Node * next;
    Node * prev;
    Node (int data){
        this->data=data;
        next=NULL;
        prev=NULL;
    }
    Node(int data,Node * next,Node * left){
        this->data=data;
        this->next=next;
        this->prev=prev;
    }
};

Node * create(vector <int> arr){
    Node * head=new Node(arr[0]);
    Node * temp=head;
    for(int i=1;i<arr.size();i++){
        Node * newNode=new Node(arr[i]);
        newNode->prev=temp;
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
    cout<<endl;
}

Node * insertHead(Node * head,int x){
    Node *newNode=new Node(x);
    newNode->next=head;
    head->prev=newNode;
    return newNode;
}

Node * insertatlast(Node * head,int x){
    Node * temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    Node * newNode=new Node(x);
    temp->next=newNode;
    newNode->prev=temp;
    return head;
}

Node *insertAtposition(Node * head,int k,int x){
    if(k==1){
        return insertHead(head,x);
    }
    if(head==NULL){
        return new Node(x);
    }
    int count=0;
    Node * temp=head;
    while(temp!=NULL){
        count++;
        if(count==k-1){
            Node * newNode=new Node(x);
            Node * front=temp->next;
            temp->next=newNode;
            newNode->prev=temp;
            newNode->next=front;
            front->prev=newNode;
        }
        temp=temp->next;
    }
    return head;
}

Node * deleteHead(Node * head){
    Node * temp=head;
    head=head->next;
    head->prev=NULL;
    delete temp;
    return head;
}
// sanju->naksh=lbuggie


int main (){
    vector<int> arr={1,2,3,4,5,6,7,8,9,10};
    Node * head=create(arr);
    display(head);
    // head=insertHead(head,100);
    // display(head);
    // head=deleteHead(head);
    // display(head);
    // head=insertatlast(head,100);
    // display(head);
    head=insertAtposition(head,10,999);
    display(head);
    return 0;
}
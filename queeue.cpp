#include <iostream>
using namespace std;
class Queue{
    public:
    int size;
    int *arr;
    int front;
    int rear;
    Queue(int size){
        this->size=size;
        front=0;
        rear=0;
        arr=new int[size];
    }
    void push(int x){
        if(size>rear){
            arr[rear]=x;
            rear++;
        }
        else{
            cout<<"Queue overflow"<<endl;
        }
    }
    void pop(){
        if(front==rear){
            cout<<"Queue is empty"<<endl;
        }
        else{
            arr[front]=-1;
            front++;
            if(rear==front){
                rear=0;
                front=0;
            }
        }
    }
    void empty(){
        if(rear==front){
            cout<<"Queue is empty"<<endl;
        }
        else{
            cout<<"Queue is not empty"<<endl;
        }
    }
    void peek(){
        if(rear==front){
            cout<<"Queue is empty"<<endl;
        }
        else{
            cout<<arr[front]<<endl;
        }
    }
};
int main (){
    Queue q(10);
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);
    q.push(7);
    // q.push(8);
    q.peek();
    return 0;
}
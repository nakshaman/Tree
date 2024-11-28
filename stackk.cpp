#include <iostream>
using namespace std;
class Stack{
    public:
    int top;
    int size;
    char * arr;
    Stack(int size){
        top=-1;
        this->size=size;
        arr=new char(size);
    }
    void push(char x){
        if(size-top>1){
            arr[++top]=x;
        }
        else{
            cout<<"Stack overflow"<<endl;
        }
    }
    void pop(){
        if(top>=0){
            arr[top]=-1;
            top--;
        }
        else{
            cout<<"Stack underflow"<<endl;
        }
    }
    void peek(){
        if(top>=0){
            cout<<arr[top]<<endl;
        }
        else{
            cout<<"Stack is empty"<<endl;
        }
    }
    void isempty(){
        if(top>=0){
            cout<<"Stack is not empty"<<endl;
        }
        else{
            cout<<"Stack is empty"<<endl;
        }
    }
};
int main (){
    Stack s(7);
    s.push('+');
    s.push('-');
    s.push('/');
    s.peek();
    s.pop();
    s.peek();
    return 0;
}
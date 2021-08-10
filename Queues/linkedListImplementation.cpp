#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;

    node(int val){
        data = val;
        next = NULL;
    }
};

class queue{
    node* front;
    node* rear;

    public:
    queue(){
        front = NULL;
        rear = NULL;
    }
    void enqueue(int x){
        node* n = new node(x);
        if(front == NULL){
            rear = n;
            front = n;
            return ;
        }
        rear->next = n;
        rear = n;
        return;
    }
    void dequeue(){
        if(front == NULL){
            cout << "Queue underflow" << endl;
            return;
        }
        node* todelete = front;
        front = front->next;
        delete todelete;
        return;
    }
    int peek(){
        if(front ==  NULL){
            cout << "Queue is empty" << endl;
            return -1;
        }
        else{
            return front->data;
        }
    }
    bool isEmpty(){
        if(front==NULL){
            return true;
        }
        else{
            return false;
        }
    }
};

int main(){
    queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);

    cout  << q.peek() << endl;
    q.dequeue();
    cout  << q.peek() << endl;
    q.dequeue();
    cout  << q.peek() << endl;
    q.dequeue();
    cout  << q.peek() << endl;
    q.dequeue();
    cout  << q.peek() << endl;
    q.dequeue();
    cout  << q.peek() << endl;
    q.dequeue();
    cout << q.isEmpty() << endl;
    return 0;

}
#include<iostream>
using namespace std;
#define n 20

class queue{
    int* arr;
    int front;
    int rear;
    
    public:
    
    queue(){
        arr = new int[n];
        front = -1;
        rear = -1;
    }
    
    bool isfull(){
        if(rear == n-1){
            return true;
        }else{
            return false;
        }
    }
    bool isempty(){
        if(rear == front){
            return true;
        }
        else{
            return false;
        }
    }
    void enqueue(int val){
        if(!isfull()){
            rear = rear+1;
            arr[rear] = val;
        }else{
            cout << "queue is full element can not added" << endl;
        }
    }

    void delQue(){
        if(isempty()){
            cout << "Queue is empty" << endl;
            return;
        }else{
            front = front+1;
            return;
        }
    }
    int peek(){
        if(!isempty()){
            return arr[front+1];
        }else{
            cout << "queue is empty" << endl;
            return -1;
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
    q.delQue();
    q.delQue();
    q.delQue();
    q.delQue();
    q.delQue();
    cout << q.isempty()<<endl;
    q.enqueue(40);
    q.enqueue(50);
    cout << q.peek() << endl;
}
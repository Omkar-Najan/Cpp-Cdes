#include<iostream>
#include<stack>
using namespace std;
// dequeue operation is costly
class queueDequeue{
    stack<int> s1;
    stack<int> s2;

    public:
    void enQueue(int val){
        s1.push(val);
    }

    int deQueue(){
        if(s1.empty() && s2.empty()){
            cout << "Queue is empty"<< endl;
            return -1;
        }
        else{
            if(s2.empty()){
                while (!s1.empty())
                {
                    s2.push(s1.top());
                    s1.pop();
                }
            }
            int topval = s2.top();
            s2.pop();
            return topval;
        }
    }
    bool empty(){
        if(s1.empty() && s2.empty()){
            return true;
        }
        return false;
    }

};

// using functioncall stack
class queueFunctionCall{
    stack<int> s1;

    public:
    void enQueue(int val){
        s1.push(val);
    }

    int deQueue(){
        if(s1.empty()){
            cout << "Queue is empty"<< endl;
            return -1;
        }
        else{
            int x = s1.top();
            s1.pop();
            if(s1.empty()){
                return x;
            }
            int item = deQueue();
            s1.push(x);
            return item;
        }
    }

    bool empty(){
        if(s1.empty()){
            return true;
        }
        return false;
    }

};



int main(){
queueFunctionCall q;
    q.enQueue(1);
    q.enQueue(2);
    q.enQueue(3);
    q.enQueue(4);
    q.enQueue(5);
    q.enQueue(6);
    q.enQueue(7);
    cout << q.deQueue() <<endl;
    cout << q.deQueue() <<endl;
    cout << q.deQueue() <<endl;
    cout << q.deQueue() <<endl;
    cout << q.deQueue() <<endl;
    cout << q.deQueue() <<endl;
    cout << q.deQueue() <<endl;
    cout << q.deQueue() <<endl;
    cout << q.deQueue() <<endl;
    cout << q.deQueue() <<endl;
    return 0;
}
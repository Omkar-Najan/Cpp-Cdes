#include<iostream>
using namespace std;
#define n 100

class stack{
    int* arr;
    int top;
    
    public:
    
    stack(){
        arr = new int[n];
        top = -1;
    }
    
    void push(int x){
        if(top == n-1){
            cout << "Stack Overflow" << endl;
            return;
        }
        top++;
        arr[top] = x;
        return;
    }
    
    bool empty(){
        return top == -1;
    }
    
    void pop(){
        if(empty()){
            cout << "Stack is empty";
            return;
        }
        top--;
        return;
    }

    int Top(){
        if(empty()){
            cout << "No element in stack";
            return -1;
        }
        return arr[top];
    }
};

int main(){
    stack st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    cout << st.Top() << endl;
    st.pop();
    st.pop();
    cout << st.Top() << endl;
    
    return 0;
}
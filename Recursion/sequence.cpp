#include<iostream>
using namespace std;

void dec(int n){
    if(n==1){
        cout << "1" << endl;
        return;
    }
    cout << n << " ";
    dec(n-1);
}

void incr(int n){
    if(n ==1){ 
        cout << "1" << " ";
        return ;
    }
    incr(n-1);
    cout << n << " ";
}

int main(){
    int n;
    cin>>n;
    incr(n);
    cout << endl;
    dec(n);
    return 0;
}
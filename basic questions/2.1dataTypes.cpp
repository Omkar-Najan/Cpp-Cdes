#include<iostream>
using namespace std;

int main(){
    int a = 12;
    cout << "size of int " << sizeof(a) << endl;

    float b;
    cout << "size of float " << sizeof(b) << endl;

    char c = 'a';
    cout << "size of char " << sizeof(c) << endl;

    bool d;
    cout<< "size of bool " << sizeof(d) << endl;

    short int as = 12;
    cout << "size of short int " << sizeof(as) << endl;

    long int al = 12;
    cout << "size of long int " << sizeof(al) << endl;
    return 0;
}
#include<iostream>
#include<algorithm>
using namespace std;

int getBit(int n,int pos){
    return(n &  (1<<pos) != 0);   // << -> left shift of 1 2 times.
}


int setBit(int n,int pos){
    return(n| (1<< pos));
}

int clearBit(int n,int pos){
    return(n & (~(1<<pos)));
}
int updateBit(int n,int pos,int bit){
    int mask = ~(1<<pos);
    n = n & mask;
    return (n | (bit << pos));
}

int toggleBit(int n,int pos){
    return (n xor (1<<pos));
}

int main(){
    //  to get bit
    // Get bit in specific position
    cout << getBit(5,2) << endl;

    // set bit
    // n = 0101 set 1 at pos 1
    //  1<< i = 0010
    // 0101 | 0010 = 0111
    cout << setBit(5,1) << endl;

    // Clear Bit
    // n = 0101 , clear bit at pos 2.
    // 1<<pos; and ~0100 = 1011;
    // 0101 & 1011 = 0001
    cout << clearBit(5,2) << endl;

    // update ith bit
    // n = 0101 , update bit of i = 1 th pos to 1
    // clear bit and then set bit.
    cout << updateBit(5,1,1)<< endl;

    // toggle ith bit
    //  toggle bit at pos
    cout << toggleBit(5,1) << endl;
    return 0;
}
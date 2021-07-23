/*
PS : Check if number is power of 2
Approach : 2^n Numbers have only 1 set bit
so  n     =   00100
    n-1   = 00011
n &(n-1)  = 00000
!(n & (n-1)) = 00001
*/

bool isPowerOf2(int n){
    return(n && !(n & n-1));
}

#include<iostream>
using namespace std;

int main(){
    cout << isPowerOf2(4)<< endl;
    cout << isPowerOf2(7)<< endl;
    return 0;
}
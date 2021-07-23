#include<iostream>
using namespace std;
/*
n & (n - 1) sets the first set-bit to zero.
Explanation: n = XXX100
n - 1 = XXX011
n & ( n - 1 ) = XXX000
*/
int numberOfones(int n){
    int count = 0;
    while(n){
        n = n & (n-1);
        count++;
    }
    return count;
}
int main(){
    cout  << numberOfones(15) << endl;
    return 0;
}
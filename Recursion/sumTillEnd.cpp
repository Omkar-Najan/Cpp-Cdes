#include<iostream>
using namespace std;
/*
Get sum of First n numbers
*/

int sum(int n){
    if(n == 0){
        return 0;
    }else{
        int result = sum(n-1);
        return n + result;
    }
}
int main(){
    int n ;
    cin >> n;
    cout << sum(n) << endl;
    return 0;
}
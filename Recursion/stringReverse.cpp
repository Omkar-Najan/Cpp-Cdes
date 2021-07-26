#include<iostream>
#include<string>
using namespace std;

char reverse(string s , int n){
    if(n == 1){
    return s[0];
}
    cout << s[n-1];
    return reverse(s,n-1);
}

void rev(string s){

    if(s.length() ==0){
        return;
    }
    string ros = s.substr(1);
    rev(ros);
    cout << s[0];
}
int main(){
    string s = "Omkar";
    int n = s.size();
    rev(s);
}